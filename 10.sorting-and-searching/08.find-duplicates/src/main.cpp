#include <bits/stdc++.h>

using namespace std;

void raiseBit(u_char *bitvector, uint32_t index);
bool isBitRaised(u_char *bitvector, uint32_t index);

static const uint64_t WORD_SIZE = 8;
static const uint64_t MAX_INTS = ((uint64_t)1) << 32;
static const uint64_t MAX_INTS_IN_BYTES = MAX_INTS / WORD_SIZE;

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
        uint32_t num = std::stoi(line);

        if (isBitRaised(bitvector, num))
        {
            cout << num << endl;
        }
        else
        {
            raiseBit(bitvector, num);
        }

        getline(ifs, line);
    }
}

void raiseBit(u_char *bitvector, uint32_t index)
{
    uint32_t wordIndex = index / WORD_SIZE;
    uint32_t bitIndex = index % WORD_SIZE;

    bitvector[wordIndex] |= ((uint32_t)1) << bitIndex;
}

bool isBitRaised(u_char *bitvector, uint32_t index)
{
    uint32_t wordIndex = index / WORD_SIZE;
    uint32_t bitIndex = index % WORD_SIZE;

    return (bitvector[wordIndex] >> bitIndex) & 1;
}
