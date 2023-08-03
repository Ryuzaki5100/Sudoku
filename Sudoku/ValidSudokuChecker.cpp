#include <bits/stdc++.h>
using namespace std;
bool validSudokuChecker(vector<vector<int>> grid)
{
    map<int, vector<int>> x;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j])
            {
                for (auto k : x[grid[i][j]])
                    if (k / 9 == i || k % 9 == j || (k / 9) / 3 == i / 3 && (k % 9) / 3 == j / 3)
                        return false;
                x[grid[i][j]].push_back(9 * i + j);
            }
        }
    return true;
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
    if (validSudokuChecker(grid))
        cout << "VALID";
    else
        cout << "INVALID";
}