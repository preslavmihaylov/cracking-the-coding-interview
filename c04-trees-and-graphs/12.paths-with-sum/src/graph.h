#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <memory>

class GraphNode
{
public:
    int id;
    std::vector<std::shared_ptr<GraphNode>> neighbors;

    GraphNode(int id) : id(id) {}
};

bool routeExists(GraphNode& node1, GraphNode& node2);
bool nodeExists(std::vector<std::shared_ptr<GraphNode>>& adjacencyList, int nodeId);
std::shared_ptr<GraphNode> findNode(std::vector<std::shared_ptr<GraphNode>>& adjacencyList, int nodeId);
void appendNeighbor(std::vector<std::shared_ptr<GraphNode>>& adjacencyList, int nodeId, int neighborId);
void readAdjacencyList(std::vector<std::shared_ptr<GraphNode>>& adjacencyList);
void printAdjacencyList(std::vector<std::shared_ptr<GraphNode>>& adjacencyList);

#endif
