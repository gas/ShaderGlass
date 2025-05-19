# ShaderGlass Core (`ShaderGlass/`)

This directory contains the core application logic for ShaderGlass. It's responsible for managing the main application window, handling user input, orchestrating screen/window capture, processing and rendering shaders, and managing user settings and profiles.

## Overview

The `ShaderGlass/` directory houses the C++ classes that form the backbone of the application. These classes work together to:
- Create and manage the main application window and its UI elements (menus, dialogs).
- Interface with the `CaptureManager` to obtain image data from the screen, specific windows, or image files.
- Utilize the `ShaderGlass` class (a central component also within this directory, distinct from the overall project name) to apply selected shader effects to the captured image.
- Handle shader preset definitions (`Preset`, `ShaderPass`), parameter adjustments (`ParamsWindow`), and shader selection (`BrowserWindow`).
- Manage application settings, profiles, and various utility functions.

## Key Files and Classes

Below is a breakdown of important files and the primary classes they define or use within this directory:

* **`ShaderGlass.h` / `ShaderGlass.cpp`**
    * **Class:** `ShaderGlass`
    * **Purpose:** This is a central engine class responsible for the DirectX 11 setup, shader processing pipeline, and rendering the final image with effects. It manages DirectX device contexts, swap chains, render targets, and the application of shader passes.
    * **Key Responsibilities & Methods:**
        * `Initialize()`: Sets up the DirectX device, swap chain, and initial rendering states using the provided output window, capture details, and D3D device/context.
        * `Process()`: Takes an input texture (the captured frame) and frame ticks, applies the currently selected shader preset and its parameters, and presents the frame. This is the core of the rendering loop.
        * `SetInputScale()`, `SetOutputScale()`, `SetOutputFlip()`: Adjust scaling and flipping parameters for the input and output textures.
        * `SetShaderPreset()`: Changes the active shader preset and applies new parameters. This involves destroying old shader resources and rebuilding new ones.
        * `Params()`, `UpdateParams()`, `ResetParams()`: Manage shader parameters, allowing them to be retrieved, updated, or reset to default values.
        * `GrabOutput()`: Captures the current rendered output as a texture, used for snapshots.
        * Internal methods for managing DirectX resources: `TryResizeSwapChain()`, `DestroyShaders()`, `DestroyPasses()`, `DestroyTargets()`, `RebuildShaders()`, `PresentFrame()`.

* **`ShaderWindow.h` / `ShaderWindow.cpp`**
    * **Class:** `ShaderWindow`
    * **Purpose:** Manages the main application window (HWND), its message loop (WndProc), menus, hotkeys, and user interactions. It orchestrates the `CaptureManager` and `ShaderGlass` engine.
    * **Key Responsibilities & Methods:**
        * `Create()`: Initializes and creates the main application window.
        * `Start()`: Begins the capture and rendering process, often called after initialization or when resuming from a paused state. It also handles command-line arguments.
        * `Stop()`: Pauses or stops the capture and rendering session.
        * `WndProc()`: The window procedure that handles messages like `WM_COMMAND` (for menu actions, hotkeys), `WM_SIZE`, `WM_DESTROY`, etc..
        * Menu building functions: `BuildProgramMenu()`, `BuildInputMenu()`, `BuildOutputMenu()`, `BuildShaderMenu()` dynamically create and update the application's menu structure.
        * Profile and settings management: `LoadProfile()`, `SaveProfile()`, `ImportShader()`, registry interactions for saving states (e.g., hotkey state, window position).
        * UI updates: `UpdateWindowState()`, `UpdateTitle()`, `SetTransparent()`, `ToggleBorderless()`.

* **`CaptureManager.h` / `CaptureManager.cpp`**
    * **Class:** `CaptureManager`
    * **Purpose:** Manages the overall capture process. It initializes the D3D device, creates and manages `CaptureSession` objects, and interfaces with the `ShaderGlass` rendering engine.
    * **Key Responsibilities & Methods:**
        * `Initialize()`: Sets up presets and the frame event.
        * `StartSession()`: Initializes D3D devices, creates a `CaptureSession` for the selected item (window, monitor, or image file), and starts the capture thread.
        * `StopSession()`: Stops the current capture session and cleans up resources.
        * `UpdatePixelSize()`, `UpdateOutputSize()`, `UpdateShaderPreset()`, etc.: Relay changes in capture or rendering options to the active `ShaderGlass` instance.
        * `ThreadFunc()`: The main loop for the capture thread, waiting for frame events and calling `ProcessInput()` on the session.
        * `AddPreset()`: Adds a new shader preset, often from an imported file, after it's compiled by `ShaderGC`.
        * `Cache()`: Provides access to the `ShaderCache` instance.

