#ifndef EDGE_H
#define EDGE_H

#include "../typedefs.h"
#include "Cost.hpp"

struct Edge
{
    Cost edge_cost;
    const EdgeID id;
    const NodeID from;
    const NodeID to;

    explicit Edge(EdgeID id, NodeID from, NodeID to, Cost edge_cost)
        : id(id), from(from), to(to), edge_cost(edge_cost)
    {
    }
};



#endif // EDGE_H
