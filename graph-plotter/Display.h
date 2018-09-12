#ifndef DISPLAY_CLASS_H
#define DISPLAY_CLASS_H

#include "Points.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

enum class Colour
{
    Red,
    Green,
    Blue    
};

// DO NOT MODIFY THE DISPLAY CLASS! 
// Clients have no knowledge that SFML is in use

class Display
{
public:
	Display(int display_width, int display_height);
	int getWidth() const { return _display_width; }
	int getHeight() const { return _display_height; }

	void drawLine(PointPair end_points, Colour colour);
	void drawDot(Point point, Colour colour);

    void clear();   // clears the current display
	void update();	// updates the display by rendering all drawn shapes
	void pause();	// pauses execution of the program so that the display can be viewed
                    // pressing the Escape key or clicking the display window's "close" icon will close the display
                    // pressing the spacebar will allow program execution to continue

private:
    
    sf::Color convertToSFML(Colour colour) const; // converts to SFML Colours
    
    int _display_width;
	int _display_height;

	sf::RenderWindow _display; // sfml window

	static const int RADIUS = 3;
};

#endif
