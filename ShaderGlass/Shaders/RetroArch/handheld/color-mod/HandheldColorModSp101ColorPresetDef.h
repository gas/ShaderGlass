/*
ShaderGlass preset handheld/color-mod / sp101-color imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/handheld/color-mod/sp101-color.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class HandheldColorModSp101ColorPresetDef : public PresetDef
{
public:
	HandheldColorModSp101ColorPresetDef() : PresetDef{}
	{
		Name = "sp101-color";
		Category = "handheld/color-mod";
	}

	virtual void Build() {
         	ShaderDefs.push_back(ReshadeShadersLUTMultiLUTShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
         	ShaderDefs.push_back(HandheldShadersColorSp101ColorShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
            TextureDefs.push_back(ReshadeShadersLUT64TextureDef()
.Param("linear", "true")
.Param("name", "SamplerLUT1"));
            TextureDefs.push_back(HandheldShadersColorLutSp101GreyTextureDef()
.Param("linear", "true")
.Param("name", "SamplerLUT2"));
	}
};
}
