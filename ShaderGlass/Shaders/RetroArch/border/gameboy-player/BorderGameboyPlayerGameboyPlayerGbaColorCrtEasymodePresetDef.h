/*
ShaderGlass preset border/gameboy-player / gameboy-player-gba-color+crt-easymode imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/border/gameboy-player/gameboy-player-gba-color+crt-easymode.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class BorderGameboyPlayerGameboyPlayerGbaColorCrtEasymodePresetDef : public PresetDef
{
public:
	BorderGameboyPlayerGameboyPlayerGbaColorCrtEasymodePresetDef() : PresetDef{}
	{
		Name = "gameboy-player-gba-color+crt-easymode";
		Category = "border/gameboy-player";
	}

	virtual void Build() {
         	ShaderDefs.push_back(HandheldShadersColorGbaColorShaderDef()
.Param("scale", "1.000")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(BorderShadersImgborderGbpShaderDef()
.Param("scale_type_x", "absolute")
.Param("scale_type_y", "absolute")
.Param("scale_x", "608")
.Param("scale_y", "448"));
         	ShaderDefs.push_back(CrtShadersCrtEasymodeShaderDef());
            TextureDefs.push_back(BorderGameboyPlayerGameboyPlayerTextureDef()
.Param("name", "BORDER"));
            OverrideParam("box_scale", (float)2.000000);
            OverrideParam("in_res_x", (float)240.000000);
            OverrideParam("in_res_y", (float)160.000000);
            OverrideParam("location", (float)0.500000);
	}
};
}
