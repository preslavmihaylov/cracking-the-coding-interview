#include <bits/stdc++.h>

using namespace std;

struct MatrixCoord
{
    int row;
    int col;

    MatrixCoord(int row, int col) : row(row), col(col) {}
};

void readMatrix(vector<vector<int>>& matrix);
MatrixCoord sortedMatrixSearch(vector<vector<int>>& matrix, int term);
MatrixCoord sortedMatrixSearch(vector<vector<int>>& matrix, 
                               int rowStart, int rowEnd, int colStart, int colEnd, int term);
int rowSearch(vector<vector<int>>& matrix,
              int row, int colStart, int colEnd, int term);
bool isValidCoord(vector<vector<int>>& matrix, MatrixCoord coord);

int main(int argc, char *argv[])
{
    vector<vector<int>> matrix;
    readMatrix(matrix);

    int term;
    cin >> term;

    MatrixCoord result = sortedMatrixSearch(matrix, term);
    cout << result.row << " " << result.col << endl;
}

void readMatrix(vector<vector<int>>& matrix)
{
    int rows;
    int cols;
    cin >> rows;
    cin >> cols;
    
    for (int row = 0; row < rows; row++)
    {
        matrix.push_back(vector<int>());
        for (int col = 0; col < cols; col++)
        {
            int num;
            cin >> num;

            matrix[row].push_back(num);
        }
    }
}

MatrixCoord sortedMatrixSearch(vector<vector<int>>& matrix, int term)
{
    return sortedMatrixSearch(matrix, 0, matrix.size(), 0, matrix[0].size(), term);
}

MatrixCoord sortedMatrixSearch(vector<vector<int>>& matrix, 
                               int rowStart, int rowEnd, int colStart, int colEnd, int term)
{
    if (rowStart >= rowEnd) return MatrixCoord(-1, -1);

    int rowMid = (rowStart + rowEnd) / 2;
    int colMid = rowSearch(matrix, rowMid, colStart, colEnd, term);
    if (matrix[rowMid][colMid] == term) 
    {
        return MatrixCoord(rowMid, colMid);
    }

    MatrixCoord upperQCoord = sortedMatrixSearch(matrix, rowStart, rowMid, colMid, colEnd, term);
    if (isValidCoord(matrix, upperQCoord) && matrix[upperQCoord.row][upperQCoord.col] == term) 
    {
        return upperQCoord;
    }

    return sortedMatrixSearch(matrix, rowMid + 1, rowEnd, colStart, colMid, term);
}

int rowSearch(vector<vector<int>>& matrix, int row, int colStart, int colEnd, int term)
{
    if (colStart >= colEnd) return colEnd;

    int colMid = (colStart + colEnd) / 2;
    if (matrix[row][colMid] == term)
    {
        return colMid;
    }
    else if (matrix[row][colMid] > term)
    {
        return rowSearch(matrix, row, colStart, colMid, term);
    }
    else
    {
        return rowSearch(matrix, row, colMid + 1, colEnd, term);
    }
}

bool isValidCoord(vector<vector<int>>& matrix, MatrixCoord coord)
{
    return coord.row >= 0 && coord.row < matrix.size() &&
           coord.col >= 0 && coord.col < matrix[coord.row].size();
}

