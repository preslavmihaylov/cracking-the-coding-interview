#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <memory>

class GraphNode
{
public:
    uint32_t id;
    std::vector<std::shared_ptr<GraphNode>> neighbors;

    GraphNode(uint32_t id) : id(id) {}
};

bool routeExists(GraphNode& node1, GraphNode& node2);
bool nodeExists(std::vector<std::shared_ptr<GraphNode>>& adjacencyList, uint32_t nodeId);
std::shared_ptr<GraphNode> findNode(std::vector<std::shared_ptr<GraphNode>>& adjacencyList, uint32_t nodeId);
void appendNeighbor(std::vector<std::shared_ptr<GraphNode>>& adjacencyList, uint32_t nodeId, uint32_t neighborId);
void readAdjacencyList(std::vector<std::shared_ptr<GraphNode>>& adjacencyList);
void printAdjacencyList(std::vector<std::shared_ptr<GraphNode>>& adjacencyList);

#endif
