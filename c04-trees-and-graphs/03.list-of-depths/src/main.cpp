#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}

    vector<vector<int> > listOfDepths()
    {
        vector<vector<int> > depths;
        this->listOfDepthsImpl(depths, 0);

        return depths;
    }

private:
    void listOfDepthsImpl(vector<vector<int> >& depths, size_t level)
    {
        if (level >= depths.size())
        {
            // it shouldn't be possible to skip depths
            assert(level == depths.size());

            depths.push_back(vector<int>());
        }

        depths[level].push_back(this->val);

        if (this->left) this->left->listOfDepthsImpl(depths, level + 1);
        if (this->right) this->right->listOfDepthsImpl(depths, level + 1);
    }
};

shared_ptr<TreeNode> constructTree(vector<int>& arr);
shared_ptr<TreeNode> constructTreeImpl(vector<int>& arr, int start, int end);

int main()
{
    int N;
    vector<int> arr;
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;

        arr.push_back(val);
    }
    
    std::sort(arr.begin(), arr.end());
    shared_ptr<TreeNode> root = constructTree(arr);
    
    vector<vector<int> > depths = root->listOfDepths();
    for (auto& depth : depths)
    {
        for (auto& el : depth)
        {
            if (el != depth[depth.size() - 1])
            {
                cout << el << " ";
            }
            else
            {
                cout << el;
            }
        }

        cout << endl;
    }

    return 0;
}

shared_ptr<TreeNode> constructTree(vector<int>& arr)
{
    return constructTreeImpl(arr, 0, arr.size());
}

shared_ptr<TreeNode> constructTreeImpl(vector<int>& arr, int start, int end)
{
    if (start >= end) return nullptr;
    
    int mid = (start + end) / 2;

    shared_ptr<TreeNode> node = make_shared<TreeNode>(arr[mid]);
    node->left = constructTreeImpl(arr, start, mid);
    node->right = constructTreeImpl(arr, mid + 1, end);

    return node;
}
