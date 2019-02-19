#include <bits/stdc++.h>

using namespace std;

#define ASCII_CHARS_COUNT 256

bool arePermutations(string str1, string str2) 
{
    if (str1.size() != str2.size()) return false;

    char letterOcc[ASCII_CHARS_COUNT] = { 0 };
    for (int i = 0; i < str1.size(); i++) 
    {
        letterOcc[str1[i]]++;
    }

    for (int i = 0; i < str2.size(); i++)
    {
        letterOcc[str2[i]]--;
        if (letterOcc[str2[i]] < 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string str1;
    string str2;

    cin >> str1 >> str2;
    bool res = arePermutations(str1, str2);
    
    cout << (res ? "true" : "false") << endl;
}

