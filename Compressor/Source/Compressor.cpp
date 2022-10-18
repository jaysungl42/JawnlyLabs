/*
  ==============================================================================

    Compressor.cpp
    Created: 11 Jun 2022 3:58:56pm
    Author:  Jay Sung

  ==============================================================================
*/

#include "Compressor.h"

Compressor::Compressor() {
    buffer = CircularBuffer(150, 20);
    avgTime = 0.01;
    rms = 0;
    gain = 1;
}

float Compressor::compressSample(float data, float thresh, float ratio, float attack, float release, float knee) {
    rms = (1 - avgTime) * rms + avgTime * std::pow(data, 2.0f);     // adjust rms value with incoming signal
    float dbRMS = 10 * std::log10(rms);     // convert rms to dB
    
    float slope = 1 - (1 / ratio);      // Convert ratio to slope
    float dbGain = std::min(0.0f, (slope * (thresh - dbRMS)));      // find new gain in dB
    float newGain = std::pow(10, dbGain / 20);      // convert new gain in db to linear
    
    float coeff;
    // if gain is getting decreasing(compressed) we smooth attack, else smooth the release
    if (newGain < gain) {
        coeff = attack;
    }
    else {
        coeff = release;
    }
    gain = (1 - coeff) * gain + coeff * newGain; //3
    
    float compressedSample = gain * buffer.getData();
    buffer.setData(data);
    buffer.nextSample();
    return compressedSample;
}
