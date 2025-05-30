/*
ShaderGlass preset crt / zfast-crt imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/crt/zfast-crt.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class CrtZfastCrtPresetDef : public PresetDef
{
public:
	CrtZfastCrtPresetDef() : PresetDef{}
	{
		Name = "zfast-crt";
		Category = "crt";
	}

	virtual void Build() {
         	ShaderDefs.push_back(CrtShadersZfast_crtZfast_crt_finemaskShaderDef()
.Param("filter_linear", "true")
.Param("scale_type", "viewport"));
	}
};
}
