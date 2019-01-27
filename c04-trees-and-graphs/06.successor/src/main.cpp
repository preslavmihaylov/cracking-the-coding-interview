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

    shared_ptr<TreeNode> getSuccessor()
    {
        if (this->right)
        {
            return findLeftmostChild(this->right);
        }
        else
        {
            return findNextRightParent(make_shared<TreeNode>(*this));
        }
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

private:
    shared_ptr<TreeNode> findLeftmostChild(shared_ptr<TreeNode> node)
    {
        return node->left ? findLeftmostChild(node->left) : node;
    }

    shared_ptr<TreeNode> findNextRightParent(shared_ptr<TreeNode> node)
    {
        if (!node->parent || (node->parent->left && node->parent->left->val == node->val))
        {
            return node->parent;
        }
        else
        {
            return findNextRightParent(node->parent);
        }
    }
};

shared_ptr<TreeNode> graphToTreeWithParentPtr(shared_ptr<GraphNode>& currentNode);

int main()
{
    vector<shared_ptr<GraphNode>> adjacencyList;
    int term;
    readAdjacencyList(adjacencyList);
    cin >> term;

    shared_ptr<TreeNode> tree = graphToTreeWithParentPtr(adjacencyList[0]);
    shared_ptr<TreeNode> node = tree->find(term);
    shared_ptr<TreeNode> successor = node->getSuccessor();

    if (successor)
    {
        cout << successor->val << endl;
    }
    else
    {
        cout << "NONE" << endl;
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
