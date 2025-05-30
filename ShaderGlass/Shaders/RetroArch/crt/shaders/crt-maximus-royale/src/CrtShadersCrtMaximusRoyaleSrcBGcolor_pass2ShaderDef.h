/*
ShaderGlass shader crt/shaders/crt-maximus-royale/src\BGcolor_pass2 imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/crt/shaders/crt-maximus-royale/src/BGcolor_pass2.slang
See original file for full credits and usage license with excerpts below. 
This file is auto-generated, do not modify directly.

/////////////////////////////  GPL LICENSE NOTICE  /////////////////////////////
//  crt-maximus-royale: A fully customizable extension for crt-royale shader,
//  inside a TV / MONITOR BOX with backlight and some other cool stuff.
//  Copyright (C) 2022 DigiDwrf
//
//  This program is free software; you can redistribute it and/or modify it
//  under the terms of the GNU General Public License as published by the Free
//  Software Foundation; either version 2 of the License, or any later version.
//
//  This program is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//  You should have received a copy of the GNU General Public License along with
//  this program; if not, write to the Free Software Foundation, Inc., 59 Temple
//  Place, Suite 330, Boston, MA 02111-1307 USA

*/

#pragma once

namespace RetroArchCrtShadersCrtMaximusRoyaleSrcBGcolor_pass2ShaderDefs
{
static const BYTE sVertexByteCode[] =
{
68,88,66,67,110,239,
1,38,44,138,120,137,
121,214,212,137,93,170,
129,5,1,0,0,0,
140,3,0,0,5,0,
0,0,52,0,0,0,
60,1,0,0,136,1,
0,0,224,1,0,0,
240,2,0,0,82,68,
69,70,0,1,0,0,
1,0,0,0,96,0,
0,0,1,0,0,0,
60,0,0,0,0,5,
254,255,0,129,0,0,
216,0,0,0,82,68,
49,49,60,0,0,0,
24,0,0,0,32,0,
0,0,40,0,0,0,
36,0,0,0,12,0,
0,0,0,0,0,0,
92,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
1,0,0,0,1,0,
0,0,85,66,79,0,
92,0,0,0,1,0,
0,0,120,0,0,0,
64,0,0,0,0,0,
0,0,0,0,0,0,
160,0,0,0,0,0,
0,0,64,0,0,0,
2,0,0,0,180,0,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,103,108,
111,98,97,108,95,77,
86,80,0,102,108,111,
97,116,52,120,52,0,
2,0,3,0,4,0,
4,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,171,0,0,0,
77,105,99,114,111,115,
111,102,116,32,40,82,
41,32,72,76,83,76,
32,83,104,97,100,101,
114,32,67,111,109,112,
105,108,101,114,32,49,
48,46,49,0,73,83,
71,78,68,0,0,0,
2,0,0,0,8,0,
0,0,56,0,0,0,
0,0,0,0,0,0,
0,0,3,0,0,0,
0,0,0,0,15,15,
0,0,56,0,0,0,
1,0,0,0,0,0,
0,0,3,0,0,0,
1,0,0,0,3,3,
0,0,84,69,88,67,
79,79,82,68,0,171,
171,171,79,83,71,78,
80,0,0,0,2,0,
0,0,8,0,0,0,
56,0,0,0,0,0,
0,0,0,0,0,0,
3,0,0,0,0,0,
0,0,3,12,0,0,
65,0,0,0,0,0,
0,0,1,0,0,0,
3,0,0,0,1,0,
0,0,15,0,0,0,
84,69,88,67,79,79,
82,68,0,83,86,95,
80,111,115,105,116,105,
111,110,0,171,171,171,
83,72,69,88,8,1,
0,0,80,0,1,0,
66,0,0,0,106,8,
0,1,89,0,0,4,
70,142,32,0,0,0,
0,0,4,0,0,0,
95,0,0,3,242,16,
16,0,0,0,0,0,
95,0,0,3,50,16,
16,0,1,0,0,0,
101,0,0,3,50,32,
16,0,0,0,0,0,
103,0,0,4,242,32,
16,0,1,0,0,0,
1,0,0,0,104,0,
0,2,1,0,0,0,
54,0,0,5,50,32,
16,0,0,0,0,0,
70,16,16,0,1,0,
0,0,56,0,0,8,
242,0,16,0,0,0,
0,0,86,21,16,0,
0,0,0,0,70,142,
32,0,0,0,0,0,
1,0,0,0,50,0,
0,10,242,0,16,0,
0,0,0,0,6,16,
16,0,0,0,0,0,
70,142,32,0,0,0,
0,0,0,0,0,0,
70,14,16,0,0,0,
0,0,50,0,0,10,
242,0,16,0,0,0,
0,0,166,26,16,0,
0,0,0,0,70,142,
32,0,0,0,0,0,
2,0,0,0,70,14,
16,0,0,0,0,0,
50,0,0,10,242,32,
16,0,1,0,0,0,
246,31,16,0,0,0,
0,0,70,142,32,0,
0,0,0,0,3,0,
0,0,70,14,16,0,
0,0,0,0,62,0,
0,1,83,84,65,84,
148,0,0,0,6,0,
0,0,1,0,0,0,
0,0,0,0,4,0,
0,0,4,0,0,0,
0,0,0,0,0,0,
0,0,1,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,1,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0
};


static const BYTE sFragmentByteCode[] =
{
68,88,66,67,84,36,
186,105,104,205,121,201,
192,230,116,148,13,22,
207,251,1,0,0,0,
220,4,0,0,5,0,
0,0,52,0,0,0,
208,1,0,0,4,2,
0,0,56,2,0,0,
64,4,0,0,82,68,
69,70,148,1,0,0,
1,0,0,0,188,0,
0,0,3,0,0,0,
60,0,0,0,0,5,
255,255,0,129,0,0,
107,1,0,0,82,68,
49,49,60,0,0,0,
24,0,0,0,32,0,
0,0,40,0,0,0,
36,0,0,0,12,0,
0,0,0,0,0,0,
156,0,0,0,3,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,2,0,0,0,
1,0,0,0,1,0,
0,0,173,0,0,0,
2,0,0,0,5,0,
0,0,4,0,0,0,
255,255,255,255,2,0,
0,0,1,0,0,0,
13,0,0,0,181,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
1,0,0,0,1,0,
0,0,0,0,0,0,
95,66,71,80,65,83,
83,49,95,115,97,109,
112,108,101,114,0,66,
71,80,65,83,83,49,
0,80,117,115,104,0,
171,171,181,0,0,0,
2,0,0,0,212,0,
0,0,16,0,0,0,
0,0,0,0,0,0,
0,0,36,1,0,0,
0,0,0,0,4,0,
0,0,2,0,0,0,
56,1,0,0,0,0,
0,0,255,255,255,255,
0,0,0,0,255,255,
255,255,0,0,0,0,
92,1,0,0,4,0,
0,0,4,0,0,0,
2,0,0,0,56,1,
0,0,0,0,0,0,
255,255,255,255,0,0,
0,0,255,255,255,255,
0,0,0,0,112,97,
114,97,109,115,95,98,
103,77,111,100,101,0,
102,108,111,97,116,0,
0,0,3,0,1,0,
1,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,50,1,0,0,
112,97,114,97,109,115,
95,108,101,100,77,111,
100,101,0,77,105,99,
114,111,115,111,102,116,
32,40,82,41,32,72,
76,83,76,32,83,104,
97,100,101,114,32,67,
111,109,112,105,108,101,
114,32,49,48,46,49,
0,171,73,83,71,78,
44,0,0,0,1,0,
0,0,8,0,0,0,
32,0,0,0,0,0,
0,0,0,0,0,0,
3,0,0,0,0,0,
0,0,3,0,0,0,
84,69,88,67,79,79,
82,68,0,171,171,171,
79,83,71,78,44,0,
0,0,1,0,0,0,
8,0,0,0,32,0,
0,0,0,0,0,0,
0,0,0,0,3,0,
0,0,0,0,0,0,
15,0,0,0,83,86,
95,84,97,114,103,101,
116,0,171,171,83,72,
69,88,0,2,0,0,
80,0,0,0,128,0,
0,0,106,8,0,1,
89,0,0,4,70,142,
32,0,1,0,0,0,
1,0,0,0,90,0,
0,3,0,96,16,0,
2,0,0,0,88,24,
0,4,0,112,16,0,
2,0,0,0,85,85,
0,0,101,0,0,3,
242,32,16,0,0,0,
0,0,104,0,0,2,
3,0,0,0,29,0,
0,8,18,0,16,0,
0,0,0,0,1,64,
0,0,0,0,128,63,
10,128,32,0,1,0,
0,0,0,0,0,0,
24,0,0,8,34,0,
16,0,0,0,0,0,
1,64,0,0,0,0,
64,64,26,128,32,0,
1,0,0,0,0,0,
0,0,55,0,0,9,
18,0,16,0,0,0,
0,0,10,0,16,0,
0,0,0,0,26,0,
16,0,0,0,0,0,
1,64,0,0,255,255,
255,255,31,0,4,3,
10,0,16,0,0,0,
0,0,54,0,0,5,
18,0,16,0,0,0,
0,0,1,64,0,0,
0,0,0,0,54,0,
0,8,114,0,16,0,
1,0,0,0,2,64,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
54,0,0,5,34,0,
16,0,0,0,0,0,
1,64,0,0,10,215,
163,60,48,0,0,1,
49,0,0,7,66,0,
16,0,0,0,0,0,
1,64,0,0,0,0,
128,63,26,0,16,0,
0,0,0,0,3,0,
4,3,42,0,16,0,
0,0,0,0,69,0,
0,139,194,0,0,128,
67,85,21,0,114,0,
16,0,2,0,0,0,
70,0,16,0,0,0,
0,0,70,126,16,0,
2,0,0,0,0,96,
16,0,2,0,0,0,
0,0,0,7,114,0,
16,0,1,0,0,0,
70,2,16,0,1,0,
0,0,70,2,16,0,
2,0,0,0,0,0,
0,7,34,0,16,0,
0,0,0,0,26,0,
16,0,0,0,0,0,
1,64,0,0,10,215,
163,60,22,0,0,1,
18,0,0,1,54,0,
0,8,114,0,16,0,
1,0,0,0,2,64,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
21,0,0,1,56,0,
0,10,114,32,16,0,
0,0,0,0,70,2,
16,0,1,0,0,0,
2,64,0,0,10,215,
163,60,10,215,163,60,
10,215,163,60,0,0,
0,0,54,0,0,5,
130,32,16,0,0,0,
0,0,1,64,0,0,
0,0,128,63,62,0,
0,1,83,84,65,84,
148,0,0,0,20,0,
0,0,3,0,0,0,
0,0,0,0,1,0,
0,0,6,0,0,0,
0,0,0,0,0,0,
0,0,2,0,0,0,
2,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
1,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,5,0,0,0,
1,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0,0,0,0,0,
0,0
};


static const uint32_t sVertexHash[] = 
{
0x867eaf62,0x618075d0,0x1974b658,0x602f8166,0x2859c27e,0x3630646c,
0x4f01e720,0x733790ea
};


static const uint32_t sFragmentHash[] =
{
0x4fc2f720,0xda2be5e1,0xf37832de,0x48a61eb0,0xf207bf95,0xeb5746ba,
0x672693dc,0x2b6a8b68
};

}

