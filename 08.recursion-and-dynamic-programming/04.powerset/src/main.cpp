#include <bits/stdc++.h>

using namespace std;

vector<int> readSet();
void powerset(vector<int>&& set);
void powerset(vector<int>& set);
void genSubsets(vector<int>& set,
                int startIndex,
                vector<int>&& currentSubset,
                int subsetSize);
void genSubsets(vector<int>& set,
                int startIndex,
                vector<int>& currentSubset,
                int subsetSize);
void printSet(vector<int>& set);

static inline void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(),
            [] (char ch) { return ch != ' '; }).base(), s.end());
}

int main()
{
    vector<int> set = readSet();
    powerset(set);
}

vector<int> readSet()
{
    string line;
    getline(cin, line);
    rtrim(line);
    
    vector<int> set;
    if (line != "")
    {
        istringstream iss(line);
        while (!iss.eof())
        {
            int elem;
            iss >> elem;
            set.push_back(elem);
        }
    }

    return set;
}

void powerset(vector<int>&& set)
{
    powerset(set);
}

void powerset(vector<int>& set)
{   
    for (uint32_t i = 0; i <= set.size(); i++)
    {
        genSubsets(set, 0, vector<int>(), i);
    }
}

void genSubsets(vector<int>& set, 
                int startIndex,
                vector<int>&& currentSubset,
                int subsetSize)
{
    genSubsets(set, startIndex, currentSubset, subsetSize);
}

void genSubsets(vector<int>& set, 
                int startIndex,
                vector<int>& currentSubset,
                int subsetSize)
{
    if (set.size() - startIndex < subsetSize - currentSubset.size()) return;
    if (currentSubset.size() >= (uint32_t)subsetSize)
    {
        printSet(currentSubset);
        return;
    }

    for (uint32_t i = startIndex; i < set.size(); i++)
    {
        currentSubset.push_back(set[i]);
            
        genSubsets(set, i + 1, currentSubset, subsetSize);
        
        currentSubset.erase(
            currentSubset.begin() + currentSubset.size() - 1);
    }
}

void printSet(vector<int>& set)
{
    for (uint32_t i = 0; i < set.size(); i++)
    {
        cout << set[i];
        if (i < set.size() - 1)
        {
            cout << " ";
        }
    }

    cout << endl;
}

