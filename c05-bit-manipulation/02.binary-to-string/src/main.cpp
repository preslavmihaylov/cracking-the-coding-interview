#include <bits/stdc++.h>
#include <cassert>
#include <pstructs/bit_ops.h>

using namespace std;
using namespace pstructs;

string binaryToString(double num)
{
    string binary;
    while (binary.size() < 32)
    {
        num *= 2;

        if (num >= 1)
        {
            binary.push_back('1');
            num -= 1;
        }
        else
        {
            binary.push_back('0');
        }
    }
    
    if (num != 0) return "ERROR";

    return binary;
}

int main()
{
    double num;
    cin >> num;

    // substr to 8 bits for simpler test scenarios
    cout << binaryToString(num).substr(0, 8) << endl;
}

