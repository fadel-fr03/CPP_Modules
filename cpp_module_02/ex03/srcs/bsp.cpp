#include "../incs/Point.hpp"

static float area(const Point p1, const Point p2, const Point p3)
{
	float area = (p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())
				+ p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())
				+ p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) / 2.0f;

	return (area < 0) ? -area : area;
}

static bool areAlmostEqual(float a, float b, float epsilon = 0.0001f)
{
	return (a - b < epsilon && b - a < epsilon);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	float a0 = area(a, b, c);
	float a1 = area(point, a, b);
	float a2 = area(point, b, c);
	float a3 = area(point, c, a);

	// If the point is on an edge or vertex, area will be very close to 0
	if (a1 < 0.0001f || a2 < 0.0001f || a3 < 0.0001f)
		return false;

	if (areAlmostEqual(a0, a1 + a2 + a3))
		return true;

	return false;
}
