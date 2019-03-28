#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
    int val;
    int leftChildrenCnt;
    int rightChildrenCnt;
    shared_ptr<TreeNode> left = nullptr;
    shared_ptr<TreeNode> right = nullptr;

public:
    TreeNode(int val) : val(val), leftChildrenCnt(0), rightChildrenCnt(0), left(nullptr), right(nullptr) {}

    void insert(TreeNode&& other) { insert(other); }
    void insert(TreeNode& other)
    {
        if (this->val >= other.val)
        {
            if (!this->left)
            {
                this->left = make_shared<TreeNode>(other);
            }
            else
            {
                this->left->insert(other);
            }
        }
        else
        {
            if (!this->right)
            {
                this->right = make_shared<TreeNode>(other);
            }
            else
            {
                this->right->insert(other);
            }
        }
        
        this->leftChildrenCnt = 
            this->left ? this->left->leftChildrenCnt + this->left->rightChildrenCnt + 1 : 0;
        this->rightChildrenCnt = 
            this->right ? this->right->leftChildrenCnt + this->right->rightChildrenCnt + 1 : 0;
    }

    int getRank(int val)
    {
        if (this->val == val)
        {
            return this->leftChildrenCnt;
        }
        else if (this->val > val)
        {
            if (this->left)
            {
                return this->left->getRank(val);
            }
            else
            {
                return 0;
            }
        }
        else
        {
            int result = this->leftChildrenCnt + 1;
            if (this->right)
            {
                result += this->right->getRank(val);
            }

            return result;
        }
    }

    void print() const { print(""); }
    void print(const string&& indent) const { print(indent); }
    void print(const string& indent) const
    {
        if (this->left) this->left->print(indent + "  ");
        cout << indent << val << endl;
        if (this->right) this->right->print(indent + "  ");
    }
};

void insert(shared_ptr<TreeNode>& root, string param);
void printRank(shared_ptr<TreeNode>& root, string param);
void printTree(shared_ptr<TreeNode>& root);

int main(int argc, char *argv[])
{
    shared_ptr<TreeNode> root = nullptr;

    string line;
    cin >> line;
    while (line != "end")
    {
        string cmd = line;
        string param;
        
        if (cmd == "insert")
        {
            cin >> param;
            insert(root, param);
        }
        else if (cmd == "rank")
        {
            cin >> param;
            printRank(root, param);
        }
        /* for debugging purposes */
        else if (cmd == "print")
        {
            printTree(root);
        }
        else
        {
            throw invalid_argument("unrecognized cmd");
        }

        cin >> line;
    }
}

void insert(shared_ptr<TreeNode>& root, string param)
{
    int val = stoi(param);
    if (!root) 
    {
        root = make_shared<TreeNode>(val);
    }
    else
    {
        root->insert(TreeNode(val));
    }
}

void printRank(shared_ptr<TreeNode>& root, string param)
{
    int val = stoi(param);
    cout << root->getRank(val) << endl;
}

void printTree(shared_ptr<TreeNode>& root)
{
    root->print();
}
