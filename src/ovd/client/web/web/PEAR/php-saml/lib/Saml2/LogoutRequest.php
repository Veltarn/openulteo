<?php

/**
 * SAML 2 Logout Request
 *
 */
class OneLogin_Saml2_LogoutRequest
{
    /**
     * Object that represents the setting info
     * @var OneLogin_Saml2_Settings
     */
    protected $_settings;

    /**
     * SAML Logout Request
     * @var string
     */
    private $_logoutRequest;

    /**
     * Constructs the Logout Request object.
     *
     * @param OneLogin_Saml2_Settings $settings Settings
     */
    public function __construct(OneLogin_Saml2_Settings $settings)
    {
        $this->_settings = $settings;

        $spData = $this->_settings->getSPData();
        $idpData = $this->_settings->getIdPData();
        $security = $this->_settings->getSecurityData();

        $id = OneLogin_Saml2_Utils::generateUniqueID();
        $nameIdValue = OneLogin_Saml2_Utils::generateUniqueID();
        $issueInstant = OneLogin_Saml2_Utils::parseTime2SAML(time());
        
        $key = null;
        if (isset($security['nameIdEncrypted']) && $security['nameIdEncrypted']) {
            $key = $idpData['x509cert'];
        }

        $nameId = OneLogin_Saml2_Utils::generateNameId(
            $nameIdValue,
            $spData['entityId'],
            $spData['NameIDFormat'],
            $key
        );

        $logoutRequest = <<<LOGOUTREQUEST
<samlp:LogoutRequest
    xmlns:samlp="urn:oasis:names:tc:SAML:2.0:protocol"
    xmlns:saml="urn:oasis:names:tc:SAML:2.0:assertion"
    ID="{$id}"
    Version="2.0"
    IssueInstant="{$issueInstant}"
    Destination="{$idpData['singleLogoutService']['url']}">
    <saml:Issuer>{$spData['entityId']}</saml:Issuer>
    {$nameId}
</samlp:LogoutRequest>
LOGOUTREQUEST;

        $this->_logoutRequest = $logoutRequest;
    }


    /**
     * Returns the Logout Request defated, base64encoded, unsigned
     *
     * @return string Deflated base64 encoded Logout Request
     */
    public function getRequest()
    {
        $deflatedRequest = gzdeflate($this->_logoutRequest);
        return base64_encode($deflatedRequest);
    }

    /**
     * Returns the ID of the Logout Request.
     *
     * @param string|DOMDocument $request Logout Request Message
     *
     * @return string ID
     */
    public static function getID($request)
    {
        if ($request instanceof DOMDocument) {
            $dom = $request;
        } else {
            $dom = new DOMDocument();
            $dom = OneLogin_Saml2_Utils::loadXML($dom, $request);
        }

        $id = $dom->documentElement->getAttribute('ID');
        return $id;
    }

    /**
     * Gets the NameID Data of the the Logout Request.
     *
     * @param string|DOMDocument $request Logout Request Message
     * @param string             $key     The SP key
     *     
     * @return array Name ID Data (Value, Format, NameQualifier, SPNameQualifier)
     */
    public static function getNameIdData($request, $key = null)
    {
        if ($request instanceof DOMDocument) {
            $dom = $request;
        } else {
            $dom = new DOMDocument();
            $dom = OneLogin_Saml2_Utils::loadXML($dom, $request);
        }

        $encryptedEntries = OneLogin_Saml2_Utils::query($dom, '/samlp:LogoutRequest/saml:EncryptedID');

        if ($encryptedEntries->length == 1) {
            $encryptedDataNodes = $encryptedEntries->item(0)->getElementsByTagName('EncryptedData');
            $encryptedData = $encryptedDataNodes->item(0);

            if (empty($key)) {
                throw new Exception("Key is required in order to decrypt the NameID");
            }

            $seckey = new XMLSecurityKey(XMLSecurityKey::RSA_1_5, array('type'=>'private'));
            $seckey->loadKey($key);

            $nameId = OneLogin_Saml2_Utils::decryptElement($encryptedData, $seckey);

        } else {
            $entries = OneLogin_Saml2_Utils::query($dom, '/samlp:LogoutRequest/saml:NameID');
            if ($entries->length == 1) {
                $nameId = $entries->item(0);
            }
        }

        if (!isset($nameId)) {
            throw new Exception("Not NameID found in the Logout Request");
        }

        $nameIdData = array();
        $nameIdData['Value'] = $nameId->nodeValue;
        foreach (array('Format', 'SPNameQualifier', 'NameQualifier') as $attr) {
            if ($nameId->hasAttribute($attr)) {
                $nameIdData[$attr] = $nameId->getAttribute($attr);
            }
        }

        return $nameIdData;
    }

    /**
     * Gets the NameID of the Logout Request.
     *
     * @param string|DOMDocument $request Logout Request Message
     * @param string             $key     The SP key     
     *
     * @return string Name ID Value
     */
    public static function getNameId($request, $key = null)
    {
        $nameId = self::getNameIdData($request, $key);
        return $nameId['Value'];
    }

