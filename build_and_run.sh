#!/bin/bash

# Build the plugin
echo "Building plugin..."
cd build
make

# Run the standalone version
echo "Launching standalone plugin..."
open "CursorJuceTemplate_artefacts/Debug/Standalone/Cursor JUCE Template.app" 