#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& elements, int term);
int search(vector<int>& elements, int term, int start, int end);

int main()
{
    vector<int> elements;
    int term;

    string line;
    getline(cin, line);
    istringstream iss(line);
    while (!iss.eof())
    {
        int element;
        iss >> element;

        elements.push_back(element);
    }

    cin >> term;
    
    int result = search(elements, term);
    cout << result << endl;
}

int search(vector<int>& elements, int term)
{
    return search(elements, term, 0, elements.size());
}

int search(vector<int>& elements, int term, int start, int end)
{
    if (start >= end) return -1;

    int mid = (start + end) / 2;
    if (elements[mid] == 0)
    {
        int left = mid - 1;
        int right = mid + 1;
        while (true)
        {
            if (left < start && right >= end)
            {
                return -1;
            }
            else if (left >= start && elements[left] != 0)
            {
                mid = left;
                break;
            }
            else if (right < end && elements[right] != 0)
            {
                mid = right;
                break;
            }

            left--;
            right++;
        }
    }
    
    if (elements[mid] == term)
    {
        return mid;
    }
    else if (elements[mid] > term)
    {
        return search(elements, term, start, mid);
    }
    else
    {
        return search(elements, term, mid + 1, end);
    }
}

