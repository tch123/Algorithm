#include "Geo2D.h"

namespace Vonng
{
    namespace Geo2D
    {
        Point::Point(Point& other) :x(other.x), y(other.y)
        {
        };

        Point::Point(double ix, double iy) :x(ix), y(iy) {};

        double Vonng::Geo2D::Point::length(Point & other)
        {
            return sqrt((other.x - x) * (other.x - x) + (other.y - y)*(other.y - y));
        }
    }
}