#include <bits/stdc++.h>

using namespace std;

void readInput(vector<string>& words);
void groupAnagrams(vector<string>& words);
void printWords(vector<string>& words);

int main()
{
    vector<string> words;
    readInput(words);

    groupAnagrams(words);
    printWords(words);
}

void readInput(vector<string>& words)
{
    string line;
    getline(cin, line);
    istringstream iss(line);

    while (!iss.eof())
    {
        string word;
        iss >> word;

        words.push_back(word);
    }
}

void groupAnagrams(vector<string>& words)
{
    map<string, vector<string>> anagramGroups;
    for (string& word : words)
    {
        string key = word;
        std::sort(key.begin(), key.end());

        if (anagramGroups.find(key) == anagramGroups.end())
        {
            anagramGroups[key] = vector<string>();
        }

        anagramGroups[key].push_back(word);
    }

    int index = 0;
    for (auto& kv : anagramGroups)
    {
        vector<string>& group = kv.second; 
        for (string& word : group)
        {
            words[index++] = word;
        }
    }
}

void printWords(vector<string>& words)
{
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i];
        if (i != words.size() - 1)
        {
            cout << " ";
        }
    }

    cout << endl;
}
