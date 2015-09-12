#ifndef NODE_H
#define NODE_H

#include "../typedefs.h"
#include "Cost.hpp"

class Node
{
private:
    Cost m_node_cost;
    const NodeID m_id;
    const Longitude m_lon;
    const Latitude m_lat;

public:
    Node();
    explicit Node(NodeID id, Longitude lon, Latitude lat)
        : m_id(id), m_lon(lon), m_lat(lat), m_node_cost(Cost(MAX_ENERGY, INFINITE_TIME))
    {
    }

    NodeID id() const { return m_id; }
    Longitude longitude() const { return m_lon; }
    Latitude latitude() const { return m_lat; }

    unsigned getEnergyCost() const { return m_node_cost.m_energy; }
    unsigned getTimeCost() const { return m_node_cost.m_time; }
    void setEnergyCost(unsigned energy) { m_node_cost.m_energy = energy; }
    void setTimeCost(unsigned time) { m_node_cost.m_time = time; }
};

#endif // NODE_H
