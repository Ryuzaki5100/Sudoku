#include <bits/stdc++.h>
using namespace std;
bool placeNumber(vector<vector<int>> &grid, int num, int k)
{
    int i = k / 9, j = k % 9;
    for (int n = 0; n < 9; n++)
        if (grid[i][n] == num && n != j || grid[n][j] == num && n != i)
            return false;
    int p = i / 3, q = j / 3;
    for (int m = 3 * p; m < 3 * p + 3; m++)
        for (int n = 3 * q; n < 3 * q + 3; n++)
            if (grid[m][n] == num && m != i && n != j)
                return false;
    return true;
}
bool solveSudoku(vector<vector<int>> &grid, int k = 0)
{
    int i = k / 9, j = k % 9;
    if (i == 9)
        return true;
    if (grid[i][j] != 0)
        return solveSudoku(grid, k + 1);
    for (int num = 1; num <= 9; num++)
    {
        if (placeNumber(grid, num, k))
        {
            grid[i][j] = num;
            if (solveSudoku(grid, k + 1))
                return true;
        }
    }
    grid[i][j] = 0;
    return false;
}
void printGrid(vector<vector<int>> grid)    
{
    for (auto i : grid)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> grid = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
                                {4, 5, 6, 7, 8, 9, 1, 2, 3},
                                {7, 8, 9, 1, 2, 3, 4, 5, 6},
                                {2, 1, 4, 3, 6, 5, 8, 9, 7},
                                {3, 6, 5, 8, 9, 7, 2, 1, 4},
                                {8, 9, 7, 2, 1, 4, 3, 6, 5},
                                {5, 3, 1, 6, 4, 2, 9, 7, 8},
                                {6, 4, 2, 9, 7, 8, 5, 3, 1},
                                {9, 7, 8, 5, 3, 1, 6, 4, 2}};
    if (solveSudoku(grid))
        printGrid(grid);
    else
        cout << "The give sudoku cannot be solved.";
}
