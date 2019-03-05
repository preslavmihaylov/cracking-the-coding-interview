#include <bits/stdc++.h>
#include <pstructs/stack.h>

using namespace std;

void hanoi(int disksCnt, 
           pstructs::stack<int>& src, 
           pstructs::stack<int>& buffer, 
           pstructs::stack<int>& dest);

int main()
{
    pstructs::stack<int> src, buffer, dest;
    int disksCnt;
    cin >> disksCnt;

    for (int i = disksCnt; i > 0; i--)
    {
        src.push(i);
    }

    hanoi(disksCnt, src, buffer, dest);
}

void moveDisk(pstructs::stack<int>& src, pstructs::stack<int>& dest)
{
    if (dest.getSize() > 0)
    {
        assert(dest.peek() > src.peek());
    }

    dest.push(src.pop());
}

void hanoi(int disksCnt, 
           pstructs::stack<int>& src, 
           pstructs::stack<int>& buffer, 
           pstructs::stack<int>& dest)
{
    if (disksCnt <= 0) return;

    hanoi(disksCnt - 1, src, dest, buffer);
    moveDisk(src, dest);
    hanoi(disksCnt - 1, buffer, src, dest);
}

