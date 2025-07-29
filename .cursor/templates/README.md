# JUCE Code Templates

This directory contains template files that Cursor can reference when helping with JUCE development.

## Template Files

### Basic Audio Parameter
```cpp
// In PluginProcessor.h
juce::AudioParameterFloat* gainParameter;

// In PluginProcessor.cpp constructor
gainParameter = new juce::AudioParameterFloat(
    "gain", "Gain", 0.0f, 1.0f, 0.5f
);
addParameter(gainParameter);
```

### Slider with Listener
```cpp
// In PluginEditor.h
juce::Slider gainSlider;
juce::Label gainLabel;

// In PluginEditor.cpp constructor
gainSlider.setSliderStyle(juce::Slider::LinearHorizontal);
gainSlider.setRange(0.0, 1.0, 0.01);
gainSlider.setValue(0.5);
gainSlider.setTextBoxStyle(juce::Slider::TextBoxRight, false, 60, 20);
gainSlider.addListener(this);
addAndMakeVisible(&gainSlider);

gainLabel.setText("Gain", juce::dontSendNotification);
gainLabel.attachToComponent(&gainSlider, true);
addAndMakeVisible(&gainLabel);
```

### Audio Processing Loop
```cpp
void processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // Clear unused output channels
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    // Process audio
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer(channel);
        
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            // Apply gain
            channelData[sample] *= gainValue;
        }
    }
}
```

### Component Layout
```cpp
void resized() override
{
    auto area = getLocalBounds();
    
    // Title area
    auto titleArea = area.removeFromTop(30);
    
    // Control area
    auto controlArea = area.reduced(10);
    gainSlider.setBounds(controlArea.removeFromTop(30));
    
    // Additional controls can be added here
}
```

### State Saving/Loading
```cpp
void getStateInformation(juce::MemoryBlock& destData) override
{
    juce::ValueTree state("PluginState");
    state.setProperty("gain", gainValue, nullptr);
    
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void setStateInformation(const void* data, int sizeInBytes) override
{
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    
    if (xmlState.get() != nullptr)
    {
        juce::ValueTree state = juce::ValueTree::fromXml(*xmlState);
        gainValue = state.getProperty("gain", 0.5f);
    }
}
``` 