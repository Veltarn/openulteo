/**
 * Copyright (C) 2012 Ulteo SAS
 * http://www.ulteo.com
 * Author Jocelyn DELALANDE <j.delalande@ulteo.com> 2012
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


#include "unicode_convtable.h"

int keysym2uni(int keysym) {
	init_unicode_tables();
	/* Default: no exception */
	int exception = 0;

	if (keysym < 0x100000) {
		// Look for a 4-digits-form exception
		exception =  keysym2uni_base[keysym];
	} else {
		// Look for a 7-digits-form exception
		/* Switch to look for 0x1001XXX 0x1002XXX or 0x1002XXX 
		   the tables only indexes on XXX
		 */
		switch(keysym & 0xFFFF000) {
		case 0x1000000:
			exception = keysym2uni_ext0[keysym & 0x0000FFF];
			break;
		case 0x1001000:
			exception = keysym2uni_ext1[keysym & 0x0000FFF];
			break;
		case 0x1002000:
			exception = keysym2uni_ext2[keysym & 0x0000FFF];
			break;
		}

		/* If the keysym is not within exceptions, keysym = unicode */
	}
	if (exception != 0) {
		return exception;
	} else {
		return keysym;
	}
}

void init_unicode_tables() {
	// initialize only on first function call.
	static int keysym2uni_initialized = 0;

	if (keysym2uni_initialized >0)
		return;
	else
		keysym2uni_initialized = 1;

/* Filled with script tools/ini2dot_h_unimap.py */
keysym2uni_base[0x11] = 104;
keysym2uni_base[0x1a1] = 0x104;
keysym2uni_base[0x1a2] = 0x2d8;
keysym2uni_base[0x1a3] = 0x141;
keysym2uni_base[0x1a5] = 0x13d;
keysym2uni_base[0x1a6] = 0x15a;
keysym2uni_base[0x1a9] = 0x160;
keysym2uni_base[0x1aa] = 0x15e;
keysym2uni_base[0x1ab] = 0x164;
keysym2uni_base[0x1ac] = 0x179;
keysym2uni_base[0x1ae] = 0x17d;
keysym2uni_base[0x1af] = 0x17b;
keysym2uni_base[0x1b1] = 0x105;
keysym2uni_base[0x1b2] = 0x2db;
keysym2uni_base[0x1b3] = 0x142;
keysym2uni_base[0x1b5] = 0x13e;
keysym2uni_base[0x1b6] = 0x15b;
keysym2uni_base[0x1b7] = 0x2c7;
keysym2uni_base[0x1b9] = 0x161;
keysym2uni_base[0x1ba] = 0x15f;
keysym2uni_base[0x1bb] = 0x165;
keysym2uni_base[0x1bc] = 0x17a;
keysym2uni_base[0x1bd] = 0x2dd;
keysym2uni_base[0x1be] = 0x17e;
keysym2uni_base[0x1bf] = 0x17c;
keysym2uni_base[0x1c0] = 0x154;
keysym2uni_base[0x1c3] = 0x102;
keysym2uni_base[0x1c5] = 0x139;
keysym2uni_base[0x1c6] = 0x106;
keysym2uni_base[0x1c8] = 0x10c;
keysym2uni_base[0x1ca] = 0x118;
keysym2uni_base[0x1cc] = 0x11a;
keysym2uni_base[0x1cf] = 0x10e;
keysym2uni_base[0x1d0] = 0x110;
keysym2uni_base[0x1d1] = 0x143;
keysym2uni_base[0x1d2] = 0x147;
keysym2uni_base[0x1d5] = 0x150;
keysym2uni_base[0x1d8] = 0x158;
keysym2uni_base[0x1d9] = 0x16e;
keysym2uni_base[0x1db] = 0x170;
keysym2uni_base[0x1de] = 0x162;
keysym2uni_base[0x1e0] = 0x155;
keysym2uni_base[0x1e3] = 0x103;
keysym2uni_base[0x1e5] = 0x13a;
keysym2uni_base[0x1e6] = 0x107;
keysym2uni_base[0x1e8] = 0x10d;
keysym2uni_base[0x1ea] = 0x119;
keysym2uni_base[0x1ec] = 0x11b;
keysym2uni_base[0x1ef] = 0x10f;
keysym2uni_base[0x1f0] = 0x111;
keysym2uni_base[0x1f1] = 0x144;
keysym2uni_base[0x1f2] = 0x148;
keysym2uni_base[0x1f5] = 0x151;
keysym2uni_base[0x1fb] = 0x171;
keysym2uni_base[0x1f8] = 0x159;
keysym2uni_base[0x1f9] = 0x16f;
keysym2uni_base[0x1fe] = 0x163;
keysym2uni_base[0x2a1] = 0x126;
keysym2uni_base[0x2a6] = 0x124;
keysym2uni_base[0x2a9] = 0x130;
keysym2uni_base[0x2ab] = 0x11e;
keysym2uni_base[0x2ac] = 0x134;
keysym2uni_base[0x2b1] = 0x127;
keysym2uni_base[0x2b6] = 0x125;
keysym2uni_base[0x2b9] = 0x131;
keysym2uni_base[0x2bb] = 0x11f;
keysym2uni_base[0x2bc] = 0x135;
keysym2uni_base[0x2c5] = 0x10a;
keysym2uni_base[0x2c6] = 0x108;
keysym2uni_base[0x2d5] = 0x120;
keysym2uni_base[0x2d8] = 0x11c;
keysym2uni_base[0x2dd] = 0x16c;
keysym2uni_base[0x2de] = 0x15c;
keysym2uni_base[0x2e5] = 0x10b;
keysym2uni_base[0x2e6] = 0x109;
keysym2uni_base[0x2f5] = 0x121;
keysym2uni_base[0x2f8] = 0x11d;
keysym2uni_base[0x2fd] = 0x16d;
keysym2uni_base[0x2fe] = 0x15d;
keysym2uni_base[0x3a2] = 0x138;
keysym2uni_base[0x3a3] = 0x156;
keysym2uni_base[0x3a5] = 0x128;
keysym2uni_base[0x3a6] = 0x13b;
keysym2uni_base[0x3aa] = 0x112;
keysym2uni_base[0x3ab] = 0x122;
keysym2uni_base[0x3ac] = 0x166;
keysym2uni_base[0x3b3] = 0x157;
keysym2uni_base[0x3b5] = 0x129;
keysym2uni_base[0x3b6] = 0x13c;
keysym2uni_base[0x3ba] = 0x113;
keysym2uni_base[0x3bb] = 0x123;
keysym2uni_base[0x3bc] = 0x167;
keysym2uni_base[0x3bd] = 0x14a;
keysym2uni_base[0x3bf] = 0x14b;
keysym2uni_base[0x3c0] = 0x100;
keysym2uni_base[0x3c7] = 0x12e;
keysym2uni_base[0x3cc] = 0x116;
keysym2uni_base[0x3cf] = 0x12a;
keysym2uni_base[0x3d1] = 0x145;
keysym2uni_base[0x3d2] = 0x14c;
keysym2uni_base[0x3d3] = 0x136;
keysym2uni_base[0x3d9] = 0x172;
keysym2uni_base[0x3dd] = 0x168;
keysym2uni_base[0x3de] = 0x16a;
keysym2uni_base[0x3e0] = 0x101;
keysym2uni_base[0x3e7] = 0x12f;
keysym2uni_base[0x3ec] = 0x117;
keysym2uni_base[0x3ef] = 0x12b;
keysym2uni_base[0x3f1] = 0x146;
keysym2uni_base[0x3f2] = 0x14d;
keysym2uni_base[0x3f3] = 0x137;
keysym2uni_base[0x3f9] = 0x173;
keysym2uni_base[0x3fd] = 0x169;
keysym2uni_base[0x3fe] = 0x16b;
keysym2uni_base[0x13bc] = 0x152;
keysym2uni_base[0x13bd] = 0x153;
keysym2uni_base[0x13be] = 0x178;
keysym2uni_base[0x47e] = 0x203e;
keysym2uni_base[0x4a1] = 0x3002;
keysym2uni_base[0x4a2] = 0x300c;
keysym2uni_base[0x4a3] = 0x300d;
keysym2uni_base[0x4a4] = 0x3001;
keysym2uni_base[0x4a5] = 0x30fb;
keysym2uni_base[0x4a6] = 0x30f2;
keysym2uni_base[0x4a7] = 0x30a1;
keysym2uni_base[0x4a8] = 0x30a3;
keysym2uni_base[0x4a9] = 0x30a5;
keysym2uni_base[0x4aa] = 0x30a7;
keysym2uni_base[0x4ab] = 0x30a9;
keysym2uni_base[0x4ac] = 0x30e3;
keysym2uni_base[0x4ad] = 0x30e5;
keysym2uni_base[0x4ae] = 0x30e7;
keysym2uni_base[0x4af] = 0x30c3;
keysym2uni_base[0x4b0] = 0x30fc;
keysym2uni_base[0x4b1] = 0x30a2;
keysym2uni_base[0x4b2] = 0x30a4;
keysym2uni_base[0x4b3] = 0x30a6;
keysym2uni_base[0x4b4] = 0x30a8;
keysym2uni_base[0x4b5] = 0x30aa;
keysym2uni_base[0x4b6] = 0x30ab;
keysym2uni_base[0x4b7] = 0x30ad;
keysym2uni_base[0x4b8] = 0x30af;
keysym2uni_base[0x4b9] = 0x30b1;
keysym2uni_base[0x4ba] = 0x30b3;
keysym2uni_base[0x4bb] = 0x30b5;
keysym2uni_base[0x4bc] = 0x30b7;
keysym2uni_base[0x4bd] = 0x30b9;
keysym2uni_base[0x4be] = 0x30bb;
keysym2uni_base[0x4bf] = 0x30bd;
keysym2uni_base[0x4c0] = 0x30bf;
keysym2uni_base[0x4c1] = 0x30c1;
keysym2uni_base[0x4c2] = 0x30c4;
keysym2uni_base[0x4c3] = 0x30c6;
keysym2uni_base[0x4c4] = 0x30c8;
keysym2uni_base[0x4c5] = 0x30ca;
keysym2uni_base[0x4c6] = 0x30cb;
keysym2uni_base[0x4c7] = 0x30cc;
keysym2uni_base[0x4c8] = 0x30cd;
keysym2uni_base[0x4c9] = 0x30ce;
keysym2uni_base[0x4ca] = 0x30cf;
keysym2uni_base[0x4cb] = 0x30d2;
keysym2uni_base[0x4cc] = 0x30d5;
keysym2uni_base[0x4cd] = 0x30d8;
keysym2uni_base[0x4ce] = 0x30db;
keysym2uni_base[0x4cf] = 0x30de;
keysym2uni_base[0x4d0] = 0x30df;
keysym2uni_base[0x4d1] = 0x30e0;
keysym2uni_base[0x4d2] = 0x30e1;
keysym2uni_base[0x4d3] = 0x30e2;
keysym2uni_base[0x4d4] = 0x30e4;
keysym2uni_base[0x4d5] = 0x30e6;
keysym2uni_base[0x4d6] = 0x30e8;
keysym2uni_base[0x4d7] = 0x30e9;
keysym2uni_base[0x4d8] = 0x30ea;
keysym2uni_base[0x4d9] = 0x30eb;
keysym2uni_base[0x4da] = 0x30ec;
keysym2uni_base[0x4db] = 0x30ed;
keysym2uni_base[0x4dc] = 0x30ef;
keysym2uni_base[0x4dd] = 0x30f3;
keysym2uni_base[0x4de] = 0x309b;
keysym2uni_base[0x4df] = 0x309c;
keysym2uni_base[0x5ac] = 0x60c;
keysym2uni_base[0x5bb] = 0x61b;
keysym2uni_base[0x5bf] = 0x61f;
keysym2uni_base[0x5c1] = 0x621;
keysym2uni_base[0x5c2] = 0x622;
keysym2uni_base[0x5c3] = 0x623;
keysym2uni_base[0x5c4] = 0x624;
keysym2uni_base[0x5c5] = 0x625;
keysym2uni_base[0x5c6] = 0x626;
keysym2uni_base[0x5c7] = 0x627;
keysym2uni_base[0x5c8] = 0x628;
keysym2uni_base[0x5c9] = 0x629;
keysym2uni_base[0x5ca] = 0x62a;
keysym2uni_base[0x5cb] = 0x62b;
keysym2uni_base[0x5cc] = 0x62c;
keysym2uni_base[0x5cd] = 0x62d;
keysym2uni_base[0x5ce] = 0x62e;
keysym2uni_base[0x5cf] = 0x62f;
keysym2uni_base[0x5d0] = 0x630;
keysym2uni_base[0x5d1] = 0x631;
keysym2uni_base[0x5d2] = 0x632;
keysym2uni_base[0x5d3] = 0x633;
keysym2uni_base[0x5d4] = 0x634;
keysym2uni_base[0x5d5] = 0x635;
keysym2uni_base[0x5d6] = 0x636;
keysym2uni_base[0x5d7] = 0x637;
keysym2uni_base[0x5d8] = 0x638;
keysym2uni_base[0x5d9] = 0x639;
keysym2uni_base[0x5da] = 0x63a;
keysym2uni_base[0x5e0] = 0x640;
keysym2uni_base[0x5e1] = 0x641;
keysym2uni_base[0x5e2] = 0x642;
keysym2uni_base[0x5e3] = 0x643;
keysym2uni_base[0x5e4] = 0x644;
keysym2uni_base[0x5e5] = 0x645;
keysym2uni_base[0x5e6] = 0x646;
keysym2uni_base[0x5e7] = 0x647;
keysym2uni_base[0x5e8] = 0x648;
keysym2uni_base[0x5e9] = 0x649;
keysym2uni_base[0x5ea] = 0x64a;
keysym2uni_base[0x5eb] = 0x64b;
keysym2uni_base[0x5ec] = 0x64c;
keysym2uni_base[0x5ed] = 0x64d;
keysym2uni_base[0x5ee] = 0x64e;
keysym2uni_base[0x5ef] = 0x64f;
keysym2uni_base[0x5f0] = 0x650;
keysym2uni_base[0x5f1] = 0x651;
keysym2uni_base[0x5f2] = 0x652;
keysym2uni_base[0x6a1] = 0x452;
keysym2uni_base[0x6a2] = 0x453;
keysym2uni_base[0x6a3] = 0x451;
keysym2uni_base[0x6a4] = 0x454;
keysym2uni_base[0x6a5] = 0x455;
keysym2uni_base[0x6a6] = 0x456;
keysym2uni_base[0x6a7] = 0x457;
keysym2uni_base[0x6a8] = 0x458;
keysym2uni_base[0x6a9] = 0x459;
keysym2uni_base[0x6aa] = 0x45a;
keysym2uni_base[0x6ab] = 0x45b;
keysym2uni_base[0x6ac] = 0x45c;
keysym2uni_base[0x6ad] = 0x491;
keysym2uni_base[0x6ae] = 0x45e;
keysym2uni_base[0x6af] = 0x45f;
keysym2uni_base[0x6b0] = 0x2116;
keysym2uni_base[0x6b1] = 0x402;
keysym2uni_base[0x6b2] = 0x403;
keysym2uni_base[0x6b3] = 0x401;
keysym2uni_base[0x6b4] = 0x404;
keysym2uni_base[0x6b5] = 0x405;
keysym2uni_base[0x6b6] = 0x406;
keysym2uni_base[0x6b7] = 0x407;
keysym2uni_base[0x6b8] = 0x408;
keysym2uni_base[0x6b9] = 0x409;
keysym2uni_base[0x6ba] = 0x40a;
keysym2uni_base[0x6bb] = 0x40b;
keysym2uni_base[0x6bc] = 0x40c;
keysym2uni_base[0x6bd] = 0x490;
keysym2uni_base[0x6be] = 0x40e;
keysym2uni_base[0x6bf] = 0x40f;
keysym2uni_base[0x6c0] = 0x44e;
keysym2uni_base[0x6c1] = 0x430;
keysym2uni_base[0x6c2] = 0x431;
keysym2uni_base[0x6c3] = 0x446;
keysym2uni_base[0x6c4] = 0x434;
keysym2uni_base[0x6c5] = 0x435;
keysym2uni_base[0x6c6] = 0x444;
keysym2uni_base[0x6c7] = 0x433;
keysym2uni_base[0x6c8] = 0x445;
keysym2uni_base[0x6c9] = 0x438;
keysym2uni_base[0x6ca] = 0x439;
keysym2uni_base[0x6cb] = 0x43a;
keysym2uni_base[0x6cc] = 0x43b;
keysym2uni_base[0x6cd] = 0x43c;
keysym2uni_base[0x6ce] = 0x43d;
keysym2uni_base[0x6cf] = 0x43e;
keysym2uni_base[0x6d0] = 0x43f;
keysym2uni_base[0x6d1] = 0x44f;
keysym2uni_base[0x6d2] = 0x440;
keysym2uni_base[0x6d3] = 0x441;
keysym2uni_base[0x6d4] = 0x442;
keysym2uni_base[0x6d5] = 0x443;
keysym2uni_base[0x6d6] = 0x436;
keysym2uni_base[0x6d7] = 0x432;
keysym2uni_base[0x6d8] = 0x44c;
keysym2uni_base[0x6d9] = 0x44b;
keysym2uni_base[0x6da] = 0x437;
keysym2uni_base[0x6db] = 0x448;
keysym2uni_base[0x6dc] = 0x44d;
keysym2uni_base[0x6dd] = 0x449;
keysym2uni_base[0x6de] = 0x447;
keysym2uni_base[0x6df] = 0x44a;
keysym2uni_base[0x6e0] = 0x42e;
keysym2uni_base[0x6e1] = 0x410;
keysym2uni_base[0x6e2] = 0x411;
keysym2uni_base[0x6e3] = 0x426;
keysym2uni_base[0x6e4] = 0x414;
keysym2uni_base[0x6e5] = 0x415;
keysym2uni_base[0x6e6] = 0x424;
keysym2uni_base[0x6e7] = 0x413;
keysym2uni_base[0x6e8] = 0x425;
keysym2uni_base[0x6e9] = 0x418;
keysym2uni_base[0x6ea] = 0x419;
keysym2uni_base[0x6eb] = 0x41a;
keysym2uni_base[0x6ec] = 0x41b;
keysym2uni_base[0x6ed] = 0x41c;
keysym2uni_base[0x6ee] = 0x41d;
keysym2uni_base[0x6ef] = 0x41e;
keysym2uni_base[0x6f0] = 0x41f;
keysym2uni_base[0x6f1] = 0x42f;
keysym2uni_base[0x6f2] = 0x420;
keysym2uni_base[0x6f3] = 0x421;
keysym2uni_base[0x6f4] = 0x422;
keysym2uni_base[0x6f5] = 0x423;
keysym2uni_base[0x6f6] = 0x416;
keysym2uni_base[0x6f7] = 0x412;
keysym2uni_base[0x6f8] = 0x42c;
keysym2uni_base[0x6f9] = 0x42b;
keysym2uni_base[0x6fa] = 0x417;
keysym2uni_base[0x6fb] = 0x428;
keysym2uni_base[0x6fc] = 0x42d;
keysym2uni_base[0x6fd] = 0x429;
keysym2uni_base[0x6fe] = 0x427;
keysym2uni_base[0x6ff] = 0x42a;
keysym2uni_base[0x7a1] = 0x386;
keysym2uni_base[0x7a2] = 0x388;
keysym2uni_base[0x7a3] = 0x389;
keysym2uni_base[0x7a4] = 0x38a;
keysym2uni_base[0x7a5] = 0x3aa;
keysym2uni_base[0x7a7] = 0x38c;
keysym2uni_base[0x7a8] = 0x38e;
keysym2uni_base[0x7a9] = 0x3ab;
keysym2uni_base[0x7ab] = 0x38f;
keysym2uni_base[0x7ae] = 0x385;
keysym2uni_base[0x7af] = 0x2015;
keysym2uni_base[0x7b1] = 0x3ac;
keysym2uni_base[0x7b2] = 0x3ad;
keysym2uni_base[0x7b3] = 0x3ae;
keysym2uni_base[0x7b4] = 0x3af;
keysym2uni_base[0x7b5] = 0x3ca;
keysym2uni_base[0x7b6] = 0x390;
keysym2uni_base[0x7b7] = 0x3cc;
keysym2uni_base[0x7b8] = 0x3cd;
keysym2uni_base[0x7b9] = 0x3cb;
keysym2uni_base[0x7ba] = 0x3b0;
keysym2uni_base[0x7bb] = 0x3ce;
keysym2uni_base[0x7c1] = 0x391;
keysym2uni_base[0x7c2] = 0x392;
keysym2uni_base[0x7c3] = 0x393;
keysym2uni_base[0x7c4] = 0x394;
keysym2uni_base[0x7c5] = 0x395;
keysym2uni_base[0x7c6] = 0x396;
keysym2uni_base[0x7c7] = 0x397;
keysym2uni_base[0x7c8] = 0x398;
keysym2uni_base[0x7c9] = 0x399;
keysym2uni_base[0x7ca] = 0x39a;
keysym2uni_base[0x7cb] = 0x39b;
keysym2uni_base[0x7cc] = 0x39c;
keysym2uni_base[0x7cd] = 0x39d;
keysym2uni_base[0x7ce] = 0x39e;
keysym2uni_base[0x7cf] = 0x39f;
keysym2uni_base[0x7d0] = 0x3a0;
keysym2uni_base[0x7d1] = 0x3a1;
keysym2uni_base[0x7d2] = 0x3a3;
keysym2uni_base[0x7d4] = 0x3a4;
keysym2uni_base[0x7d5] = 0x3a5;
keysym2uni_base[0x7d6] = 0x3a6;
keysym2uni_base[0x7d7] = 0x3a7;
keysym2uni_base[0x7d8] = 0x3a8;
keysym2uni_base[0x7d9] = 0x3a9;
keysym2uni_base[0x7e1] = 0x3b1;
keysym2uni_base[0x7e2] = 0x3b2;
keysym2uni_base[0x7e3] = 0x3b3;
keysym2uni_base[0x7e4] = 0x3b4;
keysym2uni_base[0x7e5] = 0x3b5;
keysym2uni_base[0x7e6] = 0x3b6;
keysym2uni_base[0x7e7] = 0x3b7;
keysym2uni_base[0x7e8] = 0x3b8;
keysym2uni_base[0x7e9] = 0x3b9;
keysym2uni_base[0x7ea] = 0x3ba;
keysym2uni_base[0x7eb] = 0x3bb;
keysym2uni_base[0x7ec] = 0x3bc;
keysym2uni_base[0x7ed] = 0x3bd;
keysym2uni_base[0x7ee] = 0x3be;
keysym2uni_base[0x7ef] = 0x3bf;
keysym2uni_base[0x7f0] = 0x3c0;
keysym2uni_base[0x7f1] = 0x3c1;
keysym2uni_base[0x7f2] = 0x3c3;
keysym2uni_base[0x7f3] = 0x3c2;
keysym2uni_base[0x7f4] = 0x3c4;
keysym2uni_base[0x7f5] = 0x3c5;
keysym2uni_base[0x7f6] = 0x3c6;
keysym2uni_base[0x7f7] = 0x3c7;
keysym2uni_base[0x7f8] = 0x3c8;
keysym2uni_base[0x7f9] = 0x3c9;
keysym2uni_base[0x8a1] = 0x23b7;
keysym2uni_base[0x9ec] = 0x250c;
keysym2uni_base[0x9f1] = 0x2500;
keysym2uni_base[0x8a4] = 0x2320;
keysym2uni_base[0x8a5] = 0x2321;
keysym2uni_base[0x9f8] = 0x2502;
keysym2uni_base[0x8a7] = 0x23a1;
keysym2uni_base[0x8a8] = 0x23a3;
keysym2uni_base[0x8a9] = 0x23a4;
keysym2uni_base[0x8aa] = 0x23a6;
keysym2uni_base[0x8ab] = 0x239b;
keysym2uni_base[0x8ac] = 0x239d;
keysym2uni_base[0x8ad] = 0x239e;
keysym2uni_base[0x8ae] = 0x23a0;
keysym2uni_base[0x8af] = 0x23a8;
keysym2uni_base[0x8b0] = 0x23ac;
keysym2uni_base[0x8bc] = 0x2264;
keysym2uni_base[0x8bd] = 0x2260;
keysym2uni_base[0x8be] = 0x2265;
keysym2uni_base[0x8bf] = 0x222b;
keysym2uni_base[0x8c0] = 0x2234;
keysym2uni_base[0x8c1] = 0x221d;
keysym2uni_base[0x8c2] = 0x221e;
keysym2uni_base[0x8c5] = 0x2207;
keysym2uni_base[0x8c8] = 0x223c;
keysym2uni_base[0x8c9] = 0x2243;
keysym2uni_base[0x8cd] = 0x21d4;
keysym2uni_base[0x8ce] = 0x21d2;
keysym2uni_base[0x8cf] = 0x2261;
keysym2uni_base[0xbda] = 0x2282;
keysym2uni_base[0xbd8] = 0x2283;
keysym2uni_base[0xbc3] = 0x2229;
keysym2uni_base[0xbd6] = 0x222a;
keysym2uni_base[0xba9] = 0x2227;
keysym2uni_base[0xba8] = 0x2228;
keysym2uni_base[0x8f6] = 0x192;
keysym2uni_base[0x8fb] = 0x2190;
keysym2uni_base[0x8fc] = 0x2191;
keysym2uni_base[0x8fd] = 0x2192;
keysym2uni_base[0x8fe] = 0x2193;
keysym2uni_base[0x9e0] = 0x25c6;
keysym2uni_base[0x9e1] = 0x2592;
keysym2uni_base[0x9e2] = 0x2409;
keysym2uni_base[0x9e3] = 0x240c;
keysym2uni_base[0x9e4] = 0x240d;
keysym2uni_base[0x9e5] = 0x240a;
keysym2uni_base[0x9e8] = 0x2424;
keysym2uni_base[0x9e9] = 0x240b;
keysym2uni_base[0x9ea] = 0x2518;
keysym2uni_base[0x9eb] = 0x2510;
keysym2uni_base[0x9ed] = 0x2514;
keysym2uni_base[0x9ee] = 0x253c;
keysym2uni_base[0x9ef] = 0x23ba;
keysym2uni_base[0x9f0] = 0x23bb;
keysym2uni_base[0x9f2] = 0x23bc;
keysym2uni_base[0x9f3] = 0x23bd;
keysym2uni_base[0x9f4] = 0x251c;
keysym2uni_base[0x9f5] = 0x2524;
keysym2uni_base[0x9f6] = 0x2534;
keysym2uni_base[0x9f7] = 0x252c;
keysym2uni_base[0xaa1] = 0x2003;
keysym2uni_base[0xaa2] = 0x2002;
keysym2uni_base[0xaa3] = 0x2004;
keysym2uni_base[0xaa4] = 0x2005;
keysym2uni_base[0xaa5] = 0x2007;
keysym2uni_base[0xaa6] = 0x2008;
keysym2uni_base[0xaa7] = 0x2009;
keysym2uni_base[0xaa8] = 0x200a;
keysym2uni_base[0xaa9] = 0x2014;
keysym2uni_base[0xaaa] = 0x2013;
keysym2uni_base[0xaac] = 0x2423;
keysym2uni_base[0xaae] = 0x2026;
keysym2uni_base[0xaaf] = 0x2025;
keysym2uni_base[0xab0] = 0x2153;
keysym2uni_base[0xab1] = 0x2154;
keysym2uni_base[0xab2] = 0x2155;
keysym2uni_base[0xab3] = 0x2156;
keysym2uni_base[0xab4] = 0x2157;
keysym2uni_base[0xab5] = 0x2158;
keysym2uni_base[0xab6] = 0x2159;
keysym2uni_base[0xab7] = 0x215a;
keysym2uni_base[0xab8] = 0x2105;
keysym2uni_base[0xabb] = 0x2012;
keysym2uni_base[0xabc] = 0x27e8;
keysym2uni_base[0xabd] = 0x2e;
keysym2uni_base[0xabe] = 0x27e9;
keysym2uni_base[0xac3] = 0x215b;
keysym2uni_base[0xac4] = 0x215c;
keysym2uni_base[0xac5] = 0x215d;
keysym2uni_base[0xac6] = 0x215e;
keysym2uni_base[0xac9] = 0x2122;
keysym2uni_base[0xaca] = 0x2613;
keysym2uni_base[0xacc] = 0x25c1;
keysym2uni_base[0xacd] = 0x25b7;
keysym2uni_base[0xbcf] = 0x25cb;
keysym2uni_base[0xacf] = 0x25af;
keysym2uni_base[0xad0] = 0x2018;
keysym2uni_base[0xad1] = 0x2019;
keysym2uni_base[0xad2] = 0x201c;
keysym2uni_base[0xad3] = 0x201d;
keysym2uni_base[0xad4] = 0x211e;
keysym2uni_base[0xad6] = 0x2032;
keysym2uni_base[0xad7] = 0x2033;
keysym2uni_base[0xad9] = 0x271d;
keysym2uni_base[0xadb] = 0x25ac;
keysym2uni_base[0xadc] = 0x25c0;
keysym2uni_base[0xadd] = 0x25b6;
keysym2uni_base[0xade] = 0x25cf;
keysym2uni_base[0xadf] = 0x25ae;
keysym2uni_base[0xae0] = 0x25e6;
keysym2uni_base[0xae1] = 0x25ab;
keysym2uni_base[0xae2] = 0x25ad;
keysym2uni_base[0xae3] = 0x25b3;
keysym2uni_base[0xae4] = 0x25bd;
keysym2uni_base[0xae5] = 0x2606;
keysym2uni_base[0xae6] = 0x2022;
keysym2uni_base[0xae7] = 0x25aa;
keysym2uni_base[0xae8] = 0x25b2;
keysym2uni_base[0xae9] = 0x25bc;
keysym2uni_base[0xaea] = 0x261c;
keysym2uni_base[0xaeb] = 0x261e;
keysym2uni_base[0xaec] = 0x2663;
keysym2uni_base[0xaed] = 0x2666;
keysym2uni_base[0xaee] = 0x2665;
keysym2uni_base[0xaf0] = 0x2720;
keysym2uni_base[0xaf1] = 0x2020;
keysym2uni_base[0xaf2] = 0x2021;
keysym2uni_base[0xaf3] = 0x2713;
keysym2uni_base[0xaf4] = 0x2717;
keysym2uni_base[0xaf5] = 0x266f;
keysym2uni_base[0xaf6] = 0x266d;
keysym2uni_base[0xaf7] = 0x2642;
keysym2uni_base[0xaf8] = 0x2640;
keysym2uni_base[0xaf9] = 0x260e;
keysym2uni_base[0xafa] = 0x2315;
keysym2uni_base[0xafb] = 0x2117;
keysym2uni_base[0xafc] = 0x2038;
keysym2uni_base[0xafd] = 0x201a;
keysym2uni_base[0xafe] = 0x201e;
keysym2uni_base[0xba3] = 0x3c;
keysym2uni_base[0xba6] = 0x3e;
keysym2uni_base[0xbc0] = 0xaf;
keysym2uni_base[0xbc2] = 0x22a4;
keysym2uni_base[0xbc4] = 0x230a;
keysym2uni_base[0xbca] = 0x2218;
keysym2uni_base[0xbcc] = 0x2395;
keysym2uni_base[0xbce] = 0x22a5;
keysym2uni_base[0xbd3] = 0x2308;
keysym2uni_base[0xbdc] = 0x22a3;
keysym2uni_base[0xbfc] = 0x22a2;
keysym2uni_base[0xcdf] = 0x2017;
keysym2uni_base[0xce0] = 0x5d0;
keysym2uni_base[0xce1] = 0x5d1;
keysym2uni_base[0xce2] = 0x5d2;
keysym2uni_base[0xce3] = 0x5d3;
keysym2uni_base[0xce4] = 0x5d4;
keysym2uni_base[0xce5] = 0x5d5;
keysym2uni_base[0xce6] = 0x5d6;
keysym2uni_base[0xce7] = 0x5d7;
keysym2uni_base[0xce8] = 0x5d8;
keysym2uni_base[0xce9] = 0x5d9;
keysym2uni_base[0xcea] = 0x5da;
keysym2uni_base[0xceb] = 0x5db;
keysym2uni_base[0xcec] = 0x5dc;
keysym2uni_base[0xced] = 0x5dd;
keysym2uni_base[0xcee] = 0x5de;
keysym2uni_base[0xcef] = 0x5df;
keysym2uni_base[0xcf0] = 0x5e0;
keysym2uni_base[0xcf1] = 0x5e1;
keysym2uni_base[0xcf2] = 0x5e2;
keysym2uni_base[0xcf3] = 0x5e3;
keysym2uni_base[0xcf4] = 0x5e4;
keysym2uni_base[0xcf5] = 0x5e5;
keysym2uni_base[0xcf6] = 0x5e6;
keysym2uni_base[0xcf7] = 0x5e7;
keysym2uni_base[0xcf8] = 0x5e8;
keysym2uni_base[0xcf9] = 0x5e9;
keysym2uni_base[0xcfa] = 0x5ea;
keysym2uni_base[0xda1] = 0xe01;
keysym2uni_base[0xda2] = 0xe02;
keysym2uni_base[0xda3] = 0xe03;
keysym2uni_base[0xda4] = 0xe04;
keysym2uni_base[0xda5] = 0xe05;
keysym2uni_base[0xda6] = 0xe06;
keysym2uni_base[0xda7] = 0xe07;
keysym2uni_base[0xda8] = 0xe08;
keysym2uni_base[0xda9] = 0xe09;
keysym2uni_base[0xdaa] = 0xe0a;
keysym2uni_base[0xdab] = 0xe0b;
keysym2uni_base[0xdac] = 0xe0c;
keysym2uni_base[0xdad] = 0xe0d;
keysym2uni_base[0xdae] = 0xe0e;
keysym2uni_base[0xdaf] = 0xe0f;
keysym2uni_base[0xdb0] = 0xe10;
keysym2uni_base[0xdb1] = 0xe11;
keysym2uni_base[0xdb2] = 0xe12;
keysym2uni_base[0xdb3] = 0xe13;
keysym2uni_base[0xdb4] = 0xe14;
keysym2uni_base[0xdb5] = 0xe15;
keysym2uni_base[0xdb6] = 0xe16;
keysym2uni_base[0xdb7] = 0xe17;
keysym2uni_base[0xdb8] = 0xe18;
keysym2uni_base[0xdb9] = 0xe19;
keysym2uni_base[0xdba] = 0xe1a;
keysym2uni_base[0xdbb] = 0xe1b;
keysym2uni_base[0xdbc] = 0xe1c;
keysym2uni_base[0xdbd] = 0xe1d;
keysym2uni_base[0xdbe] = 0xe1e;
keysym2uni_base[0xdbf] = 0xe1f;
keysym2uni_base[0xdc0] = 0xe20;
keysym2uni_base[0xdc1] = 0xe21;
keysym2uni_base[0xdc2] = 0xe22;
keysym2uni_base[0xdc3] = 0xe23;
keysym2uni_base[0xdc4] = 0xe24;
keysym2uni_base[0xdc5] = 0xe25;
keysym2uni_base[0xdc6] = 0xe26;
keysym2uni_base[0xdc7] = 0xe27;
keysym2uni_base[0xdc8] = 0xe28;
keysym2uni_base[0xdc9] = 0xe29;
keysym2uni_base[0xdca] = 0xe2a;
keysym2uni_base[0xdcb] = 0xe2b;
keysym2uni_base[0xdcc] = 0xe2c;
keysym2uni_base[0xdcd] = 0xe2d;
keysym2uni_base[0xdce] = 0xe2e;
keysym2uni_base[0xdcf] = 0xe2f;
keysym2uni_base[0xdd0] = 0xe30;
keysym2uni_base[0xdd1] = 0xe31;
keysym2uni_base[0xdd2] = 0xe32;
keysym2uni_base[0xdd3] = 0xe33;
keysym2uni_base[0xdd4] = 0xe34;
keysym2uni_base[0xdd5] = 0xe35;
keysym2uni_base[0xdd6] = 0xe36;
keysym2uni_base[0xdd7] = 0xe37;
keysym2uni_base[0xdd8] = 0xe38;
keysym2uni_base[0xdd9] = 0xe39;
keysym2uni_base[0xdda] = 0xe3a;
keysym2uni_base[0xddf] = 0xe3f;
keysym2uni_base[0xde0] = 0xe40;
keysym2uni_base[0xde1] = 0xe41;
keysym2uni_base[0xde2] = 0xe42;
keysym2uni_base[0xde3] = 0xe43;
keysym2uni_base[0xde4] = 0xe44;
keysym2uni_base[0xde5] = 0xe45;
keysym2uni_base[0xde6] = 0xe46;
keysym2uni_base[0xde7] = 0xe47;
keysym2uni_base[0xde8] = 0xe48;
keysym2uni_base[0xde9] = 0xe49;
keysym2uni_base[0xdea] = 0xe4a;
keysym2uni_base[0xdeb] = 0xe4b;
keysym2uni_base[0xdec] = 0xe4c;
keysym2uni_base[0xded] = 0xe4d;
keysym2uni_base[0xdf0] = 0xe50;
keysym2uni_base[0xdf1] = 0xe51;
keysym2uni_base[0xdf2] = 0xe52;
keysym2uni_base[0xdf3] = 0xe53;
keysym2uni_base[0xdf4] = 0xe54;
keysym2uni_base[0xdf5] = 0xe55;
keysym2uni_base[0xdf6] = 0xe56;
keysym2uni_base[0xdf7] = 0xe57;
keysym2uni_base[0xdf8] = 0xe58;
keysym2uni_base[0xdf9] = 0xe59;


keysym2uni_ext0[0x174] = 0x174;
keysym2uni_ext0[0x176] = 0x176;
keysym2uni_ext0[0x175] = 0x175;
keysym2uni_ext0[0x177] = 0x177;
keysym2uni_ext0[0x6f0] = 0x6f0;
keysym2uni_ext0[0x6f1] = 0x6f1;
keysym2uni_ext0[0x6f2] = 0x6f2;
keysym2uni_ext0[0x6f3] = 0x6f3;
keysym2uni_ext0[0x6f4] = 0x6f4;
keysym2uni_ext0[0x6f5] = 0x6f5;
keysym2uni_ext0[0x6f6] = 0x6f6;
keysym2uni_ext0[0x6f7] = 0x6f7;
keysym2uni_ext0[0x6f8] = 0x6f8;
keysym2uni_ext0[0x6f9] = 0x6f9;
keysym2uni_ext0[0x66a] = 0x66a;
keysym2uni_ext0[0x670] = 0x670;
keysym2uni_ext0[0x679] = 0x679;
keysym2uni_ext0[0x67e] = 0x67e;
keysym2uni_ext0[0x686] = 0x686;
keysym2uni_ext0[0x688] = 0x688;
keysym2uni_ext0[0x691] = 0x691;
keysym2uni_ext0[0x6d4] = 0x6d4;
keysym2uni_ext0[0x660] = 0x660;
keysym2uni_ext0[0x661] = 0x661;
keysym2uni_ext0[0x662] = 0x662;
keysym2uni_ext0[0x663] = 0x663;
keysym2uni_ext0[0x664] = 0x664;
keysym2uni_ext0[0x665] = 0x665;
keysym2uni_ext0[0x666] = 0x666;
keysym2uni_ext0[0x667] = 0x667;
keysym2uni_ext0[0x668] = 0x668;
keysym2uni_ext0[0x669] = 0x669;
keysym2uni_ext0[0x653] = 0x653;
keysym2uni_ext0[0x654] = 0x654;
keysym2uni_ext0[0x655] = 0x655;
keysym2uni_ext0[0x698] = 0x698;
keysym2uni_ext0[0x6a4] = 0x6a4;
keysym2uni_ext0[0x6a9] = 0x6a9;
keysym2uni_ext0[0x6af] = 0x6af;
keysym2uni_ext0[0x6ba] = 0x6ba;
keysym2uni_ext0[0x6be] = 0x6be;
keysym2uni_ext0[0x6cc] = 0x6cc;
keysym2uni_ext0[0x6d2] = 0x6d2;
keysym2uni_ext0[0x6c1] = 0x6c1;
keysym2uni_ext0[0x492] = 0x492;
keysym2uni_ext0[0x493] = 0x493;
keysym2uni_ext0[0x496] = 0x496;
keysym2uni_ext0[0x497] = 0x497;
keysym2uni_ext0[0x49a] = 0x49a;
keysym2uni_ext0[0x49b] = 0x49b;
keysym2uni_ext0[0x49c] = 0x49c;
keysym2uni_ext0[0x49d] = 0x49d;
keysym2uni_ext0[0x4a2] = 0x4a2;
keysym2uni_ext0[0x4a3] = 0x4a3;
keysym2uni_ext0[0x4ae] = 0x4ae;
keysym2uni_ext0[0x4af] = 0x4af;
keysym2uni_ext0[0x4b0] = 0x4b0;
keysym2uni_ext0[0x4b1] = 0x4b1;
keysym2uni_ext0[0x4b2] = 0x4b2;
keysym2uni_ext0[0x4b3] = 0x4b3;
keysym2uni_ext0[0x4b6] = 0x4b6;
keysym2uni_ext0[0x4b7] = 0x4b7;
keysym2uni_ext0[0x4b8] = 0x4b8;
keysym2uni_ext0[0x4b9] = 0x4b9;
keysym2uni_ext0[0x4ba] = 0x4ba;
keysym2uni_ext0[0x4bb] = 0x4bb;
keysym2uni_ext0[0x4d8] = 0x4d8;
keysym2uni_ext0[0x4d9] = 0x4d9;
keysym2uni_ext0[0x4e2] = 0x4e2;
keysym2uni_ext0[0x4e3] = 0x4e3;
keysym2uni_ext0[0x4e8] = 0x4e8;
keysym2uni_ext0[0x4e9] = 0x4e9;
keysym2uni_ext0[0x4ee] = 0x4ee;
keysym2uni_ext0[0x4ef] = 0x4ef;
keysym2uni_ext0[0x587] = 0x587;
keysym2uni_ext0[0x589] = 0x589;
keysym2uni_ext0[0x55d] = 0x55d;
keysym2uni_ext0[0x58a] = 0x58a;
keysym2uni_ext0[0x55c] = 0x55c;
keysym2uni_ext0[0x55b] = 0x55b;
keysym2uni_ext0[0x55e] = 0x55e;
keysym2uni_ext0[0x531] = 0x531;
keysym2uni_ext0[0x561] = 0x561;
keysym2uni_ext0[0x532] = 0x532;
keysym2uni_ext0[0x562] = 0x562;
keysym2uni_ext0[0x533] = 0x533;
keysym2uni_ext0[0x563] = 0x563;
keysym2uni_ext0[0x534] = 0x534;
keysym2uni_ext0[0x564] = 0x564;
keysym2uni_ext0[0x535] = 0x535;
keysym2uni_ext0[0x565] = 0x565;
keysym2uni_ext0[0x536] = 0x536;
keysym2uni_ext0[0x566] = 0x566;
keysym2uni_ext0[0x537] = 0x537;
keysym2uni_ext0[0x567] = 0x567;
keysym2uni_ext0[0x538] = 0x538;
keysym2uni_ext0[0x568] = 0x568;
keysym2uni_ext0[0x539] = 0x539;
keysym2uni_ext0[0x569] = 0x569;
keysym2uni_ext0[0x53a] = 0x53a;
keysym2uni_ext0[0x56a] = 0x56a;
keysym2uni_ext0[0x53b] = 0x53b;
keysym2uni_ext0[0x56b] = 0x56b;
keysym2uni_ext0[0x53c] = 0x53c;
keysym2uni_ext0[0x56c] = 0x56c;
keysym2uni_ext0[0x53d] = 0x53d;
keysym2uni_ext0[0x56d] = 0x56d;
keysym2uni_ext0[0x53e] = 0x53e;
keysym2uni_ext0[0x56e] = 0x56e;
keysym2uni_ext0[0x53f] = 0x53f;
keysym2uni_ext0[0x56f] = 0x56f;
keysym2uni_ext0[0x540] = 0x540;
keysym2uni_ext0[0x570] = 0x570;
keysym2uni_ext0[0x541] = 0x541;
keysym2uni_ext0[0x571] = 0x571;
keysym2uni_ext0[0x542] = 0x542;
keysym2uni_ext0[0x572] = 0x572;
keysym2uni_ext0[0x543] = 0x543;
keysym2uni_ext0[0x573] = 0x573;
keysym2uni_ext0[0x544] = 0x544;
keysym2uni_ext0[0x574] = 0x574;
keysym2uni_ext0[0x545] = 0x545;
keysym2uni_ext0[0x575] = 0x575;
keysym2uni_ext0[0x546] = 0x546;
keysym2uni_ext0[0x576] = 0x576;
keysym2uni_ext0[0x547] = 0x547;
keysym2uni_ext0[0x577] = 0x577;
keysym2uni_ext0[0x548] = 0x548;
keysym2uni_ext0[0x578] = 0x578;
keysym2uni_ext0[0x549] = 0x549;
keysym2uni_ext0[0x579] = 0x579;
keysym2uni_ext0[0x54a] = 0x54a;
keysym2uni_ext0[0x57a] = 0x57a;
keysym2uni_ext0[0x54b] = 0x54b;
keysym2uni_ext0[0x57b] = 0x57b;
keysym2uni_ext0[0x54c] = 0x54c;
keysym2uni_ext0[0x57c] = 0x57c;
keysym2uni_ext0[0x54d] = 0x54d;
keysym2uni_ext0[0x57d] = 0x57d;
keysym2uni_ext0[0x54e] = 0x54e;
keysym2uni_ext0[0x57e] = 0x57e;
keysym2uni_ext0[0x54f] = 0x54f;
keysym2uni_ext0[0x57f] = 0x57f;
keysym2uni_ext0[0x550] = 0x550;
keysym2uni_ext0[0x580] = 0x580;
keysym2uni_ext0[0x551] = 0x551;
keysym2uni_ext0[0x581] = 0x581;
keysym2uni_ext0[0x552] = 0x552;
keysym2uni_ext0[0x582] = 0x582;
keysym2uni_ext0[0x553] = 0x553;
keysym2uni_ext0[0x583] = 0x583;
keysym2uni_ext0[0x554] = 0x554;
keysym2uni_ext0[0x584] = 0x584;
keysym2uni_ext0[0x555] = 0x555;
keysym2uni_ext0[0x585] = 0x585;
keysym2uni_ext0[0x556] = 0x556;
keysym2uni_ext0[0x586] = 0x586;
keysym2uni_ext0[0x55a] = 0x55a;
keysym2uni_ext0[0x1b5] = 0x1b5;
keysym2uni_ext0[0x1e6] = 0x1e6;
keysym2uni_ext0[0x1d2] = 0x1d2;
keysym2uni_ext0[0x19f] = 0x19f;
keysym2uni_ext0[0x12d] = 0x12d;
keysym2uni_ext0[0x1b6] = 0x1b6;
keysym2uni_ext0[0x1e7] = 0x1e7;
keysym2uni_ext0[0x275] = 0x275;
keysym2uni_ext0[0x18f] = 0x18f;
keysym2uni_ext0[0x259] = 0x259;
keysym2uni_ext0[0x1a0] = 0x1a0;
keysym2uni_ext0[0x1a1] = 0x1a1;
keysym2uni_ext0[0x1af] = 0x1af;
keysym2uni_ext0[0x1b0] = 0x1b0;


keysym2uni_ext1[0xe02] = 0x1e02;
keysym2uni_ext1[0xe03] = 0x1e03;
keysym2uni_ext1[0xe0a] = 0x1e0a;
keysym2uni_ext1[0xe80] = 0x1e80;
keysym2uni_ext1[0xe82] = 0x1e82;
keysym2uni_ext1[0xe0b] = 0x1e0b;
keysym2uni_ext1[0xef2] = 0x1ef2;
keysym2uni_ext1[0xe1e] = 0x1e1e;
keysym2uni_ext1[0xe1f] = 0x1e1f;
keysym2uni_ext1[0xe40] = 0x1e40;
keysym2uni_ext1[0xe41] = 0x1e41;
keysym2uni_ext1[0xe56] = 0x1e56;
keysym2uni_ext1[0xe81] = 0x1e81;
keysym2uni_ext1[0xe57] = 0x1e57;
keysym2uni_ext1[0xe83] = 0x1e83;
keysym2uni_ext1[0xe60] = 0x1e60;
keysym2uni_ext1[0xef3] = 0x1ef3;
keysym2uni_ext1[0xe84] = 0x1e84;
keysym2uni_ext1[0xe85] = 0x1e85;
keysym2uni_ext1[0xe61] = 0x1e61;
keysym2uni_ext1[0xe6a] = 0x1e6a;
keysym2uni_ext1[0xe6b] = 0x1e6b;
keysym2uni_ext1[0x0d0] = 0x10d0;
keysym2uni_ext1[0x0d1] = 0x10d1;
keysym2uni_ext1[0x0d2] = 0x10d2;
keysym2uni_ext1[0x0d3] = 0x10d3;
keysym2uni_ext1[0x0d4] = 0x10d4;
keysym2uni_ext1[0x0d5] = 0x10d5;
keysym2uni_ext1[0x0d6] = 0x10d6;
keysym2uni_ext1[0x0d7] = 0x10d7;
keysym2uni_ext1[0x0d8] = 0x10d8;
keysym2uni_ext1[0x0d9] = 0x10d9;
keysym2uni_ext1[0x0da] = 0x10da;
keysym2uni_ext1[0x0db] = 0x10db;
keysym2uni_ext1[0x0dc] = 0x10dc;
keysym2uni_ext1[0x0dd] = 0x10dd;
keysym2uni_ext1[0x0de] = 0x10de;
keysym2uni_ext1[0x0df] = 0x10df;
keysym2uni_ext1[0x0e0] = 0x10e0;
keysym2uni_ext1[0x0e1] = 0x10e1;
keysym2uni_ext1[0x0e2] = 0x10e2;
keysym2uni_ext1[0x0e3] = 0x10e3;
keysym2uni_ext1[0x0e4] = 0x10e4;
keysym2uni_ext1[0x0e5] = 0x10e5;
keysym2uni_ext1[0x0e6] = 0x10e6;
keysym2uni_ext1[0x0e7] = 0x10e7;
keysym2uni_ext1[0x0e8] = 0x10e8;
keysym2uni_ext1[0x0e9] = 0x10e9;
keysym2uni_ext1[0x0ea] = 0x10ea;
keysym2uni_ext1[0x0eb] = 0x10eb;
keysym2uni_ext1[0x0ec] = 0x10ec;
keysym2uni_ext1[0x0ed] = 0x10ed;
keysym2uni_ext1[0x0ee] = 0x10ee;
keysym2uni_ext1[0x0ef] = 0x10ef;
keysym2uni_ext1[0x0f0] = 0x10f0;
keysym2uni_ext1[0x0f1] = 0x10f1;
keysym2uni_ext1[0x0f2] = 0x10f2;
keysym2uni_ext1[0x0f3] = 0x10f3;
keysym2uni_ext1[0x0f4] = 0x10f4;
keysym2uni_ext1[0x0f5] = 0x10f5;
keysym2uni_ext1[0x0f6] = 0x10f6;
keysym2uni_ext1[0xe8b] = 0x1e8b;
keysym2uni_ext1[0xe36] = 0x1e36;
keysym2uni_ext1[0xe37] = 0x1e37;
keysym2uni_ext1[0xea0] = 0x1ea0;
keysym2uni_ext1[0xea1] = 0x1ea1;
keysym2uni_ext1[0xea2] = 0x1ea2;
keysym2uni_ext1[0xea3] = 0x1ea3;
keysym2uni_ext1[0xea4] = 0x1ea4;
keysym2uni_ext1[0xea5] = 0x1ea5;
keysym2uni_ext1[0xea6] = 0x1ea6;
keysym2uni_ext1[0xea7] = 0x1ea7;
keysym2uni_ext1[0xea8] = 0x1ea8;
keysym2uni_ext1[0xea9] = 0x1ea9;
keysym2uni_ext1[0xeaa] = 0x1eaa;
keysym2uni_ext1[0xeab] = 0x1eab;
keysym2uni_ext1[0xeac] = 0x1eac;
keysym2uni_ext1[0xead] = 0x1ead;
keysym2uni_ext1[0xeae] = 0x1eae;
keysym2uni_ext1[0xeaf] = 0x1eaf;
keysym2uni_ext1[0xeb0] = 0x1eb0;
keysym2uni_ext1[0xeb1] = 0x1eb1;
keysym2uni_ext1[0xeb2] = 0x1eb2;
keysym2uni_ext1[0xeb3] = 0x1eb3;
keysym2uni_ext1[0xeb4] = 0x1eb4;
keysym2uni_ext1[0xeb5] = 0x1eb5;
keysym2uni_ext1[0xeb6] = 0x1eb6;
keysym2uni_ext1[0xeb7] = 0x1eb7;
keysym2uni_ext1[0xeb8] = 0x1eb8;
keysym2uni_ext1[0xeb9] = 0x1eb9;
keysym2uni_ext1[0xeba] = 0x1eba;
keysym2uni_ext1[0xebb] = 0x1ebb;
keysym2uni_ext1[0xebc] = 0x1ebc;
keysym2uni_ext1[0xebd] = 0x1ebd;
keysym2uni_ext1[0xebe] = 0x1ebe;
keysym2uni_ext1[0xebf] = 0x1ebf;
keysym2uni_ext1[0xec0] = 0x1ec0;
keysym2uni_ext1[0xec1] = 0x1ec1;
keysym2uni_ext1[0xec2] = 0x1ec2;
keysym2uni_ext1[0xec3] = 0x1ec3;
keysym2uni_ext1[0xec4] = 0x1ec4;
keysym2uni_ext1[0xec5] = 0x1ec5;
keysym2uni_ext1[0xec6] = 0x1ec6;
keysym2uni_ext1[0xec7] = 0x1ec7;
keysym2uni_ext1[0xec8] = 0x1ec8;
keysym2uni_ext1[0xec9] = 0x1ec9;
keysym2uni_ext1[0xeca] = 0x1eca;
keysym2uni_ext1[0xecb] = 0x1ecb;
keysym2uni_ext1[0xecc] = 0x1ecc;
keysym2uni_ext1[0xecd] = 0x1ecd;
keysym2uni_ext1[0xece] = 0x1ece;
keysym2uni_ext1[0xecf] = 0x1ecf;
keysym2uni_ext1[0xed0] = 0x1ed0;
keysym2uni_ext1[0xed1] = 0x1ed1;
keysym2uni_ext1[0xed2] = 0x1ed2;
keysym2uni_ext1[0xed3] = 0x1ed3;
keysym2uni_ext1[0xed4] = 0x1ed4;
keysym2uni_ext1[0xed5] = 0x1ed5;
keysym2uni_ext1[0xed6] = 0x1ed6;
keysym2uni_ext1[0xed7] = 0x1ed7;
keysym2uni_ext1[0xed8] = 0x1ed8;
keysym2uni_ext1[0xed9] = 0x1ed9;
keysym2uni_ext1[0xeda] = 0x1eda;
keysym2uni_ext1[0xedb] = 0x1edb;
keysym2uni_ext1[0xedc] = 0x1edc;
keysym2uni_ext1[0xedd] = 0x1edd;
keysym2uni_ext1[0xede] = 0x1ede;
keysym2uni_ext1[0xedf] = 0x1edf;
keysym2uni_ext1[0xee0] = 0x1ee0;
keysym2uni_ext1[0xee1] = 0x1ee1;
keysym2uni_ext1[0xee2] = 0x1ee2;
keysym2uni_ext1[0xee3] = 0x1ee3;
keysym2uni_ext1[0xee4] = 0x1ee4;
keysym2uni_ext1[0xee5] = 0x1ee5;
keysym2uni_ext1[0xee6] = 0x1ee6;
keysym2uni_ext1[0xee7] = 0x1ee7;
keysym2uni_ext1[0xee8] = 0x1ee8;
keysym2uni_ext1[0xee9] = 0x1ee9;
keysym2uni_ext1[0xeea] = 0x1eea;
keysym2uni_ext1[0xeeb] = 0x1eeb;
keysym2uni_ext1[0xeec] = 0x1eec;
keysym2uni_ext1[0xeed] = 0x1eed;
keysym2uni_ext1[0xeee] = 0x1eee;
keysym2uni_ext1[0xeef] = 0x1eef;
keysym2uni_ext1[0xef0] = 0x1ef0;
keysym2uni_ext1[0xef1] = 0x1ef1;
keysym2uni_ext1[0xef4] = 0x1ef4;
keysym2uni_ext1[0xef5] = 0x1ef5;
keysym2uni_ext1[0xef6] = 0x1ef6;
keysym2uni_ext1[0xef7] = 0x1ef7;
keysym2uni_ext1[0xef8] = 0x1ef8;
keysym2uni_ext1[0xef9] = 0x1ef9;


keysym2uni_ext2[0x21a] = 0x221a;
keysym2uni_ext2[0x202] = 0x2202;
keysym2uni_ext2[0x0a9] = 0x20a9;
keysym2uni_ext2[0x0a0] = 0x20a0;
keysym2uni_ext2[0x0a1] = 0x20a1;
keysym2uni_ext2[0x0a2] = 0x20a2;
keysym2uni_ext2[0x0a3] = 0x20a3;
keysym2uni_ext2[0x0a4] = 0x20a4;
keysym2uni_ext2[0x0a5] = 0x20a5;
keysym2uni_ext2[0x0a6] = 0x20a6;
keysym2uni_ext2[0x0a7] = 0x20a7;
keysym2uni_ext2[0x0a8] = 0x20a8;
keysym2uni_ext2[0x0aa] = 0x20aa;
keysym2uni_ext2[0x0ab] = 0x20ab;
keysym2uni_ext2[0x070] = 0x2070;
keysym2uni_ext2[0x074] = 0x2074;
keysym2uni_ext2[0x075] = 0x2075;
keysym2uni_ext2[0x076] = 0x2076;
keysym2uni_ext2[0x077] = 0x2077;
keysym2uni_ext2[0x078] = 0x2078;
keysym2uni_ext2[0x079] = 0x2079;
keysym2uni_ext2[0x080] = 0x2080;
keysym2uni_ext2[0x081] = 0x2081;
keysym2uni_ext2[0x082] = 0x2082;
keysym2uni_ext2[0x083] = 0x2083;
keysym2uni_ext2[0x084] = 0x2084;
keysym2uni_ext2[0x085] = 0x2085;
keysym2uni_ext2[0x086] = 0x2086;
keysym2uni_ext2[0x087] = 0x2087;
keysym2uni_ext2[0x088] = 0x2088;
keysym2uni_ext2[0x089] = 0x2089;
keysym2uni_ext2[0x205] = 0x2205;
keysym2uni_ext2[0x208] = 0x2208;
keysym2uni_ext2[0x209] = 0x2209;
keysym2uni_ext2[0x20b] = 0x220b;
keysym2uni_ext2[0x21b] = 0x221b;
keysym2uni_ext2[0x21c] = 0x221c;
keysym2uni_ext2[0x22c] = 0x222c;
keysym2uni_ext2[0x22d] = 0x222d;
keysym2uni_ext2[0x235] = 0x2235;
keysym2uni_ext2[0x248] = 0x2245;
keysym2uni_ext2[0x247] = 0x2247;
keysym2uni_ext2[0x262] = 0x2262;
keysym2uni_ext2[0x263] = 0x2263;
}
