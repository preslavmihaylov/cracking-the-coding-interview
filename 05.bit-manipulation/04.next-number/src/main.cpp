#include <bits/stdc++.h>
#include <cassert>
#include <pstructs/bit_ops.h>

using namespace std;
using namespace pstructs;

int onesCnt(uint32_t number)
{
    int ones = 0;
    while (number > 0)
    {
        ones = ((number & 1) == 1) ? ones + 1 : ones;
        number >>= 1;
    }

    return ones;
}

uint32_t getNextBiggest(uint32_t number)
{
    if (number == 0) return 0;

    int onesCnt = 0;
    for (int bit = 0; bit < 32; bit++)
    {
        if (bit_ops::getBit(number, bit) == 1)
        {
            onesCnt++;
        }

        if (bit_ops::getBit(number, bit) == 0 && onesCnt > 0)
        {
            number = bit_ops::raiseBit(number, bit);

            // clear all bits[0..bit)
            number &= ~((1 << bit) - 1);

            // set all ones - bits[0..prevOnes)
            number |= ((1 << (onesCnt - 1)) - 1);

            return number;
        }
    }

    throw invalid_argument("no next biggest number with same ones cnt");
}

uint32_t getNextSmallest(uint32_t number)
{
    int onesCnt = 0;
    for (int bit = 0; bit < 32; bit++)
    {
        if (bit_ops::getBit(number, bit) == 1)
        {
            onesCnt++;
        }
        
        if (bit > 0 && bit_ops::getBit(number, bit) == 1 && bit_ops::getBit(number, bit - 1) == 0)
        {
            // clear bits [0..bit + 1)
            number &= ~((1 << (bit + 1)) - 1);

            // [bit - onesCnt..bit) = 1
            number |= (((1 << onesCnt) - 1) << (bit - onesCnt));

            return number;
        }
    }

    throw invalid_argument("cannot find next smallest number");
}

int main()
{
    string input;
    cin >> input;

    uint32_t num = bit_ops::binaryStringToNumber(input);
    
    cout << bit_ops::toBinaryString(getNextBiggest(num)) << endl;
    cout << bit_ops::toBinaryString(getNextSmallest(num)) << endl;
}

