#include <bits/stdc++.h>

using namespace std;

#define ROWS_MAX 100
#define COLS_MAX 100

void readMatrix(int matrix[ROWS_MAX][COLS_MAX], int rows, int cols);
void printMatrix(int matrix[ROWS_MAX][COLS_MAX], int rows, int cols);

void zeroMatrix(int matrix[ROWS_MAX][COLS_MAX], int rows, int cols)
{
    unordered_set<int> rowsToZero;
    unordered_set<int> colsToZero;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (matrix[row][col] == 0)
            {
                rowsToZero.insert(row);
                colsToZero.insert(col);
            }
        }
    }

    for (int row : rowsToZero)
    {
        for (int col = 0; col < cols; col++)
        {
            matrix[row][col] = 0;
        }
    }

    for (int col : colsToZero)
    {
        for (int row = 0; row < rows; row++)
        {
            matrix[row][col] = 0;
        }
    }
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    int matrix[ROWS_MAX][COLS_MAX];

    readMatrix(matrix, rows, cols);
    zeroMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);
}

void readMatrix(int matrix[ROWS_MAX][COLS_MAX], int rows, int cols)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cin >> matrix[row][col];
        }
    }
}

void printMatrix(int matrix[ROWS_MAX][COLS_MAX], int rows, int cols)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cout << matrix[row][col];
            if (col != cols - 1)
            {
                cout << " "; 
            }
        }

        cout << endl;
    }
}
