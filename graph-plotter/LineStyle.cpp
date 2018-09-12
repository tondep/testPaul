#include "LineStyle.h"

LineStyle::LineStyle(Colour colour, shared_ptr<Display> display_ptr):
	_colour(colour),
	_display_ptr(display_ptr)
{
	if (display_ptr == nullptr) throw "A valid display is required.";
}





