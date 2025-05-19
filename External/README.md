# External Libraries (`/External/`)

This directory houses third-party libraries that ShaderGlass depends on, primarily for shader compilation and cross-compilation. These libraries are not part of the core ShaderGlass codebase but are essential for its shader processing pipeline, particularly for handling RetroArch's Slang shaders and converting them into a format usable by DirectX 11.

## Overview

ShaderGlass aims to support a wide variety of shaders, including those from the RetroArch project which are written in the Slang shading language. To make these shaders (and other GLSL-based shaders) compatible with its DirectX 11 backend, ShaderGlass utilizes specialized compiler and transpiler tools. The source code or pre-built components for these tools are located here.

## Key Subdirectories and Libraries

* **`/External/glslang/`**
    * **Library:** glslang
    * **Purpose:** `glslang` is an official Khronos tool used for validating and translating GLSL/ESSL (OpenGL Shading Language / OpenGL ES Shading Language) and Slang shaders into SPIR-V (Standard Portable Intermediate Representation).
    * **Role in ShaderGlass:** When ShaderGlass imports custom `.slang` shaders or when the `ShaderGen` tool processes shaders for embedding, `glslang` is the first step in the compilation chain. It parses the Slang/GLSL source and converts it to SPIR-V bytecode.
    * **Contents:** This directory contains the source code and build files for the `glslang` library (e.g., `CMakeSettings.json`, and numerous headers under `include/glslang/` such as `ShaderLang.h` and `spirv.hpp`).

* **`/External/SPIRV-Cross/`**
    * **Library:** SPIRV-Cross
    * **Purpose:** `SPIRV-Cross` is a Khronos tool for parsing and converting SPIR-V bytecode into other shader languages, such as GLSL, HLSL, and MSL (Metal Shading Language).
    * **Role in ShaderGlass:** After `glslang` produces SPIR-V, `SPIRV-Cross` is used to transpile this SPIR-V bytecode into HLSL (High-Level Shading Language), which is the shading language used by DirectX 11, ShaderGlass's rendering backend.
    * **Contents:** This directory contains the source code and build files for the `SPIRV-Cross` library (e.g., `CMakeSettings.json`, and headers like `spirv_hlsl.hpp` and `spirv_cross.hpp`).

These external tools are fundamental to ShaderGlass's ability to handle and utilize a broad range of shader effects from the RetroArch ecosystem and custom user shaders by converting them to a DirectX 11 compatible format. The `ShaderGC` (Shader Graphics Compiler) module within ShaderGlass wraps the functionality of these libraries.