* **`CaptureSession.h` / `CaptureSession.cpp`**
    * **Class:** `CaptureSession`
    * **Purpose:** Handles a single capture session, interacting with the Windows Graphics Capture API (for screen/window capture) or loading an image file. It receives frames and triggers processing.
    * **Key Responsibilities & Methods:**
        * Constructor: Initializes based on either a `GraphicsCaptureItem` or a pre-loaded `ID3D11Texture2D` (for image files).
        * `OnFrameArrived()`: Callback for when a new frame is available from the `Direct3D11CaptureFramePool`. It retrieves the frame and signals the `CaptureManager`'s processing thread.
        * `ProcessInput()`: Calls `ShaderGlass::Process()` with the latest captured frame.
        * `Stop()`: Closes the capture session and frame pool.

* **`Shader.h` / `Shader.cpp` & `Preset.h` / `Preset.cpp` & `ShaderPass.h` / `ShaderPass.cpp`**
    * **Classes:** `Shader`, `Preset`, `ShaderPass`
    * **Purpose:** These classes model the shader system.
        * `Shader`: Represents a single compiled shader (vertex and pixel shaders). It manages shader parameters and their default/current values. Includes logic for parsing preset parameters that affect shader behavior (e.g., `scale_x`, `srgb_framebuffer`).
        * `Preset`: Represents a shader preset (`.slangp` file), which consists of one or more shader passes and associated textures. It builds upon `PresetDef` structures that define the preset.
        * `ShaderPass`: Manages a single pass in a shader preset. It handles DirectX resources like input layouts, vertex/constant buffers, and sampler states. Its `Render()` method applies the shader pass to the input texture(s) and renders to a target. It also manages the `MVP` (Model-View-Projection) matrix for preprocessing and correctly maps shader parameters.

* **`Options.h`**
    * **Purpose:** Defines various structures (`PixelSizeInfo`, `AspectRatioInfo`, etc.) and constants (like `WM_SHADER(i)` for menu commands) used throughout the application for managing configurable options and UI elements. Also includes `CaptureOptions` struct (used by `CaptureManager`).

* **`ShaderList.h` / `ShaderList.cpp`**
    * **Purpose:** Primarily declares `extern` variables (`RetroArchPresetList`, `RetroArchCachedShaders`) that provide access to the built-in shader definitions, likely generated and stored elsewhere (e.g., in `ShaderGlass/Shaders/RetroArch.h`).

* **UI Helper Windows (`BrowserWindow`, `ParamsWindow`, `CompileWindow`, `CropDialog`, `InputDialog`)**
    * **Purpose:** These classes manage the various dialog windows for user interaction:
        * `BrowserWindow.h/.cpp`: Handles the shader browser UI, allowing users to select shaders from the library.
        * `ParamsWindow.h/.cpp`: Manages the UI for viewing and modifying shader parameters via trackbars.
        * `CompileWindow.h/.cpp`: A simple window to indicate that a custom shader is being compiled.
        * `CropDialog.h/.cpp`: Provides a dialog for users to input crop values for window capture.
        * `InputDialog.h/.cpp`: A generic dialog for getting simple float input from the user (e.g., for custom aspect ratios).

* **`Helpers.h`**
    * **Purpose:** Contains utility functions, such as character array to `LPCWSTR` conversion, and checks for Windows API availability (e.g., `IsAltTabWindow`, `Is1903`, `CanDisableBorder`).

* **`Shaders/` (subdirectory within `ShaderGlass/`)**
    * This subdirectory contains header files that define shader bytecode and metadata for built-in shaders (e.g., `PassthroughShaderDef.h`, `PreprocessShaderDef.h`, and the extensive `RetroArch/` collection). These are primarily data files used by the `Shader` and `Preset` classes.

## How Components Interact

1.  The `ShaderWindow` class initializes the application, creating the main window and UI elements. It also initializes the `CaptureManager`.
2.  When the user starts a capture (via menu options handled in `ShaderWindow::WndProc`), `ShaderWindow` instructs `CaptureManager` to begin a session.
3.  `CaptureManager` sets up the D3D device and creates a `ShaderGlass` rendering instance and a `CaptureSession` instance.
4.  The `CaptureSession` (using Windows Graphics Capture API or image loading) provides frames to `CaptureManager`.
5.  `CaptureManager`, in its `ThreadFunc`, receives these frames and passes them to the `ShaderGlass::Process()` method.
6.  `ShaderGlass::Process()` then uses the active `Preset` (which contains `ShaderPass` objects) to apply effects. Each `ShaderPass` uses its compiled `Shader` to render a stage of the effect pipeline, utilizing DirectX resources.
7.  User interactions with `ShaderWindow` (e.g., changing shaders via `BrowserWindow`, adjusting parameters via `ParamsWindow`) update the state in `CaptureOptions` and are relayed to `CaptureManager` and then to the `ShaderGlass` instance to modify the rendering in real-time.

This directory forms the interactive and rendering core of the ShaderGlass application.
