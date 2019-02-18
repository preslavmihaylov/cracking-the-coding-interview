#include <bits/stdc++.h>

using namespace std;

string findPath(vector<vector<char>>& grid);
string findPath(vector<vector<char>>& grid, vector<vector<bool>>& visited, uint32_t row, uint32_t col);
void readGrid(vector<vector<char>>& grid);
void printGrid(vector<vector<char>>& grid);

int main()
{
    vector<vector<char>> grid;
    readGrid(grid);
    
    string path = findPath(grid);
    cout << path << endl;

    //printGrid(grid);
}

string findPath(vector<vector<char>>& grid)
{
    vector<vector<bool>> visited(grid.size());
    for (uint32_t row = 0; row < grid.size(); row++)
    {
        visited[row] = vector<bool>(grid[row].size());
    }

    return findPath(grid, visited, 0, 0);
}

string findPath(vector<vector<char>>& grid, vector<vector<bool>>& visited, uint32_t row, uint32_t col)
{
    if (row >= grid.size()) return "";
    if (col >= grid[row].size()) return "";
    if (grid[row][col] == '*') return "";
    if (visited[row][col] == true) return "";

    // target found: bottom right corner
    if (row == grid.size() - 1 && col == grid[row].size() - 1) return "x";

    visited[row][col] = true;
    string right = findPath(grid, visited, row, col + 1);
    if (right != "")
    {
        return ">" + right;
    }

    string down = findPath(grid, visited, row + 1, col);
    if (down != "")
    {
        return "v" + down;
    }

    return "";
}

void readGrid(vector<vector<char>>& grid)
{
    assert(grid.size() == 0);

    int rows, cols;
    cin >> rows >> cols;
    
    for (int row = 0; row < rows; row++)
    {
        grid.push_back(vector<char>(cols));
        for (int col = 0; col < cols; col++)
        {
            char ch;
            cin >> ch;

            grid[row][col] = ch;
        }
    }
}

void printGrid(vector<vector<char>>& grid)
{
    for (uint32_t row = 0; row < grid.size(); row++)
    {
        for (uint32_t col = 0; col < grid[row].size(); col++)
        {
            cout << grid[row][col];
        }

        cout << endl;
    }
}