    /**
     * Gets the Issuer of the Logout Request.
     *
     * @param string|DOMDocument $request Logout Request Message
     *
     * @return string|null $issuer The Issuer
     */
    public static function getIssuer($request)
    {
        if ($request instanceof DOMDocument) {
            $dom = $request;
        } else {
            $dom = new DOMDocument();
            $dom = OneLogin_Saml2_Utils::loadXML($dom, $request);
        }

        $issuer = null;
        $issuerNodes = OneLogin_Saml2_Utils::query($dom, '/samlp:LogoutRequest/saml:Issuer');
        if ($issuerNodes->length == 1) {
            $issuer = $issuerNodes->item(0)->textContent;
        }
        return $issuer;
    }

    /**
     * Gets the SessionIndexes from the Logout Request.
     *
     * @param string|DOMDocument $request Logout Request Message
     * 
     * @return array The SessionIndex value
     */
    public static function getSessionIndexes($request)
    {
        if ($request instanceof DOMDocument) {
            $dom = $request;
        } else {
            $dom = new DOMDocument();
            $dom = OneLogin_Saml2_Utils::loadXML($dom, $request);
        }

        $sessionIndexes = array();
        $sessionIndexNodes = OneLogin_Saml2_Utils::query($dom, '/samlp:LogoutRequest/samlp:SessionIndex');
        foreach ($sessionIndexNodes as $sessionIndexNode) {
            $sessionIndexes[] = $sessionIndexNode->textContent;
        }
        return $sessionIndexes;
    }

    /**
     * Checks if the Logout Request recieved is valid.
     *
     * @param OneLogin_Saml2_Settings $settings Settings
     * @param string|DOMDocument      $request  Logout Request decoded
     *
     * @return boolean If the Logout Request is or not valid
     */
    public static function isValid(OneLogin_Saml2_Settings $settings, $request, $debug = false)
    {
        try {
            if ($request instanceof DOMDocument) {
                $dom = $request;
            } else {
                $dom = new DOMDocument();
                $dom = OneLogin_Saml2_Utils::loadXML($dom, $request);
            }

            $idpData = $settings->getIdPData();
            $idPEntityId = $idpData['entityId'];

            if ($settings->isStrict()) {

                $res = OneLogin_Saml2_Utils::validateXML($dom, 'saml-schema-protocol-2.0.xsd', $debug);
                if (!$res instanceof DOMDocument) {
                    throw new Exception("Invalid SAML Logout Request. Not match the saml-schema-protocol-2.0.xsd");
                }

                $security = $settings->getSecurityData();

                $currentURL = OneLogin_Saml2_Utils::getSelfURLNoQuery();

                // Check NotOnOrAfter
                if ($dom->documentElement->hasAttribute('NotOnOrAfter')) {
                    $na = OneLogin_Saml2_Utils::parseSAML2Time($dom->documentElement->getAttribute('NotOnOrAfter'));
                    if ($na <= time()) {
                        throw new Exception('Timing issues (please check your clock settings)');
                    }
                }

                // Check destination
                if ($dom->documentElement->hasAttribute('Destination')) {
                    $destination = $dom->documentElement->getAttribute('Destination');
                    if (!empty($destination)) {
                        if (strpos($destination, $currentURL) === false) {
                            throw new Exception("The LogoutRequest was received at $currentURL instead of $destination");
                        }
                    }
                }

                $nameId = self::getNameId($dom);

                // Check issuer
                $issuer = self::getIssuer($dom);
                if (empty($issuer) || $issuer != $idPEntityId) {
                    throw new Exception("Invalid issuer in the Logout Request");
                }

                if ($security['wantMessagesSigned']) {
                    if (!isset($_GET['Signature'])) {
                        throw new Exception("The Message of the Logout Request is not signed and the SP require it");
                    }
                }
            }

            if (isset($_GET['Signature'])) {

                if (!isset($_GET['SigAlg'])) {
                    $signAlg = XMLSecurityKey::RSA_SHA1;
                } else {
                    $signAlg = $_GET['SigAlg'];
                }

                if ($signAlg != XMLSecurityKey::RSA_SHA1) {
                    throw new Exception('Invalid signAlg in the recieved Logout Request');
                }

                $signedQuery = 'SAMLRequest='.urlencode($_GET['SAMLRequest']);
                if (isset($_GET['RelayState'])) {
                    $signedQuery .= '&RelayState='.urlencode($_GET['RelayState']);
                }
                $signedQuery .= '&SigAlg='.urlencode($signAlg);

                if (!isset($idpData['x509cert']) || empty($idpData['x509cert'])) {
                    throw new Exception('In order to validate the sign on the Logout Request, the x509cert of the IdP is required');
                }
                $cert = $idpData['x509cert'];

                $objKey = new XMLSecurityKey(XMLSecurityKey::RSA_SHA1, array('type' => 'public'));
                $objKey->loadKey($cert, false, true);

                if (!$objKey->verifySignature($signedQuery, base64_decode($_GET['Signature']))) {
                    throw new Exception('Signature validation failed. Logout Request rejected');
                }
            }

            return true;
        } catch (Exception $e) {
            $debug = $settings->isDebugActive();
            if ($debug) {
                echo $e->getMessage();
            }
            return false;
        }
    }
}
