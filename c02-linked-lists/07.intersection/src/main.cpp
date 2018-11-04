#include <bits/stdc++.h>

using namespace std;

bool doIntersect(list<int>& fList, list<int>& sList, int& intersection)
{
    int fLength = fList.size();
    int sLength = sList.size();

    auto fIter = fList.begin();
    auto sIter = sList.begin();
    while (fLength != sLength)
    {
        if (fLength > sLength)
        {
            ++fIter;
            fLength--;
        }
        else
        {
            ++sIter;
            sLength--;
        }
    }

    while (*fIter != *sIter)
    {
        ++fIter;
        ++sIter;
    }
    
    bool res = fIter != fList.end() && sIter != sList.end();
    intersection = res ? *fIter : intersection;

    return res;
}

void readList(list<int>& nums)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;

        nums.push_back(val);
    }
}

int main()
{
    list<int> fList;
    list<int> sList;
    
    readList(fList);
    readList(sList);
    
    int intersection = 0;
    cout << (doIntersect(fList, sList, intersection) ? "true" : "false") << endl;
    cout << intersection << endl;
}
