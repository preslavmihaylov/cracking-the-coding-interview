#include <bits/stdc++.h>
#include <pstructs/bit_ops.h>

using namespace std;
using namespace pstructs;

static const int BYTE_SIZE = 8;

void drawScreen(vector<char>& buffer, int width)
{
    int height = (buffer.size() * 8) / width;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int index = (col / BYTE_SIZE) + ((row * width) / BYTE_SIZE);
            int bit = col - ((col / BYTE_SIZE) * BYTE_SIZE);

            //cout << "I: " << index << " B: " << bit << endl;
            cout << (bit_ops::getBit(buffer[index], bit) == 1 ? "*" : "_");
        }

        cout << endl;
    }
}

void drawPixel(vector<char>& buffer, int width, int row, int col)
{
    int index = (col / BYTE_SIZE) + ((row * width) / BYTE_SIZE);
    int bit = col - ((col / BYTE_SIZE) * BYTE_SIZE);

    buffer[index] = bit_ops::raiseBit(buffer[index], bit);
}

void drawByte(vector<char>& buffer, int width, int row, int col)
{
    int index = (col / BYTE_SIZE) + ((row * width) / BYTE_SIZE);

    buffer[index] = 0xFF;
}

void drawHorizontalLine(vector<char>& buffer, int width, int row, int col1, int col2)
{
    for (int i = col1; i < col2; i++)
    {
        if (((i / BYTE_SIZE) * i) == i && (col2 - i >= BYTE_SIZE))
        {
            drawByte(buffer, width, row, i);
            i += BYTE_SIZE - 1;
        }
        else
        {
            drawPixel(buffer, width, row, i);
        }
    }
}

int main()
{
    int width;
    int arrLength;
    int row;
    int col1;
    int col2;
    cin >> width >> arrLength >> row >> col1 >> col2;

    vector<char> buffer(arrLength);
    for (size_t i = 0; i < buffer.size(); i++)
    {
        buffer[i] = 0;
    }
    
    drawHorizontalLine(buffer, width, row, col1, col2);
    drawScreen(buffer, width);
}

