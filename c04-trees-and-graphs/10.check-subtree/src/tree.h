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
    std::shared_ptr<TreeNode> parent;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    
    static bool isSubtree(std::shared_ptr<TreeNode> tree, std::shared_ptr<TreeNode> other)
    {
        if (!tree) return false;
        if (!other) return true;
        
        return TreeNode::areEqual(tree, other) || 
               isSubtree(tree->left, other) || 
               isSubtree(tree->right, other);
    }

    static bool areEqual(std::shared_ptr<TreeNode> first, std::shared_ptr<TreeNode> second)
    {
        if (!first && !second) return true;
        if (!first || !second) return false;
        
        return first->val == second->val && 
               areEqual(first->left, second->left) && 
               areEqual(first->right, second->right);
    }

    void print(std::string indent)
    {
        if (this->left) this->left->print(indent + "--");

        std::cout << indent << this->val << std::endl;

        if (this->right) this->right->print(indent + "--");
    }
};

std::shared_ptr<TreeNode> graphToTreeWithParentPtr(std::shared_ptr<GraphNode>& currentNode);
std::shared_ptr<TreeNode> graphToTree(std::shared_ptr<GraphNode>& currentNode);

#endif
