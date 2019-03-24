#include <bits/stdc++.h>

using namespace std;

static const uint64_t WORD_SIZE = 8;
static const uint64_t MAX_INTS = (uint64_t)1 << 15;
static const uint64_t MAX_INTS_IN_BYTES = MAX_INTS / WORD_SIZE;

void raiseBit(u_char *bitvector, uint32_t index);
bool isBitRaised(u_char *bitvector, uint32_t index);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return -1;
    }
    
    u_char *bitvector = new u_char[MAX_INTS_IN_BYTES];

    ifstream ifs(argv[1]);
    string line;
    getline(ifs, line);
    while (!ifs.eof())
    {
        unsigned int num = std::stoi(line);
        raiseBit(bitvector, num);

        getline(ifs, line);
    }

    for (int i = 0; i < MAX_INTS_IN_BYTES; i++)
    {
        if (bitvector[i] < 255)
        {
            for (int bitIndex = 0; bitIndex < 8; bitIndex++)
            {
                int num = i * 8 + bitIndex;
                if (!isBitRaised(bitvector, num))
                {
                    cout << num << endl;
                }
            }
        }
    }

    delete[] bitvector;
}

void raiseBit(u_char *bitvector, uint32_t index)
{
    int wordIndex = index / WORD_SIZE;
    int bitIndex = index % WORD_SIZE;

    bitvector[wordIndex] |= 1 << bitIndex;
}

bool isBitRaised(u_char *bitvector, uint32_t index)
{
    int wordIndex = index / WORD_SIZE;
    int bitIndex = index % WORD_SIZE;

    return (bitvector[wordIndex] >> bitIndex) & 1;
}
