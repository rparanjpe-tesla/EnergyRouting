#ifndef GEO_UTILS_HPP
#define GEO_UTILS_HPP

#include "../datastructures/Node.hpp"
#include "../datastructures/Edge.hpp"

struct GeoUtils
{
    static double greatCircleDistance(const Node& n0, const Node& n1);
    static double toRadians(double degrees);
    static double toDegrees(double radians);
};

#endif // GEO_UTILS_HPP