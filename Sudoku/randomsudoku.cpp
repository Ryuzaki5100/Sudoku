#include <bits/stdc++.h>
using namespace std;
vector<int> random = {1, 2, 3, 4, 5, 6, 7, 8, 9};
bool placeNumber(vector<vector<int>> grid, int num, int k)
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
bool Gen(vector<vector<int>> &grid, int k = 0)
{
    unsigned seed = std::chrono::system_clock::now()
                        .time_since_epoch()
                        .count();
    shuffle(random.begin(), random.end(), std::default_random_engine(seed));
    int i = k / 9, j = k % 9;
    if (i == 9)
        return true;
    for (int num = 0; num < 9; num++)
    {
        if (placeNumber(grid, random[num], k))
        {
            grid[i][j] = random[num];
            if (Gen(grid, k + 1))
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
    vector<vector<int>> grid(9, vector<int>(9, 0));
    Gen(grid);
    if(validSudokuChecker(grid))
    cout<<"Valid";
    else
    cout<<"Invalid";
}