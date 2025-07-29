# CursorJuceTemplate

A modern, well-configured JUCE audio plugin template for rapid development with Cursor IDE.

## Features

- ✅ **Ready-to-build** JUCE audio plugin template
- ✅ **VSCode/Cursor integration** with proper IntelliSense
- ✅ **CMake-based build system** for cross-platform compatibility
- ✅ **Multiple plugin formats**: AU, VST3, and Standalone
- ✅ **Modern C++17** with JUCE 8.0.8
- ✅ **Pre-configured tasks** for building and running
- ✅ **Proper include paths** and IntelliSense configuration
- ✅ **Cursor AI assistance** with custom rules and snippets
- ✅ **JUCE-specific code templates** and patterns

## Quick Start

### Prerequisites

- **macOS** (primary target, Windows/Linux can be added)
- **CMake** 3.22 or higher
- **Xcode Command Line Tools** (for macOS)
- **Cursor IDE** or **VSCode** with C++ extensions

### Getting Started

1. **Clone this template**:
   ```bash
   git clone https://github.com/jasonmarkperez/CursorJuceTemplate.git MyNewPlugin
   cd MyNewPlugin
   ```

2. **Run the setup script** (recommended):
   ```bash
   ./setup.sh
   ```
   
   This script will automatically:
   - Initialize the JUCE submodule
   - Set up the build directory
   - Configure CMake
   - Build the project

3. **Or manually** (if you prefer):
   ```bash
   # Initialize JUCE submodule
   git submodule update --init --recursive
   
   # Build the plugin
   mkdir build && cd build
   cmake .. && make
   ```

4. **Run standalone version**:
   ```bash
   ./build_and_run.sh
   ```

## Project Structure

```
CursorJuceTemplate/
├── CMakeLists.txt              # Main build configuration
├── source/                     # Plugin source code
│   ├── PluginProcessor.h       # Audio processor header
│   ├── PluginProcessor.cpp     # Audio processor implementation
│   ├── PluginEditor.h          # GUI editor header
│   └── PluginEditor.cpp        # GUI editor implementation
├── JUCE/                       # JUCE framework (submodule)
├── .vscode/                    # IDE configuration
│   ├── c_cpp_properties.json   # IntelliSense settings
│   ├── settings.json           # VSCode/Cursor settings
│   └── tasks.json              # Build and run tasks
├── build_and_run.sh            # Quick build and run script
├── .cursorrules                # Cursor AI rules and context
├── .cursorignore               # Files to ignore for AI assistance
├── .cursor/                    # Cursor-specific configuration
│   ├── snippets.json           # JUCE code snippets
│   ├── commands.json           # Custom commands
│   ├── context.md              # JUCE development context
│   └── templates/              # Code templates
└── README.md                   # This file
```

## Development Workflow

### Using VSCode/Cursor Tasks

1. **Build Plugin**: `Cmd+Shift+P` → "Tasks: Run Task" → "Build Plugin"
2. **Run Standalone**: `Cmd+Shift+P` → "Tasks: Run Task" → "Run Standalone"

### Using Terminal

```bash
# Build only
cd build && make

# Build and run standalone
./build_and_run.sh
```

## Customization

### Changing Plugin Name

1. **Update CMakeLists.txt**:
   - Change `project(CursorJuceTemplate VERSION 1.0.0)` to your project name
   - Update `juce_add_plugin(CursorJuceTemplate` to your target name
   - Change `PRODUCT_NAME "Cursor JUCE Template"` to your plugin name
   - Update `PLUGIN_CODE Curs` to a unique 4-character code

2. **Update source files**:
   - Rename `CursorJuceTemplateAudioProcessor` to `YourPluginAudioProcessor`
   - Rename `CursorJuceTemplateAudioProcessorEditor` to `YourPluginAudioProcessorEditor`
   - Update all class references in `.cpp` files

3. **Update VSCode tasks**:
   - Modify paths in `.vscode/tasks.json` to match your plugin name
   - Update `build_and_run.sh` script

### Adding Features

- **Parameters**: Add `juce::AudioParameterFloat` in the processor
- **GUI Components**: Add widgets in the editor
- **DSP**: Implement audio processing in `processBlock()`
- **MIDI**: Enable MIDI input/output in CMakeLists.txt

## Build Outputs

The template builds three formats:

- **AU (Audio Unit)**: `CursorJuceTemplate_artefacts/Debug/AU/Cursor JUCE Template.component`
- **VST3**: `CursorJuceTemplate_artefacts/Debug/VST3/Cursor JUCE Template.vst3`
- **Standalone**: `CursorJuceTemplate_artefacts/Debug/Standalone/Cursor JUCE Template.app`

## Configuration Options

### CMake Options

- `FORMATS`: Change plugin formats (AU, VST3, Standalone, AAX, etc.)
- `COPY_PLUGIN_AFTER_BUILD`: Auto-install plugins to system directories
- `IS_SYNTH`: Set to `TRUE` for synthesizers
- `NEEDS_MIDI_INPUT/OUTPUT`: Enable MIDI support

### JUCE Modules

The template includes these JUCE modules:
- `juce_audio_utils` - Plugin hosting and utilities
- `juce_audio_basics` - Core audio functionality
- `juce_audio_devices` - Audio I/O
- `juce_audio_formats` - File format support
- `juce_audio_processors` - Plugin format support
- `juce_core` - Core utilities
- `juce_graphics` - Graphics and drawing
- `juce_gui_basics` - Basic GUI components
- `juce_gui_extra` - Advanced GUI components

## Cursor AI Features

This template includes special configuration for Cursor AI assistance:

### AI Rules and Context
- **`.cursorrules`** - Defines project context and development guidelines
- **`.cursorignore`** - Tells AI which files to ignore during assistance
- **`.cursor/context.md`** - Detailed JUCE framework information

### Code Snippets
Type these prefixes in Cursor to get JUCE code snippets:
- `juce_param` - Create audio parameter
- `juce_slider` - Create slider with listener
- `juce_button` - Create button
- `juce_process` - Audio processing template
- `juce_layout` - Component layout template
- `juce_paint` - Paint method template

### Custom Commands
Cursor can suggest these commands:
- Build Plugin
- Clean Build
- Run Standalone
- Initialize JUCE
- Create Build Directory
- Open Plugin in DAW

## Troubleshooting

### IntelliSense Issues

If you see `'JuceHeader.h' file not found`:
1. Build the project first: `cd build && make`
2. Reload VSCode/Cursor: `Cmd+Shift+P` → "Developer: Reload Window"
3. Reset IntelliSense: `Cmd+Shift+P` → "C/C++: Reset IntelliSense Database"

### Build Issues

- **CMake version**: Ensure you have CMake 3.22+
- **Xcode**: Install Xcode Command Line Tools: `xcode-select --install`
- **Clean build**: Delete `build/` directory and rebuild

## License

This template is provided as-is for educational and development purposes. JUCE framework has its own licensing terms.

## Contributing

Feel free to fork and customize this template for your projects. Consider contributing improvements back to the community! 