#ifndef EDGE_H
#define EDGE_H

#include "../typedefs.h"
#include "Cost.hpp"

class Edge
{
private:
    const EdgeID m_id;
    const Cost m_edge_cost;
    const NodeID m_from;
    const NodeID m_to;

public:
    explicit Edge(EdgeID id, NodeID from, NodeID to, Cost edge_cost)
        : m_id(id), m_from(from), m_to(to), m_edge_cost(edge_cost)
    {
    }

    EdgeID id() const { return m_id; }
    NodeID from() const { return m_from; }
    NodeID to() const { return m_to; }

    unsigned getEnergyCost() const { return m_edge_cost.m_energy; }
    unsigned getTimeCost() const { return m_edge_cost.m_time; }

};



#endif // EDGE_H
