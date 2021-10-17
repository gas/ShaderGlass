/*
ShaderGlass preset dithering / sgenpt-mix imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/master/dithering/sgenpt-mix.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class DitheringSgenptMixPresetDef : public PresetDef
{
public:
	DitheringSgenptMixPresetDef() : PresetDef{}
	{
		Name = "sgenpt-mix";
		Category = "dithering";
	}

	virtual void Build() {
         	ShaderDefs.push_back(DitheringShadersSgenptMixShaderDef()
.Param("filter_linear", "false")
.Param("scale", "1.0")
.Param("scale_type", "source"));
	}
};
}
