#include <bits/stdc++.h>

using namespace std;

#define ASCII_CHARS_COUNT 256

bool isPalindromePerm(string str)
{
    char letters[ASCII_CHARS_COUNT] = { 0 };
    int trueLength = str.size();

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            trueLength--;
            continue;
        }

        letters[str[i]]++;
    }

    int allowedOdds = 0;
    if (trueLength % 2 == 1)
    {
        allowedOdds = 1;
    }
    
    int oddsCnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ') continue;

        if (letters[str[i]] % 2 == 1)
        {
            letters[str[i]] = 0;
            oddsCnt++;
        }

        if (oddsCnt > allowedOdds)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string str;
    getline(cin, str);
    
    cout << (isPalindromePerm(str) ? "true" : "false") << endl;
}

