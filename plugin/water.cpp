#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

#include <boost/geometry/io/wkt/wkt.hpp>

#include <string>
#include <vector>

using std::string;
using std::vector;

#include "water.h"

typedef boost::geometry::model::d2::point_xy<double> point_type;
typedef boost::geometry::model::polygon<point_type> polygon_type;

int water_area_id = -1;
vector<polygon_type> areas;


int add_water_area(char* area)
{
	polygon_type poly;
	boost::geometry::read_wkt("POLYGON(" + string(area) + ")", poly);

	water_area_id ++;
	return water_area_id;
}

bool remove_water_area(int id)
{
	return false;
}

bool point_in_any_water_area(float x, float y)
{
	bool success = false;
	point_type p(x, y);

	for (polygon_type area : areas)
	{
		if (boost::geometry::within(p, area))
		{
			success = true;
			break;
		}
	}

	return success;
}