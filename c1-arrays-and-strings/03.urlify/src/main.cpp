#include <bits/stdc++.h>

using namespace std;

#define ASCII_CHARS_COUNT 256

char* urlify(char *str, int length) 
{
    int charIndex = length - 1;
    bool firstCharMet = false;

    for (int i = length - 1; i >= 0; i--)
    {
        if (str[i] != ' ')
        {
            firstCharMet = true;
            str[charIndex] = str[i];
            charIndex--;
        }
        else if (firstCharMet)
        {
            assert(i + 2 < length);

            str[charIndex] = '0';
            str[charIndex - 1] = '2';
            str[charIndex - 2] = '%';
            charIndex -= 3;
        }
    }

    return str;
}

int main()
{
    string str;
    getline(cin, str);

    int charBuffSize = str.size() - 2;
    char *charBuffer = new char[charBuffSize + 1];
    for (int i = 1, chBuffIndex = 0; i < str.size() - 1; i++)
    {
        charBuffer[i - 1] = str[i]; 
    }

    charBuffer[charBuffSize] = '\0';

    cout << urlify(charBuffer, charBuffSize) << endl;
    delete charBuffer;

    return 0;
}

