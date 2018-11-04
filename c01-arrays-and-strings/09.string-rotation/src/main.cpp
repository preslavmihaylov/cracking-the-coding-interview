#include <bits/stdc++.h>

using namespace std;

bool isRotation(string origin, string term)
{
    if (origin.length() != term.length()) return false;
    
    int origRotationPos = 0;
    int termRotationPos = 0;

    int origIndex = 0;
    for (int termIndex = 0; termIndex < term.length(); termIndex++)
    {
        if (origin[origIndex] == term[termIndex])
        {
            origRotationPos = origIndex + 1;
            origIndex++;
        }
        else
        {
            termRotationPos = termIndex + 1;
            origRotationPos = 0;
            origIndex = 0;
        }
    }

    if (origin.length() - origRotationPos == termRotationPos)
    {
        int tPos = 0;
        int oPos = origRotationPos;
        while (oPos < origin.length())
        {
            // if oPos is in boundary, tPos should not go outside it
            assert(tPos < termRotationPos);
            if (origin[oPos] != term[tPos])
            {
                return false;
            }

            oPos++;
            tPos++;
        }

        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string origin, term;
    cin >> origin >> term;

    cout << (isRotation(origin, term) ? "true" : "false") << endl;
}
