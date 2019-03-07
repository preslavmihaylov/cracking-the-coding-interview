#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

void generateEightQueensVariations(vector<int>& cols, int row, int availableCols);
bool diagonalsAreClear(vector<int>& cols, int row, int col);
void printBoard(vector<int>& cols);

static const int ROWS_CNT = 8;
static const int COLS_CNT = ROWS_CNT;
int variationsCnt = 0;

int main()
{
    vector<int> cols;
    for (int row = 0; row < ROWS_CNT; row++)
    {
        cols.push_back(-1);
    }

    generateEightQueensVariations(cols, 0, 0);
    cout << "VARIATIONS: " << variationsCnt << endl;
}

void generateEightQueensVariations(vector<int>& cols, int row, int availableCols)
{
    if (row >= cols.size())
    {
        variationsCnt++;
        printBoard(cols);
        cout << endl;

        return;
    }

    for (int col = 0; col < cols.size(); col++)
    {
        if (((availableCols >> col) & 1) != 0) continue;
        
        if (diagonalsAreClear(cols, row, col))
        {
            cols[row] = col;
            availableCols |= 1 << col;

            generateEightQueensVariations(cols, row + 1, availableCols);

            cols[row] = -1;
            availableCols ^= 1 << col;
        }
    }
}

bool diagonalsAreClear(vector<int>& cols, int row, int col)
{
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        int colDistance = abs(col - cols[rowIndex]);
        int rowDistance = row - rowIndex;

        if (colDistance == rowDistance) return false;
    }

    return true;
}

void printBoard(vector<int>& cols)
{
    for (int row = 0; row < cols.size(); row++)
    {
        for (int col = 0; col < cols.size(); col++)
        {
            cout << (cols[row] == col ? '*' : '-') << " ";
        }

        cout << endl;
    }
}

