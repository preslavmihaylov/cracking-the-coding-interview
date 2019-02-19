#include <bits/stdc++.h>

using namespace std;

void eraseDups(list<int>& nums) 
{
    int i = 0;
    unordered_set<int> dups;
    for (_List_iterator<int> it = nums.begin(); it != nums.end();) {
        if (dups.find(*it) != dups.end())
        {
            _List_iterator<int> toDelete = it;
            it = ++it;
            nums.erase(toDelete);
        }
        else
        {
            dups.insert(*it);
            it = ++it;
        }

        i++;
    }
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
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    eraseDups(nums);
    printList(nums);
}
