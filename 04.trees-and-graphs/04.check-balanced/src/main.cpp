#include <bits/stdc++.h>
#include <graph.h>

using namespace std;

struct TreeNode
{
    int val;

    // in a production scenario, we should create an add() function for appending to the tree
    // and reset this cached depth. Otherwise, it will be invalid once the tree changes.
    // For the sake of the exercise, this suffices
    int depth = 0;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}

    int getDepth()
    {
        if (this->depth != 0) return this->depth;

        int leftDepth = this->left ? this->left->getDepth() : 0;
        int rightDepth = this->right ? this->right->getDepth() : 0;
        this->depth = max(leftDepth, rightDepth) + 1;

        return this->depth;
    }

    bool isBalanced()
    {
        int leftDepth = this->left ? this->left->getDepth() : 0;
        int rightDepth = this->right ? this->right->getDepth() : 0;
        this->depth = max(leftDepth, rightDepth) + 1;
        
        bool isTreeBalanced = (max(leftDepth, rightDepth) - min(leftDepth, rightDepth)) <= 1;
        bool isLeftTreeBalanced = this->left ? this->left->isBalanced() : true;
        bool isRightTreeBalanced = this->right ? this->right->isBalanced() : true;

        return isTreeBalanced && isLeftTreeBalanced && isRightTreeBalanced;
    }

    void print(string indent)
    {
        if (this->left) this->left->print(indent + "--");

        cout << indent << this->val << endl;

        if (this->right) this->right->print(indent + "--");
    }
};

shared_ptr<TreeNode> graphToTree(shared_ptr<GraphNode>& currentNode);

int main()
{
    vector<shared_ptr<GraphNode>> adjacencyList;
    readAdjacencyList(adjacencyList);
    
    shared_ptr<TreeNode> tree = graphToTree(adjacencyList[0]);
    
    cout << (tree->isBalanced() ? "true" : "false") << endl;
    
    return 0;
}

shared_ptr<TreeNode> graphToTree(shared_ptr<GraphNode>& currentNode)
{
    if (currentNode == nullptr) return nullptr;
    assert(currentNode->neighbors.size() <= 2);
    
    shared_ptr<TreeNode> treeNode = make_shared<TreeNode>(currentNode->id);
    treeNode->left = currentNode->neighbors.size() >= 1 ? graphToTree(currentNode->neighbors[0]) : nullptr;
    treeNode->right = currentNode->neighbors.size() == 2 ? graphToTree(currentNode->neighbors[1]) : nullptr;

    return treeNode;
}
