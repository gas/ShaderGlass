# glslang Headers (`/ShaderGC/include/glslang/`)

This directory contains the public C and C++ header files for the **glslang** library, which is an official Khronos reference compiler for GLSL/ESSL (OpenGL Shading Language / OpenGL ES Shading Language) and Slang.

## Overview

In the context of ShaderGlass, the `glslang` library is a critical component of the `ShaderGC` (Shader Graphics Compiler) module. Its primary role is to:
1.  Parse and validate Slang shader source code (which is based on GLSL).
2.  Compile this source code into SPIR-V (Standard Portable Intermediate Representation), an intermediate binary format for shaders.

This SPIR-V output is then typically passed to `SPIRV-Cross` for further transpilation into HLSL, which is the target shader language for ShaderGlass's DirectX 11 backend.

## Key Subdirectories and Headers

The headers are organized into several subdirectories:

* **`Public/`**: Contains the main public C++ API headers.
    * `ShaderLang.h`: Defines the core `TShader` and `TProgram` classes used to manage shader compilation and linking stages within glslang. This is likely the primary interface used by `ShaderGC/GLSL.cpp`.
    * `ResourceLimits.h`: Defines structures for specifying resource limits for the compiler (e.g., max uniforms, max texture units).
    * `resource_limits_c.h`: C-style definitions for resource limits, potentially for C language bindings or simpler interop.

* **`Include/`**: Contains lower-level C API headers and common definitions.
    * `glslang_c_interface.h`: Defines the C interface for glslang, providing functions for shader compilation and reflection from C code.
    * `intermediate.h`: Declarations for the internal intermediate representation (AST - Abstract Syntax Tree) that glslang builds from shader source code.
    * `Types.h`, `BaseTypes.h`: Define fundamental types and enums used throughout the glslang library.

* **`MachineIndependent/`**: Contains headers for parts of the compiler that are not platform-specific, including parsing logic, symbol table management, and preprocessor components.
    * `ParseHelper.h`: Likely contains helper classes and functions for the parsing process.
    * `SymbolTable.h`: Manages symbols (variables, functions, etc.) encountered during parsing.
    * `preprocessor/PpContext.h`: Context for the preprocessor.

* **`OSDependent/`**: Contains platform-specific includes, though for ShaderGlass, the primary interaction is likely through the more abstract public APIs.

* **`HLSL/`**: Contains headers related to HLSL-specific parsing capabilities within glslang (glslang can also directly target SPIR-V from HLSL source, though ShaderGlass primarily uses it for Slang/GLSL to SPIR-V).

These headers provide the necessary declarations for the `ShaderGC` module to invoke `glslang` programmatically, feed it shader source code, and retrieve the resulting SPIR-V for the next stage of the pipeline.
