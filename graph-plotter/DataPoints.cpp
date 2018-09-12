#include "DataPoints.h"
#include <algorithm>
#include <cmath>
using std::abs;

vector<PointPair> DataPoints::getAsPointPairs() const
{
	auto point_pairs = vector<PointPair>{};

	// return an empty vector if there are insufficient points to create a pair
	if (_datapoints.size() < 2)
		return point_pairs;

	// group as point pairs
	auto first_point_in_pair = _datapoints.cbegin();  // Returns a const_iterator, no non-member versions in C++11
	for (; first_point_in_pair != _datapoints.end()-1; first_point_in_pair++)
	{
		auto second_point_in_pair = first_point_in_pair + 1;
		auto temp_pair = PointPair{*first_point_in_pair, *second_point_in_pair};
		point_pairs.push_back(temp_pair);
	}

	return point_pairs;
}

vector<float> DataPoints::extractYValues() const
{
	auto y_values = vector<float>{};
	for (const auto& point : _datapoints)	// store all y values
	{
		y_values.push_back(point.y);
	}
	return y_values;
}

float DataPoints::getMaxY() const
{
	auto y_values = extractYValues();
	return *(max_element(y_values.begin(),y_values.end()));		// using STL algorithm to determine max
}

float DataPoints::getMinY() const
{
	auto y_values = extractYValues();
	return *(min_element(y_values.begin(),y_values.end()));		// using STL algorithm to determine min
}

float DataPoints::getMaxX() const
{
	// assuming ordered points, last point will have the maximum x-value
	auto last_point = _datapoints.back();
	return last_point.x;
}

float DataPoints::getMinX() const
{
	// assuming ordered points, first point will have the minimum x-value
	auto first_point = _datapoints.front();
	return first_point.x;
}

void DataPoints::transformToDisplayCoordinateSystem(int display_width, int display_height)
{
	if (_transformed) // it does not make sense to transform points more than once
		return;

	auto scale_factors = calculateScaleFactors(display_width,display_height);
	auto offsets = calculateOffsets(display_width,display_height);

	auto transformed_points = vector<Point>{};
	for (const auto& point : _datapoints)
	{
		// Scale and shift point to fit display
		auto new_x1 = (point.x + offsets.first) * scale_factors.first;
		auto new_y1 = (point.y + offsets.second) * scale_factors.second;

		// Invert y display coordinate
		new_y1 = display_height - new_y1;

		// Store transformed point
		auto transformed_point = Point{new_x1, new_y1};
		transformed_points.push_back(transformed_point);
	}

	_datapoints = transformed_points;
	_transformed = true;
}

pair<float,float> DataPoints::calculateScaleFactors(int display_width, int display_height) const
{
	// Determine graph dimensions
	auto graph_width = getMaxX() - getMinX();
	auto graph_height = getMaxY() - getMinY();

	// Determine scaling factors
	auto horizontal_scaling_factor = display_width/graph_width;
	auto vertical_scaling_factor = display_height/graph_height;

    return (make_pair(horizontal_scaling_factor, vertical_scaling_factor));
}

pair<float,float> DataPoints::calculateOffsets(int display_width, int display_height) const
{
	// offsets are calculated to shift the plot into the first quadrant
	// ie. ensure that all datapoints are positive
	// before being scaled to screen dimensions

	// determine horizontal offset
	auto horizontal_offset = 0.0f;
	if ( getMinX() < 0 )
		horizontal_offset = abs(getMinX());
	else
		horizontal_offset = -getMinX();

	// determine vertical offset
    auto vertical_offset = 0.0f;
	if ( getMinY() < 0 )
		vertical_offset = abs(getMinY());
	else
		vertical_offset = -getMinY();

	return (make_pair(horizontal_offset, vertical_offset));
}
