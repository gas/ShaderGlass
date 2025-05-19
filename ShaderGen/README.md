# Shader Generation Tool (`/ShaderGen/`)

This directory contains the source code for **ShaderGen**, a command-line utility specifically built for the ShaderGlass project. Its primary function is to convert Slang shader files (`.slang` and preset `.slangp` files) and associated texture assets into C++ header files (`.h`). These generated headers can then be directly compiled into the main ShaderGlass application, allowing for a built-in library of pre-processed shaders.

## Overview

ShaderGen automates the complex pipeline required to transform human-readable Slang shaders into a format that DirectX 11 (ShaderGlass's rendering backend) can consume efficiently. This process involves several steps, utilizing external libraries like `glslang` and `SPIRV-Cross`.

The overall conversion process managed by `ShaderGen` is as follows:
1.  **Slang/GLSL to SPIR-V:** `glslang` is used to parse the input Slang/GLSL shader source and compile it into SPIR-V (Standard Portable Intermediate Representation) bytecode.
2.  **SPIR-V to HLSL:** `SPIRV-Cross` takes the SPIR-V bytecode and transpiles it into HLSL (High-Level Shading Language) source code. During this step, it also reflects on the SPIR-V to extract metadata about shader parameters (uniforms), textures, and samplers.
3.  **HLSL to Bytecode:** The generated HLSL source code is then compiled into DirectX 11 shader bytecode using the Direct3D shader compiler (`fxc.exe` or the `D3DCompile` API).
4.  **Header File Generation:** `ShaderGen` takes the compiled bytecode, along with the extracted metadata (parameters, texture paths, etc.), and formats it into C++ structures (like `ShaderDef`, `PresetDef`, `TextureDef` as defined in `/ShaderGC/`) within a `.h` file. Texture files are also converted into embeddable C++ byte arrays.

This pre-conversion process means that ShaderGlass can load its extensive built-in shader library quickly at startup without needing to perform these compilation steps at runtime.

## Key Files and Components

* **`ShaderGen.h` / `ShaderGen.cpp`**
    * **Class/Namespace:** `ShaderGen` (the main logic is likely within the `main` function or helper functions in `ShaderGen.cpp`).
    * **Purpose:** Implements the command-line interface and orchestrates the shader-to-header conversion pipeline.
    * **Key Responsibilities & Functionality:**
        * Parses command-line arguments to determine input shader/preset files/directories and output locations.
        * Iterates through specified shader files and preset collections (like the RetroArch library).
        * For each shader:
            * Invokes the `ShaderGC` library's compilation capabilities (or a similar internal pipeline leveraging `glslang`, `SPIRV-Cross`, and HLSL compilation logic, as seen in the namespaces `GLSL`, `SPIRV`, `HLSL` used in `ShaderGen.cpp`).
            * Reads texture files specified in presets and converts them into C++ byte arrays.
            * Generates C++ header file content, defining `ShaderDef`, `PresetDef`, and `TextureDef` structures with the compiled bytecode and metadata.
        * Manages output file paths and organization, often mirroring the source shader directory structure (e.g., creating corresponding `.h` files in an output `Shaders/` directory).
        * The `main` function in `ShaderGen.cpp` handles argument parsing (e.g., `-shaders <path>`, `-presets <path>`, `-textures <path>`, `-output <path>`) and drives the conversion for entire directories of shaders and presets.
        * Functions like `WritePreset()`, `WriteShader()`, and `WriteTexture()` are responsible for formatting and writing the C++ header content for each type of definition.

* **`framework.h`, `pch.h`, `pch.cpp`**
    * **Purpose:** Standard precompiled header and framework include files for the `ShaderGen` command-line tool project.

* **`include/` (subdirectory):**
    * **Purpose:** Contains header files for the external libraries (`glslang`, `SPIRV-Cross`) required by `ShaderGen` to perform its compilation tasks. (See `ShaderGen/include/README.md` for more details).

`ShaderGen` is a developer tool essential for maintaining and updating the built-in shader library of ShaderGlass.
