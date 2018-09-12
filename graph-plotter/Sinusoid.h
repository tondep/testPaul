#ifndef SINUSOID_H
#define SINUSOID_H

class Sinusoid
{
public:
	Sinusoid(float amplitude=1.0, float frequency = 1.0, float phase=0.0):
	_amplitude(amplitude),
	_frequency(frequency),
	_phase(phase)
	{}

	float evaluate(float x) const;

private:
	float _amplitude;
	float _frequency;
	float _phase;
};

#endif