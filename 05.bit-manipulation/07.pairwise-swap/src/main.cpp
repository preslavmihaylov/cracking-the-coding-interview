#include <bits/stdc++.h>
#include <pstructs/bit_ops.h>

using namespace std;
using namespace pstructs;

uint32_t swapEvenOddBits(uint32_t num)
{
    return ((num & 0xAAAAAAAA) >> 1) | ((num & 0x55555555) << 1);
}

int main()
{
    string input;
    cin >> input;
        
    uint32_t num = bit_ops::binaryStringToNumber(input);
    num = swapEvenOddBits(num);

    cout << bit_ops::toBinaryString(num) << endl;
}

