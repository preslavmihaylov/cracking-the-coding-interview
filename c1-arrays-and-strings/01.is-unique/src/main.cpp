#include <bits/stdc++.h>

using namespace std;

#define ASCII_CHARS_COUNT 256

bool isUnique(string str) 
{
    int letters[ASCII_CHARS_COUNT] = { 0 };

    for (int i = 0; i < str.size(); i++) 
    {
        if (++letters[str[i]] > 1)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string str;
    cin >> str;
    bool res = isUnique(str);
    
    cout << (res ? "true" : "false") << endl;
}

