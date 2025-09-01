#include <iostream>
#include <vector>
using namespace std;

// f(i, j)表示从左上角到第i行第j列的最小路径和
// 每次只能向下或者向右移动一步，因此f(i, j)可由f(i-1, j)和f(i, j-1)转移到
// f(i, j) = min(f(i-1, j), f(i, j-1)) + grid_i_j
// 边界条件：f(1, 0), f(0, 1)初始化为0, 目的是让f(1, 1)=左上角的数字，
//         其余初始化为INT_MAX/2，表示非法值不应该取到
int minPathSum2(vector<vector<int>>& grid) {
  int n = grid.size(), m = grid[0].size();
  auto f = vector<vector<int>>(n + 1, vector<int>(m + 1, INT_MAX / 2));
  f[0][1] = f[1][0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i - 1][j - 1];
    }
  }
  return f[n][m];
}

// 空间优化：
// 计算第i层的f[j]，会用到第i-1层的f[j]，和第i层的f[j-1]
// 因此i和j可以从小到大遍历
int minPathSum(vector<vector<int>>& grid) {
  int n = grid.size(), m = grid[0].size();
  auto f = vector<int>(m + 1, INT_MAX / 2);
  f[1] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      f[j] = min(f[j], f[j - 1]) + grid[i - 1][j - 1];
    }
  }
  return f[m];
}

int main() {
  {
    vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minPathSum(grid) << endl;
  }
  {
    vector<vector<int>> grid{{1, 2, 3}, {4, 5, 6}};
    cout << minPathSum(grid) << endl;
  }
}