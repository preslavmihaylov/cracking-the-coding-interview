#include <bits/stdc++.h>

using namespace std;

#define ASCII_CHARS_COUNT 256

void toggleBit(int *bitVector, int pos)
{
    *bitVector ^= (1 << pos);
}

bool isPalindromePerm(string str)
{
    int bitVector = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ') continue;
        
        toggleBit(&bitVector, (int)(str[i] - 'a'));
    }

    // this second part is magic:
    // 00100 - 1 = 00011. AND-ing them will result to 0.
    // If there is more than one bit, the result will be different from 0
    return bitVector == 0 || (bitVector & (bitVector - 1)) == 0;
}

int main()
{
    string str;
    getline(cin, str);
    
    cout << (isPalindromePerm(str) ? "true" : "false") << endl;
}

