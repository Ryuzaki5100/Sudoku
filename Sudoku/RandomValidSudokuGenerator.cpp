#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> randomSudoku()
{
    srand(time(0));
    vector<vector<int>> grid = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
                                {4, 5, 6, 7, 8, 9, 1, 2, 3},
                                {7, 8, 9, 1, 2, 3, 4, 5, 6},
                                {2, 1, 4, 3, 6, 5, 8, 9, 7},
                                {3, 6, 5, 8, 9, 7, 2, 1, 4},
                                {8, 9, 7, 2, 1, 4, 3, 6, 5},
                                {5, 3, 1, 6, 4, 2, 9, 7, 8},
                                {6, 4, 2, 9, 7, 8, 5, 3, 1},
                                {9, 7, 8, 5, 3, 1, 6, 4, 2}};
    int iterations = 100 + rand() % 100;
    for (int n = 0; n < iterations; n++)
    {
        int i = rand() % 9, j = rand() % 9;
        switch (rand() % 2)
        {
        case 0:
        {
            vector<int> temp = grid[i];
            grid[i] = grid[j];
            grid[j] = temp;
            break;
        }
        case 1:
        {
            for (int k = 0; k < 9; k++)
            {
                int temp = grid[k][i];
                grid[k][i] = grid[k][j];
                grid[k][j] = temp;
            }
            break;
        }
        // case 2:
        // {
        //     i++, j++;
        //     for (int k = 0; k < 9; k++)
        //     {
        //         int p, q;
        //         for (int r = 0; r < 9; r++)
        //         {
        //             if (grid[k][r] == i)
        //                 p = r;
        //             if (grid[k][r] == j)
        //                 q = r;
        //         }
        //         int temp = grid[k][p];
        //         grid[k][p] = grid[k][q];
        //         grid[k][q] = temp;
        //     }
        //     break;
        // }
        }
    }
    return grid;
}
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
    if (validSudokuChecker(randomSudoku()))
        cout << "Valid";
    else
        cout << "Invalid";
}