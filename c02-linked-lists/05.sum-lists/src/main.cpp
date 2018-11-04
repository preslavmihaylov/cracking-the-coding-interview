#include <bits/stdc++.h>

using namespace std;

list<int> sumLists(list<int>& firstNumList, list<int>& secondNumList)
{
    list<int> res;
    
    _List_iterator<int> fIter = firstNumList.begin();
    _List_iterator<int> sIter = secondNumList.begin();
    int carry = 0;

    while (fIter != firstNumList.end() && sIter != secondNumList.end())
    {
        int val = *fIter + *sIter + carry;
        res.push_back(val % 10);
        
        carry = val >= 10 ? 1 : 0;
        ++fIter;
        ++sIter;
    }

    // add remaining digits
    while (fIter != firstNumList.end())
    {
        // this loop excludes the other one being executed
        assert(sIter == secondNumList.end());
        
        int val = *fIter + carry;
        res.push_back(val % 10);

        carry = val >= 10 ? 1 : 0;
        ++fIter;
    }

    // add remaining digits
    while (sIter != secondNumList.end())
    {
        // this loop excludes the other one being executed
        assert(fIter == firstNumList.end());

        int val = *sIter + carry;
        res.push_back(val % 10);

        carry = val >= 10 ? 1 : 0;
        ++sIter;
    }
    
    if (carry == 1) res.push_back(1);

    return res;
}

void printNumList(list<int>& numList)
{
    for (auto iter = numList.rbegin(); iter != numList.rend(); ++iter)
    {
        cout << *iter;
    }

    cout << endl;
}

void turnNumToList(int num, list<int>& numList)
{
    while (num > 0)
    {
        numList.push_back(num % 10); 
        num /= 10;
    }
}

int main()
{
    list<int> firstNumList;
    list<int> secondNumList;
    int firstNum;
    int secondNum;

    cin >> firstNum >> secondNum;
    turnNumToList(firstNum, firstNumList);
    turnNumToList(secondNum, secondNumList);

    list<int> res = sumLists(firstNumList, secondNumList);
    printNumList(res);
}

