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
    int length = 1;
    while (elements[length - 1] != -1 && term > elements[length - 1])
    {
        length *= 2;
    }

    return sortedSearch(elements, term, length / 2, length);
}

int sortedSearch(Listy& elements, int term, int start, int end)
{
    if (start >= end) return -1;
    
    int mid = (start + end) / 2;
    if (elements[mid] == term)
    {
        return mid;
    }
    else if (elements[mid] > term || elements[mid] == -1)
    {
        return sortedSearch(elements, term, start, mid);
    }
    else
    {
        return sortedSearch(elements, term, mid + 1, end);
    }
}

