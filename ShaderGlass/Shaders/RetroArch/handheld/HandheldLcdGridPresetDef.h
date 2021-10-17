/*
ShaderGlass preset handheld / lcd-grid imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/master/handheld/lcd-grid.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class HandheldLcdGridPresetDef : public PresetDef
{
public:
	HandheldLcdGridPresetDef() : PresetDef{}
	{
		Name = "lcd-grid";
		Category = "handheld";
	}

	virtual void Build() {
         	ShaderDefs.push_back(HandheldShadersLcdCgwgLcdGridShaderDef()
.Param("filter_linear", "false"));
	}
};
}
