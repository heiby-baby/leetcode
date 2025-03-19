/*
В золотом руднике gridразмером m x nкаждая ячейка в этом руднике имеет целое число, представляющее количество золота в этой ячейке, 0если она пуста.

Верните максимальное количество золота, которое вы можете собрать при соблюдении следующих условий:

Каждый раз, когда вы оказываетесь в камере, вы собираете все золото в этой камере.
Из своего положения вы можете сделать один шаг влево, вправо, вверх или вниз.
Одну и ту же камеру можно посетить только один раз.
Никогда не посещайте камеру с 0золотом.
Вы можете начать и прекратить сбор золота с любой позиции в сетке, где есть золото.

Пример 1:

Вход: сетка = [[0,6,0],[5,8,7],[0,9,0]]
 Выход: 24
 Пояснение:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Путь к получению максимального количества золота: 9 -> 8 -> 7.
Пример 2:

Вход: сетка = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
 Выход: 28
 Пояснение:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Путь к получению максимального количества золота: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int getMaximumGoldHelper(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
            return 0;
        }

        int currentGold = grid[row][col];
        grid[row][col] = 0;

        int maxGold = currentGold + max({
            getMaximumGoldHelper(grid, row + 1, col),
            getMaximumGoldHelper(grid, row - 1, col),
            getMaximumGoldHelper(grid, row, col + 1),
            getMaximumGoldHelper(grid, row, col - 1)
        });

        grid[row][col] = currentGold;

        return maxGold;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int result = 0;
        int row_count = grid.size();
        int col_count = grid[0].size();

        for (int i = 0; i < row_count; i++) {
            for (int j = 0; j < col_count; j++) {
                if (grid[i][j] != 0) {
                    result = max(result, getMaximumGoldHelper(grid, i, j));
                }
            }
        }

        return result;
    }
};

int main() {
    Solution a;
    vector<vector<int>> grid = {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0}
    };
    cout << a.getMaximumGold(grid) << endl; 

    vector<vector<int>> grid2 = {
        {1, 0, 7},
        {2, 0, 6},
        {3, 4, 5},
        {0, 3, 0},
        {9, 0, 20}
    };
    cout << a.getMaximumGold(grid2) << endl; 
    return 0;
}