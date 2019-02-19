#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    shared_ptr<Node> left;
    shared_ptr<Node> right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}

    void print(string indent)
    {
        if (this->left) this->left->print(indent + "--");

        cout << indent << this->val << endl;

        if (this->right) this->right->print(indent + "--");
    }
};

shared_ptr<Node> constructTree(vector<int>& arr);
shared_ptr<Node> constructTreeImpl(vector<int>& arr, int start, int end);

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
    shared_ptr<Node> root = constructTree(arr);

    root->print("");
    return 0;
}

shared_ptr<Node> constructTree(vector<int>& arr)
{
    return constructTreeImpl(arr, 0, arr.size());
}

shared_ptr<Node> constructTreeImpl(vector<int>& arr, int start, int end)
{
    if (start >= end) return nullptr;
    
    int mid = (start + end) / 2;

    shared_ptr<Node> node = make_shared<Node>(arr[mid]);
    node->left = constructTreeImpl(arr, start, mid);
    node->right = constructTreeImpl(arr, mid + 1, end);

    return node;
}

