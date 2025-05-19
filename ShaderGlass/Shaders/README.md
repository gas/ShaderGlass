# Shader Definitions (`/ShaderGlass/Shaders/`)

This directory contains the pre-converted shader definitions used by ShaderGlass. These are primarily C++ header files (`.h`) that embed shader bytecode and metadata, allowing them to be compiled directly into the application.

## Overview

ShaderGlass utilizes a system where shaders, originally in Slang (a language similar to GLSL), are processed by tools like `glslang` and `SPIRV-Cross` (found in the `/External` directory) and then converted into C++ header definitions by the `ShaderGen` tool. This directory stores the output of that generation process.

The main purpose of these files is to provide the ShaderGlass application with readily available shader programs without needing to parse and compile original `.slang` or `.slangp` files at runtime for the built-in library, although ShaderGlass also supports on-the-fly import of external `.slangp`/`.slang` shaders.

Each `.h` file in this directory and its subdirectories typically defines:
-   Bytecode for vertex and pixel shaders.
-   Shader parameters (uniforms), including their names, default values, and sometimes min/max/step values.
-   Texture sampler information.
-   Metadata about the shader, such as its name, category, and any specific preset parameters.

## Key Files and Subdirectories

* **`PassthroughShaderDef.h`**: Defines a basic passthrough shader, likely used when no effect is selected or as a foundational pass.
* **`PreprocessShaderDef.h`**: Defines a preprocessing shader. This shader is likely used to prepare the input texture (e.g., scaling, cropping, handling coordinate adjustments) before it's fed into the main effect shader chain.
* **`PassthroughPresetDef.h`**: Defines a simple preset that likely uses the `PassthroughShaderDef.h`.
* **`RetroArch/`**: This is a major subdirectory containing a large collection of shaders sourced from the [RetroArch shader repository](https://github.com/libretro/slang-shaders). These are organized into further subcategories (e.g., `crt`, `handheld`, `ntsc`, `anti-aliasing`, `blur`, etc.) reflecting their original structure. Each file within is a C++ header defining a specific shader or preset from that library.
    * Example: `RetroArch/crt/shaders/crt-geom/CrtShadersCrtGeomCrtGeomShaderDef.h` would define the `crt-geom` shader.
* **`RetroArch.h`**: This header file likely includes all the individual `PresetDef.h` files from the `RetroArch/` subdirectories to provide a single point of access to the entire built-in RetroArch shader library for the application.

The files in this directory are crucial for populating ShaderGlass's extensive built-in shader library. When adding or modifying shaders for built-in use, the `ShaderGen` tool would be used to regenerate these header files from their original `.slang`/`.slangp` sources.
