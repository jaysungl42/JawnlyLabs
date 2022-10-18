/*
  ==============================================================================

    Clipper.cpp
    Created: 16 Jun 2022 10:24:11pm
    Author:  Jay Sung

  ==============================================================================
*/

#include <math.h>
#include "Clipper.h"

Clipper::Clipper() {
}

float Clipper::clipSample(float data, float thresh, int E, float mix, int algo) {
    float dryOut = data;
    float wetOut = data;
    switch ((int)algo) {
        case 1:     // Hyperbolic Tangent Soft Clipping
            wetOut = tanh(5 * data);
            return ((1 - mix) * dryOut) + (mix * wetOut);
            break;
        case 2:     // Sinusoidal Soft Clipping
            if (abs(data) > thresh) {
                wetOut = (data > 0) - (data < 0);
            }
            else if (-thresh <= data <= thresh) {
                wetOut = sin((3 * data * M_PI) / 4);
            }
            return ((1 - mix) * dryOut) + (mix * wetOut);
            break;
        case 3:     // Exponential Soft Clipping
            if (abs(data) > thresh) {
                wetOut = (data > 0) - (data < 0);
            }
            else if (-thresh <= data <= thresh) {
                wetOut = ((data > 0) - (data < 0)) * (1 - pow(abs(((3 * data) / 2) - ((data > 0) - (data < 0))), (int)E));
            }
            return ((1 - mix) * dryOut) + (mix * wetOut);
            break;
        case 4:     // Two Stage Quadratic Soft Clipping
            if (abs(data) > thresh) {
                wetOut = (data > 0) - (data < 0);
            }
            else if ((thresh / 2) <= abs(data) <= thresh) {
                wetOut = ((data > 0) - (data < 0)) * ((3 - pow(2 - abs(3 * data), 2)) / 3);
            }
            else if (-(thresh / 2) <= data <= (thresh / 2)) {
                wetOut = 2 * data;
            }
            return ((1 - mix) * dryOut) + (mix * wetOut);
            break;
        case 5:     // Cubic Soft Clipping
            if (abs(data) > thresh) {
                wetOut = (data > 0) - (data < 0);
            }
            else if (-thresh <= data <= thresh) {
                wetOut = ((9 * data) / 4) - ((27 * pow(data, 3)) / 16);
            }
            return ((1 - mix) * dryOut) + (mix * wetOut);
            break;
        case 6:     // Reciprocal Soft Clipping
            wetOut = ((data > 0) - (data < 0)) * (1 - (1 / (abs(30 * data) + 1)));
            return ((1 - mix) * dryOut) + (mix * wetOut);
            break;
    }
    return data;
}
