#include <bits/stdc++.h>

using namespace std;

class Listy
{
public:
    void push_back(int element)
    {
        elements.push_back(element);
    }

    int operator[](int i) const 
    {
        if (i >= elements.size()) return -1;

        return elements[i]; 
    }

private:
    vector<int> elements;
};

int sortedSearchNoSize(Listy& elements, int term);
int sortedSearch(Listy& elements, int term, int start, int end);
int findLength(Listy& elements, int start, int end);

int main()
{
    Listy elements;
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
    
    int result = sortedSearchNoSize(elements, term);
    cout << result << endl;
}

int sortedSearchNoSize(Listy& elements, int term)
{
    int length = -1;

    int lastElementIndex = 0;
    int currentElementIndex = 1;
    while (length == -1)
    {
        int element = elements[currentElementIndex - 1];
        if (element != -1)
        {
            if (term <= element)
            {
                return sortedSearch(elements, term, lastElementIndex, currentElementIndex);
            }

            lastElementIndex = currentElementIndex - 1;
            currentElementIndex *= 2;
        }
        else
        {
            length = findLength(elements, lastElementIndex, currentElementIndex - 1);
        }
    }

    return sortedSearch(elements, term, lastElementIndex, length);
}

int sortedSearch(Listy& elements, int term, int start, int end)
{
    if (start >= end) return -1;
    
    int mid = (start + end) / 2;
    if (elements[mid] == term)
    {
        return mid;
    }
    else if (elements[mid] > term)
    {
        return sortedSearch(elements, term, start, mid);
    }
    else
    {
        return sortedSearch(elements, term, mid + 1, end);
    }
}

int findLength(Listy& elements, int start, int end)
{
    if (start >= end) return 0;

    int mid = (start + end) / 2;
    if (elements[mid] != -1 && elements[mid + 1] == -1)
    {
        return mid + 1;
    }
    else if (elements[mid] == -1)
    {
        return findLength(elements, start, mid);
    }
    else // if (elements[mid] != -1)
    {
        return findLength(elements, mid, end);
    }
}

