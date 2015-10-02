#ifndef NODE_H
#define NODE_H

#include "../typedefs.h"
#include "Cost.hpp"

struct Node
{
    Cost cost;
    const NodeID id;
    const Longitude lon;
    const Latitude lat;
    const bool charger;

    explicit Node(NodeID id, Longitude lon, Latitude lat, bool charger)
        : id(id), lon(lon), lat(lat), cost(Cost(MAX_ENERGY, INFINITE_TIME)), charger(charger)
    {
    }
};

struct ReplicaNode: Node
{
    const NodeID referenceId;

    explicit ReplicaNode(NodeID id, Longitude lon, Latitude lat, NodeID referenceId)
        : Node(id, lon, lat), referenceId(referenceId)
    {
    }
};

#endif // NODE_H
