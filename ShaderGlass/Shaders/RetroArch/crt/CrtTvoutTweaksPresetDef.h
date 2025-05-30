/*
ShaderGlass preset crt / tvout-tweaks imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/crt/tvout-tweaks.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class CrtTvoutTweaksPresetDef : public PresetDef
{
public:
	CrtTvoutTweaksPresetDef() : PresetDef{}
	{
		Name = "tvout-tweaks";
		Category = "crt";
	}

	virtual void Build() {
         	ShaderDefs.push_back(CrtShadersTvoutTweaksShaderDef()
.Param("filter_linear", "false")
.Param("scale_type", "viewport"));
	}
};
}
