#include <bits/stdc++.h>
#include <cassert>
#include <pstructs/bit_ops.h>

using namespace std;
using namespace pstructs;

int main()
{
    string input;
    cin >> input;
    
    uint32_t number = bit_ops::binaryStringToNumber(input);

    int seqStart = -1;
    int bitToFlip = -1;
    int longestSequenceCnt = 1;
    for (int i = 0; i < 32; i++)
    {
        int bit = bit_ops::getBit(number, i);
        if (bit == 1 && seqStart == -1)
        {
            seqStart = i;
        }

        if (seqStart == -1) continue;

        if (bit == 0 && bitToFlip == -1)
        {
            bitToFlip = i;
        }
        else if (bit == 0)
        {
            int currentSequenceCnt = i - seqStart;
            if (currentSequenceCnt > longestSequenceCnt)
            {
                longestSequenceCnt = currentSequenceCnt;
            }
            
            if (bit_ops::getBit(number, bitToFlip + 1) == 1)
            {
                seqStart = bitToFlip + 1;
                bitToFlip = i;
            }
            else
            {
                seqStart = -1;
                bitToFlip = -1;
            }
        }
    }

    if (seqStart != -1)
    {
        // (UINT32_BITS_CNT - seqStart) + flipped bit
        int currentSequenceCnt = (32 - seqStart);
        if (bitToFlip == -1)
        {
            currentSequenceCnt++;
        }
        
        if (currentSequenceCnt > longestSequenceCnt)
        {
            longestSequenceCnt = currentSequenceCnt;
        }
    }
    
    cout << longestSequenceCnt << endl;
    

    return 0;
}

