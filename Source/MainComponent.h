#pragma once

#include <JuceHeader.h>
#include "maximilian.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;
    

private:
    //==============================================================================
    maxiOsc testOsc;
    //member variables for saving file
    //relative path for file, currently doesn't work with a absolute path
    juce::File file = juce::File::getCurrentWorkingDirectory().getChildFile ("file.wav");
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
