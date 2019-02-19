#ifndef _TREE_H
#define _TREE_H

#include <memory>
#include <string>
#include <graph.h>
#include <iostream>
#include <cassert>

struct TreeNode
{
    int val;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    std::shared_ptr<TreeNode> parent;
    int childrenLeftCnt;
    int childrenRightCnt;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr), childrenLeftCnt(0), childrenRightCnt(0) {}
   
    // normally, I would implement the seed to be calculated internally,
    // but I have exposed it here in order for the function to be testable
    std::shared_ptr<TreeNode> getRandomNode(int seed)
    {
        int nodesCnt = this->childrenLeftCnt + this->childrenRightCnt + 1;
        if (seed >= nodesCnt || seed < 0) return nullptr;
        
        if (seed < childrenLeftCnt)
        {
            // cannot be null if childrenLeftCnt is non-zero
            assert(this->left != nullptr);

            return this->left->getRandomNode(seed);
        }
        else if (seed == childrenLeftCnt)
        {
            return std::make_shared<TreeNode>(*this);
        }
        else // if (seed > childrenLeftCnt)
        {
            // cannot be null if seed is in childrenRightCnt range
            assert(this->right != nullptr);

            return this->right->getRandomNode(seed - childrenLeftCnt - 1);
        }
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
int calculateChildNodesCnt(std::shared_ptr<TreeNode>& treeNode);

#endif
