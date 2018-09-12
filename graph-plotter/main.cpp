#include "Graph.h"
#include "Sinusoid.h"
#include "Sampler.h"
#include "Display.h"
#include "SolidLineStyle.h"
#include "Points.h"
#include <memory>

using std::shared_ptr;
using std::make_shared;

const float PI = 3.14159265359;

int main()
{
	// setup Graph with Display
	const auto WIDTH = 800;
	const auto HEIGHT = 600;
	auto display = make_shared<Display>(WIDTH, HEIGHT);
	auto graph = Graph{display};

	// create sine and cosine functions
	auto amplitude = 1.0f;
	auto frequency = 1.0f;
	auto phase = 0.0f;
	auto sine_function = Sinusoid{amplitude, frequency, phase};
	auto cosine_function = Sinusoid{amplitude, frequency, phase + PI/2};

	// generate range and plot graphs
	auto range = Range{0, 6*PI};
	auto solid_red = SolidLineStyle{Colour::Red, display};
	graph.plot(generateDataPoints(sine_function, range), solid_red);

	auto solid_blue = SolidLineStyle{Colour::Blue, display};
	graph.plot(generateDataPoints(cosine_function, range), solid_blue);

	return 0;
}