namespace RetroArch
{
class CrtShadersCrtMaximusRoyaleSrcBGcolor_pass2ShaderDef : public ShaderDef
{
public:
	CrtShadersCrtMaximusRoyaleSrcBGcolor_pass2ShaderDef() : ShaderDef{}
	{
		Name = "BGcolor_pass2";
		VertexByteCode = RetroArchCrtShadersCrtMaximusRoyaleSrcBGcolor_pass2ShaderDefs::sVertexByteCode;
		VertexLength = sizeof(RetroArchCrtShadersCrtMaximusRoyaleSrcBGcolor_pass2ShaderDefs::sVertexByteCode);
		VertexHash = RetroArchCrtShadersCrtMaximusRoyaleSrcBGcolor_pass2ShaderDefs::sVertexHash;
		FragmentByteCode = RetroArchCrtShadersCrtMaximusRoyaleSrcBGcolor_pass2ShaderDefs::sFragmentByteCode;
		FragmentLength = sizeof(RetroArchCrtShadersCrtMaximusRoyaleSrcBGcolor_pass2ShaderDefs::sFragmentByteCode);
		FragmentHash = RetroArchCrtShadersCrtMaximusRoyaleSrcBGcolor_pass2ShaderDefs::sFragmentHash;
		Format = "";
		Params.push_back(ShaderParam("MVP", 0, 0, 64, 0.000000f, 0.000000f, 0.000000f, 0.000000f, ""));
		Params.push_back(ShaderParam("bgMode", -1, 0, 4, 0.000000f, 3.000000f, 0.000000f, 1.000000f, "BG Mode"));
		Params.push_back(ShaderParam("ledMode", -1, 4, 4, 0.000000f, 3.000000f, 0.000000f, 1.000000f, "Rear TV LED Mode"));
		Samplers.push_back(ShaderSampler("BGPASS1", 2));
/*
VertexSource = %*VERTEX_SOURCE*%;
*/
/*
FragmentSource = %*FRAGMENT_SOURCE*%;
*/
	}
};
}
