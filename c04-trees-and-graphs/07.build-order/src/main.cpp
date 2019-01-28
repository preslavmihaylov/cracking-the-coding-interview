#include <bits/stdc++.h>
#include <graph.h>

using namespace std;

void preprocessDependencies(vector<shared_ptr<GraphNode>>& adjacencyList);

int main()
{
    vector<shared_ptr<GraphNode>> adjacencyList;
    vector<shared_ptr<GraphNode>> buildOrderList;

    readAdjacencyList(adjacencyList);
    preprocessDependencies(adjacencyList);

    while (adjacencyList.size() != buildOrderList.size())
    {
        bool independentNodeFound = false;
        for (shared_ptr<GraphNode>& node : adjacencyList)
        {
            if (node->dependenciesCnt == 0)
            {
                node->dependenciesCnt = -1;
                independentNodeFound = true;
                buildOrderList.push_back(node);
                for (shared_ptr<GraphNode>& neighbor : node->neighbors)
                {
                    assert(neighbor->dependenciesCnt > 0);
                    neighbor->dependenciesCnt--;
                }

                break;
            }
        }

        if (!independentNodeFound) break;
    }
    
    if (adjacencyList.size() != buildOrderList.size())
    {
        cout << "ERROR" << endl;
    }
    else
    {
        for (shared_ptr<GraphNode>& node : buildOrderList)
        {
            cout << node->id;
            if (node->id != buildOrderList[buildOrderList.size() - 1]->id)
            {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}

void preprocessDependencies(vector<shared_ptr<GraphNode>>& adjacencyList)
{
    for (shared_ptr<GraphNode>& node : adjacencyList)
    {
        for (shared_ptr<GraphNode>& neighbor : node->neighbors)
        {
            neighbor->dependenciesCnt++;
        }
    }
}
