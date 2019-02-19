#include <bits/stdc++.h>
#include <cassert>
#include <pstructs/bit_ops.h>

using namespace std;
using namespace pstructs;

int main()
{
    string input1;
    string input2;
    int i;
    int j;
    cin >> input1 >> input2 >> i >> j;
    
    int number = bit_ops::binaryStringToNumber(input1);
    int insNumber = bit_ops::binaryStringToNumber(input2);

    int insNumberBitsCnt = bit_ops::bitsCnt(insNumber);
    assert(insNumberBitsCnt <= (j - i) + 1);

    while (j >= i)
    {
        int bit = bit_ops::getBit(insNumber, insNumberBitsCnt - 1);
        number = bit_ops::setBit(number, j, bit);
        
        insNumberBitsCnt--;
        j--;
    }
    
    cout << bit_ops::toBinaryString(number) << endl;
    

    return 0;
}

