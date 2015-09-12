#include "geo_utils.hpp"

#include <cmath>

const double MEAN_EARTH_RADIUS = 6371.2;
const double PI = 3.14159265358979323;

double GeoUtils::greatCircleDistance(const Node &n0, const Node &n1)
{
    double delta_lambda = fabs(GeoUtils::toRadians(n0.longitude() - n1.longitude()));
    double delta_phi    = fabs(GeoUtils::toRadians(n0.latitude() - n1.latitude()));
    double cos_phi1     = cos(GeoUtils::toRadians(n0.latitude()));
    double cos_phi2     = cos(GeoUtils::toRadians(n1.latitude()));
    double a = pow(sin(delta_phi/2), 2) + cos_phi1*cos_phi2*pow(sin(delta_lambda/2), 2);

    return 2 * MEAN_EARTH_RADIUS * atan2(sqrt(a), sqrt(1 - a));
}

double GeoUtils::toRadians(double degrees)
{
    return 2 * PI * degrees / 360;
}

double GeoUtils::toDegrees(double radians)
{
    return 360 * radians / (2 * PI);
}