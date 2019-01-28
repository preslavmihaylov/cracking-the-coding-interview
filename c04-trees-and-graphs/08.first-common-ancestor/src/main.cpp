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
        shared_ptr<TreeNode> ancestor1 = this->parent;
        while (ancestor1 != nullptr)
        {
            shared_ptr<TreeNode> ancestor2 = other->parent;
            shared_ptr<TreeNode> commonAncestor = nullptr;
            while (ancestor2 != nullptr)
            {
                if (ancestor1->val == ancestor2->val)
                {
                    commonAncestor = ancestor1;
                    break;
                }

                ancestor2 = ancestor2->parent;
            }

            if (commonAncestor) return commonAncestor;

            ancestor1 = ancestor1->parent;
        }

        return nullptr;
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
