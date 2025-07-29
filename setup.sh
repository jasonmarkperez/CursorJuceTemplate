#!/bin/bash

echo "🎵 Setting up CursorJuceTemplate..."

# Check if git is available
if ! command -v git &> /dev/null; then
    echo "❌ Error: Git is not installed. Please install Git first."
    exit 1
fi

# Check if CMake is available
if ! command -v cmake &> /dev/null; then
    echo "❌ Error: CMake is not installed. Please install CMake 3.22+ first."
    exit 1
fi

# Initialize JUCE submodule
echo "📦 Initializing JUCE framework..."
git submodule update --init --recursive

if [ $? -ne 0 ]; then
    echo "❌ Error: Failed to initialize JUCE submodule."
    exit 1
fi

# Create build directory
echo "🔨 Setting up build directory..."
mkdir -p build
cd build

# Configure CMake
echo "⚙️  Configuring CMake..."
cmake ..

if [ $? -ne 0 ]; then
    echo "❌ Error: CMake configuration failed."
    exit 1
fi

# Build the project
echo "🏗️  Building project..."
make

if [ $? -ne 0 ]; then
    echo "❌ Error: Build failed."
    exit 1
fi

echo "✅ Setup complete! Your JUCE plugin is ready."
echo ""
echo "🎮 To run the standalone version:"
echo "   ./build_and_run.sh"
echo ""
echo "📁 Build outputs:"
echo "   - AU: build/CursorJuceTemplate_artefacts/Debug/AU/"
echo "   - VST3: build/CursorJuceTemplate_artefacts/Debug/VST3/"
echo "   - Standalone: build/CursorJuceTemplate_artefacts/Debug/Standalone/" 