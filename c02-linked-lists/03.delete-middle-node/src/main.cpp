#include <bits/stdc++.h>

using namespace std;

void deleteMiddleNode(list<int>& nums, _List_iterator<int> node) 
{
    if (node == nums.end()) return;

    _List_iterator<int> oldNode = node;
    ++node;

    if (node == nums.end()) return;

    *oldNode = *node;
    nums.erase(node);
}

void printListPartition(_List_iterator<int> begin, _List_iterator<int> end)
{
    if (begin == end) return;

    cout << *begin;
    ++begin;

    for (; begin != end; ++begin)
    {
        cout << " " << *begin;
    }

    cout << endl;
}

void printList(list<int>& nums)
{
    int i = 0;
    for (_List_iterator<int> it = nums.begin(); it != nums.end(); ++it) {
        cout << *it;
        if (i != nums.size() - 1) {
            cout << " ";
        }

        i++;
    }

    cout << endl;
}

int main()
{
    list<int> nums;
    int N;
    int midNodeIndex;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    cin >> midNodeIndex;

    _List_iterator<int> middleNode = nums.end();
    for (_List_iterator<int> it = nums.begin(); it != nums.end(); ++it)
    {
        if (midNodeIndex == 0)
        {
            middleNode = it;
            break;
        }

        midNodeIndex--;
    }

    deleteMiddleNode(nums, middleNode);
    printListPartition(nums.begin(), nums.end());
}
