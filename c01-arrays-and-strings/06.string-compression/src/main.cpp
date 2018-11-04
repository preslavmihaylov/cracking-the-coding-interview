#include <bits/stdc++.h>

using namespace std;

#define ASCII_CHARS_COUNT 256

string compressString(string str)
{
    stringstream ss;
    char currentChar = str[0];
    int cnt = 1;

    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == currentChar)
        {
            cnt++;
        }
        else
        {
            ss << currentChar << cnt;

            currentChar = str[i];
            cnt = 1;
        }
    }
    
    ss << currentChar << cnt;

    return ss.str().size() < str.size() ? ss.str() : str;
}

int main()
{
    string str;
    cin >> str;

    cout << compressString(str) << endl;
}

