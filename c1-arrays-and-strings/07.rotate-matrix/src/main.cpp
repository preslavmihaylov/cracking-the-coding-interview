#include <bits/stdc++.h>

using namespace std;

#define ROWS_MAX 100
#define COLS_MAX 100

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

void rotateMatrix(int matrix[ROWS_MAX][COLS_MAX], int rows, int cols)
{
    for (int row = 0; row < rows / 2; row++)
    {
        for (int col = row; col < cols - 1 - row; col++)
        {
            int rotatedRow = row;
            int rotatedCol = col;
            int buffer = matrix[rotatedRow][rotatedCol];
            matrix[rotatedRow][rotatedCol] = matrix[rotatedCol][cols - 1 - rotatedRow];

            int cnt = 0;
            while (cnt < 4)
            {
                cnt++;
                int newRow = cols - 1 - rotatedCol;
                int newCol = rotatedRow;
                int temp = matrix[newRow][newCol];

                matrix[newRow][newCol] = buffer;
                buffer = temp;

                rotatedRow = newRow;
                rotatedCol = newCol;
            }
        }
    }

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

int main()
{
    int N;
    cin >> N;

    int matrix[ROWS_MAX][COLS_MAX];

    readMatrix(matrix, N, N);
    rotateMatrix(matrix, N, N);
}

