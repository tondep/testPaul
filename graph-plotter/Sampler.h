#ifndef SAMPLER_H
#define SAMPLER_H

#include "DataPoints.h"
#include "Sinusoid.h"

class Sampler
{
public:
	// performs uniform sampling
	DataPoints generateSamples(const Sinusoid& sine_wave, const Range& range) const;

private:
	static const int TOTAL_POINTS = 50;
};

// standalone function for generating data points, a default uniform sampler is provided
DataPoints generateDataPoints(const Sinusoid& sine_wave, const Range& range, const Sampler& sampler = Sampler{});

#endif
