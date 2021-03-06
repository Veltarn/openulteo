/**
 * Copyright 2012 Ulteo SAS
 * http://www.ulteo.com
 * Author Alexandre CONFIANT-LATOUR <a.confiant@ulteo.com> 2012
 *
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 **/

#ifndef __GUAC_RDP_RDP_SEAMRDP_H
#define __GUAC_RDP_RDP_SEAMRDP_H

#include <freerdp/freerdp.h>
#include <guacamole/client.h>

void guac_rdp_process_seamrdp_event(guac_client* client, RDP_EVENT* event);

#endif // __GUAC_RDP_RDP_SEAMRDP_H
