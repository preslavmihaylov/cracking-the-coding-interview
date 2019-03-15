#include <bits/stdc++.h>

using namespace std;

void readInput(vector<int>& a, vector<int>& b);
void sortedMerge(vector<int>& a, vector<int>& b);
void printArr(vector<int>& arr);

int main()
{
    vector<int> a;
    vector<int> b;
    readInput(a, b);

    sortedMerge(a, b);
    printArr(a);
}

void readInput(vector<int>& a, vector<int>& b)
{
    string line;
    getline(cin, line);
    istringstream aInputStream(line);
    while (!aInputStream.eof())
    {
        int elem;
        aInputStream >> elem;

        a.push_back(elem);
    }

    getline(cin, line);
    istringstream bInputStream(line);

    while (!bInputStream.eof())
    {
        int elem;
        bInputStream >> elem;

        a.push_back(0);
        b.push_back(elem);
    }
}

void sortedMerge(vector<int>& a, vector<int>& b)
{
    int aRight = -1;
    for (int el : a)
    {
        if (el == 0) break;

        aRight++;
    }
    
    int bRight = b.size() - 1;
    int nextElemIndex = a.size() - 1;

    while (bRight >= 0)
    {
        if (a[aRight] > b[bRight])
        {
            a[nextElemIndex--] = a[aRight--];
        }
        else
        {
            a[nextElemIndex--] = b[bRight--];
        }
    }
}

void printArr(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
        {
            cout << " ";
        }
    }

    cout << endl;
}

