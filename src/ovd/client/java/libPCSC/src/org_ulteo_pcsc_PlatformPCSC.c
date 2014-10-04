/*
 * Copyright (C) 2012 Ulteo SAS
 * http://www.ulteo.com
 * Author Yann Hodique <y.hodique@ulteo.com> 2012
 *
 * Copyright (c) 2005, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

#include <jni.h>
 
#ifndef _WIN32

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <dlfcn.h>
#include <link.h>

#include <winscard.h>

/* from jni_util.h */
void JNU_ThrowNullPointerException(JNIEnv *env, const char *msg);
void JNU_ThrowIOException(JNIEnv *env, const char *msg);

#include "org_ulteo_pcsc_PlatformPCSC.h"

void *hModule;
FPTR_SCardEstablishContext scardEstablishContext;
FPTR_SCardReleaseContext scardReleaseContext;
FPTR_SCardIsValidContext scardIsValidContext;
FPTR_SCardConnect scardConnect;
FPTR_SCardReconnect scardReconnect;
FPTR_SCardDisconnect scardDisconnect;
FPTR_SCardStatus scardStatus;
FPTR_SCardGetStatusChange scardGetStatusChange;
FPTR_SCardCancel scardCancel;
FPTR_SCardTransmit scardTransmit;
FPTR_SCardListReaders scardListReaders;
FPTR_SCardBeginTransaction scardBeginTransaction;
FPTR_SCardEndTransaction scardEndTransaction;
FPTR_SCardControl scardControl;
FPTR_SCardGetAttrib scardGetAttrib;

void *findFunction(JNIEnv *env, void *hModule, char *functionName) {
	void *fAddress = dlsym(hModule, functionName);
	if (fAddress == NULL) {
		char errorMessage[256];
		snprintf(errorMessage, sizeof(errorMessage), "Symbol not found: %s", functionName);
		JNU_ThrowNullPointerException(env, errorMessage);
		return NULL;
	}
	return fAddress;
}

JNIEXPORT void JNICALL Java_org_ulteo_pcsc_PCSC_initialize
		(JNIEnv *env, jclass thisClass, jstring jLibName) {
	const char *libName = (*env)->GetStringUTFChars(env, jLibName, NULL);
	hModule = dlopen(libName, RTLD_LAZY);
	(*env)->ReleaseStringUTFChars(env, jLibName, libName);

	if (hModule == NULL) {
		JNU_ThrowIOException(env, dlerror());
		return;
	}
	scardEstablishContext = (FPTR_SCardEstablishContext)findFunction(env, hModule, "SCardEstablishContext");
	scardReleaseContext   = (FPTR_SCardReleaseContext)  findFunction(env, hModule, "SCardReleaseContext");
	scardIsValidContext   = (FPTR_SCardIsValidContext)  findFunction(env, hModule, "SCardIsValidContext");
	scardConnect		  = (FPTR_SCardConnect)		 findFunction(env, hModule, "SCardConnect");
	scardReconnect		= (FPTR_SCardReconnect)	   findFunction(env, hModule, "SCardReconnect");
	scardDisconnect	   = (FPTR_SCardDisconnect)	  findFunction(env, hModule, "SCardDisconnect");
	scardStatus		   = (FPTR_SCardStatus)		  findFunction(env, hModule, "SCardStatus");
	scardGetStatusChange  = (FPTR_SCardGetStatusChange) findFunction(env, hModule, "SCardGetStatusChange");
	scardCancel		   = (FPTR_SCardCancel)		  findFunction(env, hModule, "SCardCancel");
	scardTransmit		 = (FPTR_SCardTransmit)		findFunction(env, hModule, "SCardTransmit");
	scardListReaders	  = (FPTR_SCardListReaders)	 findFunction(env, hModule, "SCardListReaders");
	scardBeginTransaction = (FPTR_SCardBeginTransaction)findFunction(env, hModule, "SCardBeginTransaction");
	scardEndTransaction   = (FPTR_SCardEndTransaction)  findFunction(env, hModule, "SCardEndTransaction");
	scardControl		  = (FPTR_SCardControl)		 findFunction(env, hModule, "SCardControl");
	scardGetAttrib		= (FPTR_SCardGetAttrib)	   findFunction(env, hModule, "SCardGetAttrib");
}
#else
JNIEXPORT void JNICALL Java_org_ulteo_pcsc_PCSC_initialize
		(JNIEnv *env, jclass thisClass, jstring jLibName) {
}
#endif
