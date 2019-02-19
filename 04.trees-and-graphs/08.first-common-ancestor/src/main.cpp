#include <bits/stdc++.h>
#include <graph.h>

using namespace std;

struct TreeNode
{
    int val;
    shared_ptr<TreeNode> parent;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;

    TreeNode(int val) : val(val), parent(nullptr), left(nullptr), right(nullptr) {}
    
    // in the task, it is specified the tree is not necessarily BST, 
    // but we will use one nonetheless for easier search 
    // and assume it isn't BST for the actual solution of the problem
    shared_ptr<TreeNode> find(int term)
    {
        if (this->val == term) 
        {
            return make_shared<TreeNode>(*this);
        }
        else if (term < this->val)
        {
            return this->left ? this->left->find(term) : nullptr;
        }
        else
        {
            return this->right ? this->right->find(term) : nullptr;
        }

        return nullptr;
    }

    shared_ptr<TreeNode> firstCommonAncestor(const shared_ptr<TreeNode>& other)
    {
        int myDepth = this->depth();
        int otherDepth = other->depth();

        shared_ptr<TreeNode> first = myDepth <= otherDepth ? make_shared<TreeNode>(*this) : other;
        shared_ptr<TreeNode> second = myDepth <= otherDepth ? other : make_shared<TreeNode>(*this);
        int firstDepth = myDepth <= otherDepth ? myDepth : otherDepth;
        int secondDepth = myDepth <= otherDepth ? otherDepth : myDepth;
       
        while (secondDepth > firstDepth)
        {
            // if the depth is calculated correctly, we shouldn't encounter the root
            assert(second->parent != nullptr);
            second = second->parent;
            secondDepth--;
        }

        while (first != nullptr && second != nullptr && first->val != second->val)
        {
            first = first->parent;
            second = second->parent;
        }

        return (first == nullptr || second == nullptr) ? nullptr : first;
    }

    int depth()
    {
        if (this->parent == nullptr) return 0;

        int depth = 0;
        shared_ptr<TreeNode> parent = this->parent;
        while (parent != nullptr)
        {
            parent = parent->parent;
            depth++;
        }

        return depth;
    }

    void print(string indent)
    {
        if (this->left) this->left->print(indent + "--");

        cout << indent << this->val;
        if (this->parent)
        {
            cout << " P: " << this->parent->val;
        }

        cout << endl;

        if (this->right) this->right->print(indent + "--");
    }
};

shared_ptr<TreeNode> graphToTreeWithParentPtr(shared_ptr<GraphNode>& currentNode);

int main()
{
    vector<shared_ptr<GraphNode>> adjacencyList;
    int node1Id;
    int node2Id;

    readAdjacencyList(adjacencyList);
    cin >> node1Id;
    cin >> node2Id;

    shared_ptr<TreeNode> tree = graphToTreeWithParentPtr(adjacencyList[0]);
    shared_ptr<TreeNode> node1 = tree->find(node1Id);
    shared_ptr<TreeNode> node2 = tree->find(node2Id);
    
    shared_ptr<TreeNode> firstCommonAncestor = node1->firstCommonAncestor(node2);
    
    if (!firstCommonAncestor)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << firstCommonAncestor->val << endl;
    }

    return 0;
}

shared_ptr<TreeNode> graphToTreeWithParentPtr(shared_ptr<GraphNode>& currentNode)
{
    if (currentNode == nullptr) return nullptr;
    assert(currentNode->neighbors.size() <= 2);
    
    shared_ptr<TreeNode> treeNode = make_shared<TreeNode>(currentNode->id);
    treeNode->left = currentNode->neighbors.size() >= 1 ? graphToTreeWithParentPtr(currentNode->neighbors[0]) : nullptr;
    if (treeNode->left)
    {
        treeNode->left->parent = treeNode;
    }

    treeNode->right = currentNode->neighbors.size() == 2 ? graphToTreeWithParentPtr(currentNode->neighbors[1]) : nullptr;
    if (treeNode->right)
    {
        treeNode->right->parent = treeNode;
    }

    return treeNode;
}
