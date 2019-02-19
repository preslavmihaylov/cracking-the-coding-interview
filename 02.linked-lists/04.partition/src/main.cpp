#include <bits/stdc++.h>

using namespace std;

void partition(list<int>& nums, int pivot)
{
    _List_iterator<int> it = nums.begin();
    while (it != nums.end())
    {
        if (*it < pivot)
        {
            nums.insert(nums.begin(), *it);
            _List_iterator<int> toDelete = it;
            ++it;

            nums.erase(toDelete);
        }
        else
        {
            ++it;
        }
    }
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
    int pivot;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    cin >> pivot;

    partition(nums, pivot);
    printListPartition(nums.begin(), nums.end());
}

