#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <limits>
#include <string>

using NodeID = unsigned int;
using EdgeID = unsigned int;

using Latitude = double;
using Longitude = double;

static const unsigned INFINITE_TIME = std::numeric_limits<unsigned>::max();
static const unsigned MAX_ENERGY    = 100;
static const std::string NODE_EDGE_BREAK = "---";

#endif /* TYPEDEFS_H */
