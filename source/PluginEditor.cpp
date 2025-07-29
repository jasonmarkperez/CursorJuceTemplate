#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CursorJuceTemplateAudioProcessorEditor::CursorJuceTemplateAudioProcessorEditor (CursorJuceTemplateAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Set up the volume slider
    volumeSlider.setSliderStyle (juce::Slider::LinearHorizontal);
    volumeSlider.setRange (0.0, 1.0, 0.01);
    volumeSlider.setValue (0.5);
    volumeSlider.setTextBoxStyle (juce::Slider::TextBoxRight, false, 60, 20);
    volumeSlider.addListener (this);
    addAndMakeVisible (&volumeSlider);

    // Set up the volume label
    volumeLabel.setText ("Volume", juce::dontSendNotification);
    volumeLabel.attachToComponent (&volumeSlider, true);
    addAndMakeVisible (&volumeLabel);

    // Set the window size
    setSize (300, 100);
}

CursorJuceTemplateAudioProcessorEditor::~CursorJuceTemplateAudioProcessorEditor()
{
}

//==============================================================================
void CursorJuceTemplateAudioProcessorEditor::paint (juce::Graphics& g)
{
    // Fill the background
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    // Draw a title
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Cursor JUCE Template", getLocalBounds().removeFromTop(30), 
                      juce::Justification::centred, 1);
}

void CursorJuceTemplateAudioProcessorEditor::resized()
{
    // Position the slider
    auto area = getLocalBounds();
    area.removeFromTop (30); // Space for title
    area.removeFromLeft (60); // Space for label
    volumeSlider.setBounds (area.removeFromTop (30).reduced (10, 5));
}

void CursorJuceTemplateAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    if (slider == &volumeSlider)
    {
        // In a real plugin, you'd update a parameter or processor value here
        // For now, just show that the slider is working
        DBG ("Volume slider changed to: " << slider->getValue());
    }
}