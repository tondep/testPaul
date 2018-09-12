#include "Graph.h"
#include "Points.h"

void Graph::plot(DataPoints data_points, LineStyle& line_plotter)
{
    _display->clear();

	data_points.transformToDisplayCoordinateSystem(_display->getWidth(), _display->getHeight());
	auto point_pairs = data_points.getAsPointPairs();
	for (const auto& point_pair : point_pairs)
	{
		line_plotter.plotLine(point_pair);
	}

	_display->update();
	_display->pause();
}
