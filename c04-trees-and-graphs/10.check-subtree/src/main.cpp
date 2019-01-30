#include <bits/stdc++.h>
#include <graph.h>
#include <tree.h>

using namespace std;

int main()
{
    vector<shared_ptr<GraphNode>> adjacencyList1;
    readAdjacencyList(adjacencyList1);

    vector<shared_ptr<GraphNode>> adjacencyList2;
    readAdjacencyList(adjacencyList2);

    shared_ptr<TreeNode> tree1 = graphToTree(adjacencyList1[0]);
    shared_ptr<TreeNode> tree2 = graphToTree(adjacencyList2[0]);

    if (TreeNode::isSubtree(tree1, tree2))
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }

    return 0;
}

