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
class CompressorAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    CompressorAudioProcessorEditor (CompressorAudioProcessor&, juce::AudioProcessorValueTreeState&);
    ~CompressorAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void addSlider(juce::String, juce::String, juce::Slider&, juce::Label&, std::unique_ptr<SliderAttachment>&);

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    CompressorAudioProcessor& audioProcessor;
    juce::AudioProcessorValueTreeState& params;
    juce::Slider threshSlider, ratioSlider, kneeSlider, attackSlider, releaseSlider;
    juce::Label threshLabel, ratioLabel, kneeLabel, attackLabel, releaseLabel;
    std::unique_ptr<SliderAttachment> threshAttachment, slopeAttachment, kneeAttachment, attackAttachment, releaseAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CompressorAudioProcessorEditor)
};
