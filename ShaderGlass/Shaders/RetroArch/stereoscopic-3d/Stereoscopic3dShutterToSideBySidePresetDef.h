/*
ShaderGlass preset stereoscopic-3d / shutter-to-side-by-side imported from RetroArch:
https://github.com/libretro/slang-shaders/blob/25311dc03332d9ef2dff8d9d06c611d828028fac/stereoscopic-3d/shutter-to-side-by-side.slangp
See original file for credits and usage license. 
This file is auto-generated, do not modify directly.
*/

#pragma once

namespace RetroArch
{
class Stereoscopic3dShutterToSideBySidePresetDef : public PresetDef
{
public:
	Stereoscopic3dShutterToSideBySidePresetDef() : PresetDef{}
	{
		Name = "shutter-to-side-by-side";
		Category = "stereoscopic-3d";
	}

	virtual void Build() {
         	ShaderDefs.push_back(Stereoscopic3dShadersShutterToSideBySideShaderDef()
.Param("scale_type", "source"));
	}
};
}
