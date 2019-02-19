#include <bits/stdc++.h>
#include <graph.h>
#include <tree.h>

using namespace std;

int main()
{
    int seed;
    vector<shared_ptr<GraphNode>> adjacencyList;
    readAdjacencyList(adjacencyList);
    cin >> seed;

    shared_ptr<TreeNode> tree = graphToTree(adjacencyList[0]);
    calculateChildNodesCnt(tree);

    shared_ptr<TreeNode> res = tree->getRandomNode(seed);
    
    if (res)
    {
        cout << res->val << endl;
    }
    else
    {
        cout << "NULL" << endl;
    }

    return 0;
}

