#include <bits/stdc++.h>

using namespace std;

enum Direction 
{
    DIR_LEFT,
    DIR_RIGHT,
    DIR_BOTH
};

int searchRotated(vector<int>& arr, int term);
int findMinPoint(vector<int>& arr, int start, int end, int lastMid);
int searchRotated(vector<int>& arr, int term, int start, int end);

int main()
{
    vector<int> arr;
    int term;
    
    string line;
    getline(cin, line);
    istringstream iss(line);

    while (!iss.eof())
    {
        int num;
        iss >> num;

        arr.push_back(num);
    }

    cin >> term;

    int result = searchRotated(arr, term);
    cout << result << endl;
}

int searchRotated(vector<int>& arr, int term)
{
    return searchRotated(arr, term, 0, arr.size());
}

int searchRotated(vector<int>& arr, int term, int start, int end)
{
    if (start >= end) return -1;

    int mid = (start + end) / 2;
    if (arr[mid] == term)
    {
        return mid;
    }
    
    Direction direction = DIR_LEFT;
    if (arr[start] < arr[mid])
    {
        if (term >= arr[start] && term < arr[mid])
        {
            direction = DIR_LEFT;
        }
        else
        {
            direction = DIR_RIGHT;
        }
    }
    else if (arr[mid] < arr[end - 1]) 
    {
        if (term > arr[mid] && term <= arr[end - 1])
        {
            direction = DIR_RIGHT;
        }
        else
        {
            direction = DIR_LEFT;
        }
    }
    else if (arr[mid] == arr[start])
    {
        direction = DIR_BOTH;
    }

    if (direction == DIR_LEFT)
    {
        return searchRotated(arr, term, start, mid);
    }
    else if (direction == DIR_RIGHT)
    {
        return searchRotated(arr, term, mid + 1, end);
    }
    else // if (direction == DIR_BOTH)
    {
        int index = searchRotated(arr, term, start, mid);

        return index != -1 ? index : searchRotated(arr, term, mid + 1, end);
    }
}

