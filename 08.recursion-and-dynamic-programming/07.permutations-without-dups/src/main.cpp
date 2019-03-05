#include <bits/stdc++.h>

using namespace std;

void permsWithoutDups(vector<string>& results, string& str, int start);
void swap(string& str, int first, int second);

int main()
{
    string str;
    cin >> str;
    
    vector<string> results;
    permsWithoutDups(results, str, 0);
    std::sort(results.begin(), results.end());
    for (string& str : results)
    {
        cout << str << endl;
    }
}

void permsWithoutDups(vector<string>& results, string& str, int start)
{
    if (start >= str.size())
    {
        results.push_back(str);
    }

    for (int i = start; i < str.size(); i++)
    {
        swap(str, start, i);
        permsWithoutDups(results, str, start + 1);
        swap(str, start, i);
    }
}

void swap(string& str, int first, int second)
{
    char tmp = str[first];
    str[first] = str[second];
    str[second] = tmp;
}
