#include "Display.h"
#include <cassert>

// DO NOT MODIFY THE DISPLAY CLASS!

Display::Display(int display_width, int display_height):
	_display_width(display_width),
	_display_height(display_height),
	_display{sf::VideoMode(display_width, display_height), "Graph Plotter"}
{}

void Display::drawLine(PointPair end_points, Colour colour)
{
    auto line_start = end_points.first();
    auto line_end = end_points.second();

    // define the start and end positions of the line for SFML
    auto line = sf::VertexArray{sf::Lines, 2};
    line[0].position = sf::Vector2f(line_start.x, line_start.y);
    line[1].position = sf::Vector2f(line_end.x, line_end.y);
    line[0].color = convertToSFML(colour);
    line[1].color = convertToSFML(colour);

    _display.draw(line);
}

void Display::drawDot(Point point,  Colour colour)
{
    auto shape = sf::CircleShape{RADIUS};
    shape.setPosition(sf::Vector2f(point.x, point.y));
    shape.setFillColor(convertToSFML(colour));
    _display.draw(shape);
}

void Display::clear()
{
    _display.clear ();
}

void Display::update()
{
    _display.display();
}

void Display::pause()
{
    // pause display until user interaction
    while (_display.isOpen())
    {
        auto event = sf::Event{};
        while (_display.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _display.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    _display.close();
                }
                if (event.key.code == sf::Keyboard::Space)
                {
                    return;
                }
            }
        }
    }
}

sf::Color Display::convertToSFML(Colour colour) const
{
    auto drawing_colour = sf::Color{};
    switch (colour) {
        case(Colour::Red): 
            drawing_colour = sf::Color::Red;
            break;
        case(Colour::Green): 
            drawing_colour = sf::Color::Green;
            break;
        case(Colour::Blue): 
            drawing_colour = sf::Color::Blue;
            break;
        default: assert(false);
    }
    return drawing_colour;        
}

