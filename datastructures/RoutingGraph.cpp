#include "RoutingGraph.hpp"
#include "../utilities/geo_utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

RoutingGraph::RoutingGraph(const std::string& filename)
{
    std::cout<< filename << std::endl;
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cout << "Could not open file for routing graph..." << std::endl;
        return;
    }

    std::string line;
    bool nodes = true;
    while (std::getline(ifs, line))
    {
        if (line == NODE_EDGE_BREAK)
        {
            nodes = false;
            continue;
        }

        // Nodes
        if (nodes)
        {
            std::istringstream iss(line);
            NodeID nodeId;
            double lat, lon;
            bool charger;
            if (!(iss >> nodeId >> lat >> lon >> charger)) { break; }
            m_node_map.insert(std::make_pair(nodeId, new Node(nodeId, lon, lat, charger)));
        }

        // Edges
        else
        {
            std::istringstream iss(line);
            EdgeID edgeId;
            NodeID n0, n1;
            double energy, speed;
            if (!(iss >> edgeId >> n0 >> n1 >> energy >> speed)) { break; }
            if (0 == m_node_map.count(n0) || 0 == m_node_map.count(n1))
            {
                std::cout << "Edge references node that does not exist in map!" << std::endl;
                break;
            }
            double traversal_time = GeoUtils::greatCircleDistance(*m_node_map.at(n0), *m_node_map.at(n1)) / speed;
            m_edge_map.insert(std::make_pair(edgeId, new Edge(edgeId, n0, n1, Cost(energy, traversal_time))));
        }
    }
}

std::vector<EdgeID> RoutingGraph::getOutgoingEdgesFrom(NodeID node_id)
{
    std::vector<EdgeID> outgoing_edges;
    for (auto kv = m_edge_map.begin(); kv != m_edge_map.end(); ++kv)
    {
        if (kv->second->from == node_id)
        {
            outgoing_edges.push_back(kv->first);
        }
    }
    return outgoing_edges;
}

std::vector<EdgeID> RoutingGraph::getIncomingEdgesTo(NodeID node_id)
{
    std::vector<EdgeID> incoming_edges;
    for (auto kv = m_edge_map.begin(); kv != m_edge_map.end(); ++kv)
    {
        if (kv->second->to == node_id)
        {
            incoming_edges.push_back(kv->first);
        }
    }
    return incoming_edges;
}

/** Returns the cost between two nodes in the graph. If the nodes are not connected by an edge, returns
an infinite edge cost.
**/
Cost RoutingGraph::getCostBetweenNodes(NodeID n0, NodeID n1)
{
    std::vector<EdgeID> outgoing_edges = getOutgoingEdgesFrom(n0);
    for (auto edge_id_ptr = outgoing_edges.begin(); edge_id_ptr != outgoing_edges.end(); ++edge_id_ptr)
    {
        if (m_edge_map.at(*edge_id_ptr)->to == n1)
        {
            return m_edge_map.at(*edge_id_ptr)->edge_cost;
        }
    }
    return Cost::max_cost();
}


