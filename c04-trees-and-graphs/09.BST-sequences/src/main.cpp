#include <bits/stdc++.h>
#include <graph.h>
#include <tree.h>

using namespace std;

shared_ptr<vector<vector<int>>> deriveInputArrays(shared_ptr<TreeNode>& node);
void weave(vector<vector<int>>& sequences, vector<int>& currentSeq, uint32_t elementIndex, uint32_t minIndex);
void swap(vector<int>& arr, uint32_t index1, uint32_t index2);
void shiftRight(vector<int>& arr, uint32_t startIndex, uint32_t endIndex);
void print(vector<int>& arr);

int main()
{
    vector<shared_ptr<GraphNode>> adjacencyList;
    readAdjacencyList(adjacencyList);

    shared_ptr<TreeNode> tree = graphToTreeWithParentPtr(adjacencyList[0]);

    shared_ptr<vector<vector<int>>> inputArrays = deriveInputArrays(tree);
    for (vector<int>& seq : *inputArrays)
    {
        print(seq);
    }

    return 0;
}

shared_ptr<vector<vector<int>>> deriveInputArrays(shared_ptr<TreeNode>& node)
{
    if (!node)
    {
        shared_ptr<vector<vector<int>>> sequence = make_shared<vector<vector<int>>>();
        sequence->push_back(vector<int>());

        return sequence;
    }

    shared_ptr<vector<vector<int>>> leftSequences = deriveInputArrays(node->left);
    shared_ptr<vector<vector<int>>> rightSequences = deriveInputArrays(node->right);
    
    shared_ptr<vector<vector<int>>> finalSequences = make_shared<vector<vector<int>>>();
    for (vector<int>& leftSeq : *leftSequences)
    {
        for (vector<int>& rightSeq : *rightSequences)
        {
            vector<int> currentSeq = leftSeq;
            currentSeq.insert(currentSeq.begin(), rightSeq.begin(), rightSeq.end());

            weave(*finalSequences, currentSeq, leftSeq.size(), 0);
        }
    }
    
    for (vector<int>& seq : *finalSequences)
    {
        seq.insert(seq.begin(), node->val);
    }

    return finalSequences;
}

void weave(vector<vector<int>>& sequences, vector<int>& currentSeq, uint32_t elementIndex, uint32_t minIndex)
{
    sequences.push_back(currentSeq);
    if (elementIndex >= currentSeq.size()) return;

    for (uint32_t i = elementIndex; i >= minIndex + 1; i--)
    {
        swap(currentSeq, i, i - 1);
        weave(sequences, currentSeq, elementIndex + 1, i);
    }

    shiftRight(currentSeq, minIndex, elementIndex);
}

void swap(vector<int>& arr, uint32_t index1, uint32_t index2)
{
    int tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
}

void shiftRight(vector<int>& arr, uint32_t startIndex, uint32_t endIndex)
{
    int startElement = arr[startIndex];
    for (uint32_t i = startIndex; i < endIndex; i++)
    {
        arr[i] = arr[i + 1];
    }

    arr[endIndex] = startElement;
}

void print(vector<int>& arr)
{
    for (uint32_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
