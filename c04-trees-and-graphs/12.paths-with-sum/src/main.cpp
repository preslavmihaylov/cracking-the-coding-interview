#include <bits/stdc++.h>
#include <graph.h>
#include <tree.h>

using namespace std;

int main()
{
    int target;
    vector<shared_ptr<GraphNode>> adjacencyList;
    readAdjacencyList(adjacencyList);
    cin >> target;
    
    shared_ptr<TreeNode> tree = graphToTree(adjacencyList[0]);
    calculateChildNodesCnt(tree);
    
    int result = TreeNode::pathsCnt2(tree, target);
    cout << result << endl;

    return 0;
}

