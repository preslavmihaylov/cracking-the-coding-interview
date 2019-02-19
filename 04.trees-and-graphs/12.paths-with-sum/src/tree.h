#ifndef _TREE_H
#define _TREE_H

#include <memory>
#include <vector>
#include <string>
#include <graph.h>
#include <iostream>
#include <cassert>

struct TreeNode
{
    int val;
    bool oneNodePathFound;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    std::shared_ptr<TreeNode> parent;
    int childrenLeftCnt;
    int childrenRightCnt;

    TreeNode(int val) : val(val), oneNodePathFound(false), left(nullptr), right(nullptr), childrenLeftCnt(0), childrenRightCnt(0) {}
   
    static int pathsCnt(std::shared_ptr<TreeNode> node, int target)
    {
        if (!node) return 0;
//        std::cout << "VAL: " << node->val 
//                  << " TARGET: " << target 
//                  << std::endl;

        int result = 0;
        if (node->val == target)
        {
//            std::cout << "HIT TARGET!" << std::endl;
            result++;
        }

        return result +
               TreeNode::pathsCntImpl(node->left, target, target - node->val) + 
               TreeNode::pathsCntImpl(node->right, target, target - node->val);
    }
    
    static int pathsCnt2(std::shared_ptr<TreeNode> node, int target)
    {
        std::vector<int> paths;
        return TreeNode::pathsCnt2Impl(node, target, paths);
    }

    static int pathsCnt2Impl(std::shared_ptr<TreeNode> node, int target, std::vector<int>& paths)
    {
        if (!node) return 0;

        int result = 0;
        std::vector<int> pathsLeft;
        result += pathsCnt2Impl(node->left, target, pathsLeft);

        std::vector<int> pathsRight;
        result += pathsCnt2Impl(node->right, target, pathsRight);

        for (int path : pathsLeft)
        {
            paths.push_back(path + node->val);
            if (path + node->val == target)
            {
                result++;
            }
        }
        
        paths.push_back(node->val);
        if (node->val == target)
        {
            result++;
        }

        for (int path : pathsRight)
        {
            paths.push_back(path + node->val);
            if (path + node->val == target)
            {
                result++;
            }
        }

        return result;
    }

    void print(std::string indent)
    {
        if (this->left) this->left->print(indent + "--");

        std::cout << indent << this->val << std::endl;

        if (this->right) this->right->print(indent + "--");
    }

private:
    static int pathsCntImpl(std::shared_ptr<TreeNode> node, int target, int leftover)
    {
        if (!node) return 0;
//        std::cout << "VAL: " << node->val 
//                  << " TARGET: " << target 
//                  << " LEFTOVER: " << leftover
//                  << std::endl;

        int result = 0;
        if (node->val == target && !node->oneNodePathFound)
        {
//            std::cout << "HIT TARGET!" << std::endl;
            result++;
            node->oneNodePathFound = true;
        }

        if (node->val == leftover)
        {
//            std::cout << "HIT LEFTOVER!" << std::endl;
            result++;
        }

        return result +
               TreeNode::pathsCntImpl(node->left, target, leftover - node->val) + 
               TreeNode::pathsCntImpl(node->left, target, target - node->val) + 
               TreeNode::pathsCntImpl(node->right, target, leftover - node->val) + 
               TreeNode::pathsCntImpl(node->right, target, target - node->val);
    }
};

std::shared_ptr<TreeNode> graphToTreeWithParentPtr(std::shared_ptr<GraphNode>& currentNode);
std::shared_ptr<TreeNode> graphToTree(std::shared_ptr<GraphNode>& currentNode);
int calculateChildNodesCnt(std::shared_ptr<TreeNode>& treeNode);

#endif
