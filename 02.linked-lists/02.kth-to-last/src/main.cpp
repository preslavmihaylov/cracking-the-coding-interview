#include <bits/stdc++.h>

using namespace std;

_List_iterator<int> findKthToLast(list<int>& nums, int k) 
{
    int i = 0;
    _List_iterator<int> lastPtr = nums.begin();
    _List_iterator<int> kPtr = nums.begin();
    while (k > 0)
    {
        if (lastPtr == nums.end()) return nums.end();

        ++lastPtr;
        --k;
    }

    while (lastPtr != nums.end()) 
    {
        ++kPtr;
        ++lastPtr;
    }

    return kPtr;
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
    int k;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    cin >> k;

    _List_iterator<int> kPtr = findKthToLast(nums, k);
    printListPartition(kPtr, nums.end());
}
