#include <bits/stdc++.h>

using namespace std;

void paintFill(vector<vector<char>>& screen, int row, int col, char color);
void paintFill(vector<vector<char>>& screen, int row, int col, char prevColor, char color);
void readScreen(vector<vector<char>>& screen);
void printScreen(vector<vector<char>>& screen);

int main()
{
    vector<vector<char>> screen;
    readScreen(screen);
    
    int row, col;
    char color;
    cin >> row >> col;
    cin >> color;

    paintFill(screen, row, col, color);
    printScreen(screen);
}

void paintFill(vector<vector<char>>& screen, int row, int col, char color)
{
    if (row < 0 || row >= screen.size() ||
        col < 0 || col >= screen[row].size())
    {
        return;
    }

    paintFill(screen, row, col, screen[row][col], color);
}

void paintFill(vector<vector<char>>& screen, int row, int col, char prevColor, char color)
{
    if (row < 0 || row >= screen.size() ||
        col < 0 || col >= screen[row].size() ||
        screen[row][col] != prevColor)
    {
        return;
    }

    prevColor = screen[row][col];
    screen[row][col] = color;
    
    paintFill(screen, row - 1, col, prevColor, color);
    paintFill(screen, row,  col + 1, prevColor, color);
    paintFill(screen, row + 1, col, prevColor, color);
    paintFill(screen, row, col - 1, prevColor, color);
}

void readScreen(vector<vector<char>>& screen)
{
    int rows;
    cin >> rows;
    
    for (int row = 0; row < rows; row++)
    {
        screen.push_back(vector<char>());

        string line;
        cin >> line;
        for (char& ch : line)
        {
            screen[row].push_back(ch);
        }
    }
}

void printScreen(vector<vector<char>>& screen)
{
    for (int row = 0; row < screen.size(); row++)
    {
        for (int col = 0; col < screen[row].size(); col++)
        {
            cout << screen[row][col];
        }

        cout << endl;
    }
}
