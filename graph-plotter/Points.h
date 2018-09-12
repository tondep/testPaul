#ifndef POINTS_H
#define POINTS_H

struct Point
{
	float x;
	float y;
};

class PointPair
{
public:
	PointPair(Point p1, Point p2):
	  _p1(p1),
	  _p2(p2)
	  {}

	  Point first() const { return _p1; }	// return first point in pair
	  Point second() const { return _p2; }	// return second point in pair

private:
	Point _p1;
	Point _p2;
};

class Range
{
public:
	Range(float start, float end):
	  _start(start),
	  _end(end)
	  { if (end <= start) throw "Not a range."; }

	  float getStart() const { return _start; }		// return start of range
	  float getEnd() const { return _end; }			// return end of range
	  float size() const { return _end - _start; }	// return size of range

private:
	float _start;
	float _end;
};

#endif
