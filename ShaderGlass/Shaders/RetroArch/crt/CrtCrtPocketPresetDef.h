/*
ShaderGlass preset crt / crt-pocket imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/crt/crt-pocket.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class CrtCrtPocketPresetDef : public PresetDef
{
public:
	CrtCrtPocketPresetDef() : PresetDef{}
	{
		Name = "crt-pocket";
		Category = "crt";
	}

	virtual void Build() {
         	ShaderDefs.push_back(CrtShadersCrtPocketShaderDef()
.Param("scale_type", "viewport"));
	}
};
}
