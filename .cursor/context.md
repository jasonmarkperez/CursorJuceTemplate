# JUCE Audio Plugin Development Context

## JUCE Framework Overview
JUCE is a comprehensive C++ framework for audio plugin development. It provides cross-platform support for creating VST, AU, AAX, and standalone audio plugins.

## Key JUCE Classes

### AudioProcessor
- Base class for all audio plugins
- Handles audio processing, parameter management, and plugin hosting
- Must implement `processBlock()` for audio processing
- Use `JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR` for memory management

### AudioProcessorEditor
- GUI editor for the audio processor
- Inherits from `juce::Component`
- Must implement `paint()` and `resized()` methods
- Use `addAndMakeVisible()` to add child components

### Common JUCE Components
- `juce::Slider` - For parameter control
- `juce::Button` - For triggers and toggles
- `juce::ComboBox` - For selection controls
- `juce::Label` - For text display
- `juce::AudioParameterFloat` - For automatable parameters

## Audio Processing Patterns

### Real-time Safety
- Never allocate memory in `processBlock()`
- Use `juce::ScopedNoDenormals` to prevent denormal numbers
- Keep processing deterministic and efficient

### Parameter Automation
- Create parameters in the constructor
- Use `addParameter()` to register them
- Access parameter values in `processBlock()`

### State Management
- Implement `getStateInformation()` and `setStateInformation()`
- Use `juce::ValueTree` or `juce::XmlElement` for complex state
- Consider using `juce::AudioProcessorValueTreeState` for parameter state

## GUI Development

### Component Layout
- Use `getLocalBounds()` for layout calculations
- `removeFromTop()`, `removeFromLeft()` for flexible layouts
- `reduced()` for margins and padding

### Event Handling
- Implement listener interfaces for user interaction
- Use `addListener()` to connect components to listeners
- Override callback methods like `sliderValueChanged()`

## Best Practices

### Memory Management
- Use RAII principles
- Avoid raw pointers when possible
- Use `std::unique_ptr` for ownership
- Use `juce::ScopedPointer` for JUCE-specific objects

### Performance
- Profile audio processing code
- Use SIMD instructions when available
- Minimize allocations in audio thread
- Use lock-free data structures for thread communication

### Cross-platform Development
- Use JUCE's platform abstraction layers
- Test on all target platforms
- Handle platform-specific audio APIs
- Consider different screen densities for GUI

## Common Patterns

### Parameter Setup
```cpp
juce::AudioParameterFloat* gainParam = new juce::AudioParameterFloat(
    "gain", "Gain", 0.0f, 1.0f, 0.5f
);
addParameter(gainParam);
```

### Slider Setup
```cpp
gainSlider.setSliderStyle(juce::Slider::LinearHorizontal);
gainSlider.setRange(0.0, 1.0, 0.01);
gainSlider.setValue(0.5);
gainSlider.addListener(this);
addAndMakeVisible(&gainSlider);
```

### Audio Processing
```cpp
void processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override
{
    juce::ScopedNoDenormals noDenormals;
    
    for (int channel = 0; channel < getTotalNumInputChannels(); ++channel)
    {
        auto* channelData = buffer.getWritePointer(channel);
        
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            // Process each sample here
            channelData[sample] *= gainValue;
        }
    }
}
``` 