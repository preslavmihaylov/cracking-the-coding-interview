#include <bits/stdc++.h>

using namespace std;

int findMagicIndex(vector<int>& arr);
int findMagicIndex(vector<int>& arr, int start, int end);
int findMagicIndexNonDistinct(vector<int>& arr);
int findMagicIndexNonDistinct(vector<int>& arr, int start, int end);
void readArray(vector<int>& arr);
void printArray(vector<int>& arr);

static inline void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(),
            [] (char ch) { return ch != ' '; }).base(), s.end());
}

int main()
{
    vector<int> arr;
    readArray(arr);
    
    std::sort(arr.begin(), arr.end());
    int magicIndex = findMagicIndexNonDistinct(arr);
    cout << magicIndex << endl;
}

int findMagicIndex(vector<int>& arr)
{
    return findMagicIndex(arr, 0, arr.size());
}

int findMagicIndex(vector<int>& arr, int start, int end)
{
    int mid = (start + end) / 2;
    if (mid >= end) return -1;

    if (arr[mid] == mid)
    {
        return mid;
    }
    else if (arr[mid] > mid)
    {
        return findMagicIndex(arr, start, mid);
    }
    else // if (arr[mid] < mid)
    {
        return findMagicIndex(arr, mid + 1, end);
    }
}

int findMagicIndexNonDistinct(vector<int>& arr)
{
    return findMagicIndexNonDistinct(arr, 0, arr.size());
}

int findMagicIndexNonDistinct(vector<int>& arr, int start, int end)
{
    int mid = (start + end) / 2;
    if (mid >= end) return -1;

    if (arr[mid] == mid)
    {
        return mid;
    }
    
    int upperBoundLeft = mid;
    int lowerBoundRight = mid + 1;
    if (arr[mid] > mid)
    {
        lowerBoundRight = arr[mid];
    }
    else if (arr[mid] < mid)
    {
        upperBoundLeft = arr[mid] + 1;
    }

    int left = findMagicIndexNonDistinct(arr, start, upperBoundLeft);
    int right = findMagicIndexNonDistinct(arr, lowerBoundRight, end);

    return left != -1 ? left : right;
}

void readArray(vector<int>& arr)
{
    string line;
    getline(cin, line);
    rtrim(line);
    istringstream iss(line);

    while (!iss.eof())
    {
        int num;
        iss >> num;

        arr.push_back(num);
    }
}

void printArray(vector<int>& arr)
{
    for (uint32_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}
