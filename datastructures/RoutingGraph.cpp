#include "RoutingGraph.hpp"
#include <fstream>
#include <sstream>

RoutingGraph::RoutingGraph(const std::string& filename)
{
    std::ifstream ifs(original_file_name);
    if (!ifs.is_open()) {
        std::cout << "Could not open file for routing graph..." << std::endl;
        return 1;
    }

    std::string line;
    bool nodes = true;
    while (std::getline(infile, line))
    {
        if (line == NODE_EDGE_BREAK)
        {
            nodes = false;
        }

        // Nodes
        if (nodes)
        {
            std::istringstream iss(line);
            NodeID nodeId;
            double lat, lon;
            bool charger;
            if (!(iss >> nodeId >> lat >> lon >> charger)) { break; }
            m_node_map.insert(nodeId, Node(nodeId, lon, lat, charger));
        }

        // Edges
        else
        {
            std::istringstream iss(line);
            EdgeID edgeId;
            NodeID n0, n1;
            if (!(iss >> edgeId >> n0 >> n1)) { break; }
            m_edge_map.insert(edgeId, Edge(edgeId, n0, n1));
        }
    }
}