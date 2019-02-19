#include <bits/stdc++.h>

using namespace std;

bool isPalindromeRec(list<int>& nums, int length, _List_iterator<int> head, _List_iterator<int>& bHead)
{
    if (length == 0)
    {
        bHead = head;
        return true;
    }
    else if (length == 1)
    {
        bHead = ++head;
        return true;
    }

    _List_iterator<int> opposite = nums.begin();
    _List_iterator<int> nextHead = head;
    ++nextHead;

    bool res = isPalindromeRec(nums, length - 2, nextHead, opposite);
    bool areEqual = *head == *opposite;

    bHead = ++opposite;
    return res && areEqual;
}

bool isPalindrome(list<int>& nums)
{
    auto iter = nums.begin();
    auto runner = nums.begin();

    stack<int> numStack;
    while (iter != nums.end())
    {
        if (runner != nums.end())
        {
            ++runner;
            if (runner == nums.end())
            {
                // odd length. skip middle
                ++iter;
                continue;
            }
            
            ++runner;

            numStack.push(*iter);
        }
        else
        {
            int val = numStack.top();
            numStack.pop();

            if (val != *iter) return false;
        }

        ++iter;
    }
    
    return true;
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
    
    // Iterative solution:
    // cout << (isPalindrome(nums) ? "true" : "false") << endl;

    // Recursive solution:
    auto dummy = nums.end();
    cout << (isPalindromeRec(nums, nums.size(), nums.begin(), dummy) ? "true" : "false") << endl;
}

