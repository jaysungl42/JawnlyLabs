/*
  ==============================================================================

    Clipper.h
    Created: 16 Jun 2022 10:24:11pm
    Author:  Jay Sung

  ==============================================================================
*/

#include "CircularBuffer.h"
#pragma once

class Clipper {
public:
    Clipper();
    float clipSample(float data, float thresh, int E, float output, int algo);
private:
    CircularBuffer buffer;
};
