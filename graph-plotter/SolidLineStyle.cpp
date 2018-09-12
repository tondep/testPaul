#include "SolidLineStyle.h"

void SolidLineStyle::plotLine(PointPair end_points)
{
	auto display = getDisplay();
	display->drawLine(end_points, getColour());
}
