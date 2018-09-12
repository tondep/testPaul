#include "Sinusoid.h"
#include <cmath>

float Sinusoid::evaluate(float x) const
{
	return _amplitude*sin(_frequency * x + _phase);
}