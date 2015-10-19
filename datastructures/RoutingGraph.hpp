#include <string>
#include <vector>
#include <unordered_map>

#include "Cost.hpp"
#include "Edge.hpp"
#include "Node.hpp"

#include <map>

class RoutingGraph
{
public:
    RoutingGraph(const std::string& filename);
    Cost getCostBetweenNodes(NodeID n0, NodeID n1);
    void setNodeCost(NodeID, const Cost& cost);
    std::vector<EdgeID> getOutgoingEdgesFrom(NodeID node_id);
    std::vector<EdgeID> getIncomingEdgesTo(NodeID node_id);

private:
    std::unordered_map<NodeID, Node*> m_node_map;
    std::unordered_map<EdgeID, Edge*> m_edge_map;
    std::unordered_map<NodeID, std::vector<Edge> > m_node_to_edges;
};