/*
  ==============================================================================

    Compressor.h
    Created: 11 Jun 2022 3:59:10pm
    Author:  Jay Sung

  ==============================================================================
*/

#pragma once

#include "CircularBuffer.h"

class Compressor {
public:
    Compressor();
    float compressSample(float data, float thresh, float ratio, float attack, float release, float knee);
private:
    CircularBuffer buffer;
    float avgTime, rms, gain;
};
