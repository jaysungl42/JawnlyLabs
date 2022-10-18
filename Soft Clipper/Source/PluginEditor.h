/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

//==============================================================================
/**
*/
class SoftClipperAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SoftClipperAudioProcessorEditor (SoftClipperAudioProcessor&, juce::AudioProcessorValueTreeState&);
    ~SoftClipperAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void addSlider(juce::String, juce::String, juce::Slider&, juce::Label&, std::unique_ptr<SliderAttachment>&);

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SoftClipperAudioProcessor& audioProcessor;
    juce::AudioProcessorValueTreeState& params;
    juce::Slider threshSlider, ESlider, mixSlider, algoSlider;
    juce::Label threshLabel, ELabel, mixLabel, algoLabel;
    std::unique_ptr<SliderAttachment> threshAttachment, EAttachment, mixAttachment, algoAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SoftClipperAudioProcessorEditor)
};
