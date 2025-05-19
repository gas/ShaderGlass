# glslang Headers (`/ShaderGen/include/glslang/`)

This directory contains the public C and C++ header files for the **glslang** library. `glslang` is an official Khronos reference compiler front-end for the GLSL (OpenGL Shading Language), ESSL (OpenGL ES Shading Language), and by extension, Slang (RetroArch's GLSL-based shading language).

## Overview

Within the `ShaderGen` tool of the ShaderGlass project, these `glslang` headers provide the API necessary to:
1.  Parse and validate Slang/GLSL shader source code.
2.  Compile this source code into SPIR-V (Standard Portable Intermediate Representation), an intermediate binary format for shaders.

This SPIR-V output is a crucial intermediate step before the code is further processed (typically by `SPIRV-Cross`) to generate HLSL suitable for ShaderGlass's DirectX 11 backend. The `ShaderGen` tool uses these headers to invoke `glslang`'s functionalities programmatically.

## Key Subdirectories and Headers

The headers are organized into several subdirectories, providing different levels of API access and internal definitions:

* **`Public/`**: Contains the main public C++ API headers intended for direct use by applications like `ShaderGen`.
    * `ShaderLang.h`: Defines core C++ classes like `TShader` (for individual shader stages like vertex, fragment) and `TProgram` (for linking shader stages) used to manage the compilation process. This is a primary interface for `ShaderGen`.
    * `ResourceLimits.h`: Defines structures (`TBuiltInResource`) for specifying compiler resource limits (e.g., maximum number of uniforms, texture image units). `ShaderGen` uses this to configure the `glslang` compiler.
    * `resource_limits_c.h`: C-style definitions for resource limits.

* **`Include/`**: Contains lower-level C API headers and common definitions used across the `glslang` library.
    * `glslang_c_interface.h`: Defines the C interface for `glslang`, offering an alternative way to interact with the compiler.
    * `intermediate.h`: Declarations for `glslang`'s internal intermediate representation (AST - Abstract Syntax Tree) nodes and traversal mechanisms.
    * `Types.h`, `BaseTypes.h`: Define fundamental data types, enums (like `EShLanguage` for shader stages), and other common definitions used by `glslang`.
    * `PoolAlloc.h`: Manages memory allocation through pools for compiler efficiency.
    * `InfoSink.h`: Used for routing informational, warning, and error messages from the compiler.

* **`MachineIndependent/`**: Contains headers for platform-agnostic parts of the compiler, such as the parser, preprocessor, and symbol table logic.
    * `ParseHelper.h`: Provides helper classes for parsing shader source code.
    * `SymbolTable.h`: Defines how symbols (variables, functions, types) are managed during compilation.
    * `preprocessor/PpContext.h`: Manages the context for the GLSL preprocessor.

* **`OSDependent/`**: Includes platform-specific configurations, primarily for threading or other OS-level interactions.

* **`HLSL/`**: Contains headers specific to `glslang`'s capabilities for parsing HLSL source code, although ShaderGlass primarily uses `glslang` for Slang/GLSL input.

These headers are part of the `glslang` SDK and are used "as-is" by `ShaderGen` to leverage `glslang`'s compilation services.
