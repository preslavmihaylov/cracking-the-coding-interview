#ifndef _TREE_H
#define _TREE_H

#include <memory>
#include <string>
#include <graph.h>
#include <iostream>

struct TreeNode
{
    int val;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    
    void print(std::string indent)
    {
        if (this->left) this->left->print(indent + "--");

        std::cout << indent << this->val << std::endl;

        if (this->right) this->right->print(indent + "--");
    }
};

std::shared_ptr<TreeNode> graphToTreeWithParentPtr(std::shared_ptr<GraphNode>& currentNode);

#endif
