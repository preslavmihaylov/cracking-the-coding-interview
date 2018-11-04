#include <bits/stdc++.h>

using namespace std;

#define ASCII_CHARS_COUNT 256

bool isOneReplaceAway(string str1, string str2)
{
    if (str1.size() != str2.size()) return false;

    int diffcharsfound = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] != str2[i])
        {
            diffcharsfound++;
        }

        if (diffcharsfound > 1)
        {
            return false;
        }
    }

    return true;
}

bool isOneRemoveAway(string str1, string str2)
{
    if (str1.size() - str2.size() != 1) return false;

    int misplacedChars = 0;
    int str2Index = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        if (str2Index >= str2.size())
        {
            misplacedChars++;
        }

        if (misplacedChars > 1)
        {
            return false;
        }

        if (str1[i] == str2[str2Index])
        {
            str2Index++; 
        }
        else
        {
            misplacedChars++; 
        }
    }

    return true;
}

bool isOneInsertAway(string str1, string str2)
{
    return isOneRemoveAway(str2, str1);
}

bool isOneAway(string str1, string str2)
{
    if (str1.size() - str2.size() == 1) return isOneRemoveAway(str1, str2);
    if (str2.size() - str1.size() == 1) return isOneRemoveAway(str2, str1);
    if (str1.size() == str2.size()) return isOneReplaceAway(str1, str2);

    return false;
}

int main()
{
    string str1;
    string str2;
    cin >> str1 >> str2;

    cout << (isOneAway(str1, str2) ? "true" : "false") << endl;
}

