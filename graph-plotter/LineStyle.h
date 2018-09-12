#ifndef LINESTYLE
#define LINESTYLE

#include "Display.h"
#include <SFML/Graphics.hpp>
#include <memory>

using std::shared_ptr;

class LineStyle
{
public:
	LineStyle(Colour colour, shared_ptr<Display> display_ptr);
	virtual void plotLine(PointPair end_points) = 0;

	virtual ~LineStyle() {};

protected:
    shared_ptr<Display> getDisplay() { return _display_ptr; }
    Colour getColour() { return _colour; }

private:
	Colour _colour;
	shared_ptr<Display> _display_ptr;
};

#endif
