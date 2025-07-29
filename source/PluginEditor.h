#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
class CursorJuceTemplateAudioProcessorEditor : public juce::AudioProcessorEditor,
                                          private juce::Slider::Listener
{
public:
    CursorJuceTemplateAudioProcessorEditor (CursorJuceTemplateAudioProcessor&);
    ~CursorJuceTemplateAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    CursorJuceTemplateAudioProcessor& audioProcessor;

    // Simple volume slider for testing
    juce::Slider volumeSlider;
    juce::Label volumeLabel;

    void sliderValueChanged (juce::Slider* slider) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CursorJuceTemplateAudioProcessorEditor)
};