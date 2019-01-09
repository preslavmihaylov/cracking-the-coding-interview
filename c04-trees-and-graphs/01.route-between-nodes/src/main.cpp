#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    uint32_t id;
    vector<shared_ptr<Node>> neighbors;

    Node(uint32_t id) : id(id) {}
};

bool nodeExists(vector<shared_ptr<Node>>& adjacencyList, uint32_t nodeId);
shared_ptr<Node> findNode(vector<shared_ptr<Node>>& adjacencyList, uint32_t nodeId);
void appendNeighbor(vector<shared_ptr<Node>>& adjacencyList, uint32_t nodeId, uint32_t neighborId);
void readAdjacencyList(vector<shared_ptr<Node>>& adjacencyList);
void printAdjacencyList(vector<shared_ptr<Node>>& adjacencyList);

int main()
{
    vector<shared_ptr<Node>> adjacencyList;
    readAdjacencyList(adjacencyList);
    printAdjacencyList(adjacencyList);
}

bool nodeExists(vector<shared_ptr<Node>>& adjacencyList, uint32_t nodeId)
{
    return find_if(adjacencyList.begin(), 
                   adjacencyList.end(), 
                   [&](const shared_ptr<Node>& n) { return n->id == nodeId; }) != adjacencyList.end();
}

shared_ptr<Node> findNode(vector<shared_ptr<Node>>& adjacencyList, uint32_t nodeId)
{
    return *find_if(adjacencyList.begin(), 
                   adjacencyList.end(), 
                   [&](const shared_ptr<Node>& n) { return n->id == nodeId; });
}

void appendNeighbor(vector<shared_ptr<Node>>& adjacencyList, uint32_t nodeId, uint32_t neighborId)
{
    if (!nodeExists(adjacencyList, nodeId))
    {
        adjacencyList.push_back(make_shared<Node>(nodeId));
    }
    
    if (!nodeExists(adjacencyList, neighborId))
    {
        adjacencyList.push_back(make_shared<Node>(neighborId));
    }

    shared_ptr<Node> node = findNode(adjacencyList, nodeId);
    vector<shared_ptr<Node>>& neighbors = node->neighbors;
    shared_ptr<Node> newNeighbor = findNode(adjacencyList, neighborId);

    if (!nodeExists(neighbors, newNeighbor->id))
    {
        neighbors.push_back(newNeighbor);
        // uncomment for undirected graph
        // newNeighbor->neighbors.push_back(node);
    }
}

void readAdjacencyList(vector<shared_ptr<Node>>& adjacencyList)
{
    string line;
    int linesCnt;

    cin >> linesCnt;
    getline(cin, line);
    for (int i = 0; i < linesCnt; i++)
    {
        getline(cin, line);

        istringstream iss(line);
        uint32_t nodeId;
        string arrowSymbol;
        uint32_t adjacentNodeId;

        iss >> nodeId;

        // discard arrow symbol
        iss >> arrowSymbol;

        while (!iss.eof())
        {
            iss >> adjacentNodeId;
            appendNeighbor(adjacencyList, nodeId, adjacentNodeId);
        }
    }
}

void printAdjacencyList(vector<shared_ptr<Node>>& adjacencyList)
{
    for (shared_ptr<Node>& node : adjacencyList)
    {
        cout << node->id << " -> ";
        for (shared_ptr<Node>& neighbor : node->neighbors)
        {
            cout << neighbor->id << " ";
        }

        cout << endl;
    }
}
