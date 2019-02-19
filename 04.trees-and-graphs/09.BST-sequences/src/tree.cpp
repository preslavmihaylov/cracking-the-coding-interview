#include <cassert>
#include <tree.h>

using namespace std;

shared_ptr<TreeNode> graphToTreeWithParentPtr(shared_ptr<GraphNode>& currentNode)
{
    if (currentNode == nullptr) return nullptr;
    assert(currentNode->neighbors.size() <= 2);
    
    shared_ptr<TreeNode> treeNode = make_shared<TreeNode>(currentNode->id);
    treeNode->left = currentNode->neighbors.size() >= 1 ? graphToTreeWithParentPtr(currentNode->neighbors[0]) : nullptr;
    treeNode->right = currentNode->neighbors.size() == 2 ? graphToTreeWithParentPtr(currentNode->neighbors[1]) : nullptr;

    return treeNode;
}
