#include <iostream>
#include <vector>
using namespace std;

// f(i, j)表示从左上角到第i行第j列的不同路径个数
// 每次移动只能向下或者向右移动一步
// 如果obs_i_j = 1，则f(i, j) = 0
// 如果obs_i_j = 0，则f(i, j) = f(i-1, j) + f(i, j -1)
// 边界条件：为了让f(1, 1)=1，可以让f(0, 1)=1，其他都初始化为0
int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
  int n = obstacleGrid.size(), m = obstacleGrid[0].size();
  auto f = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
  f[0][1] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (obstacleGrid[i - 1][j - 1] == 1)
        f[i][j] = 0;
      else
        f[i][j] = f[i - 1][j] + f[i][j - 1];
    }
  }
  return f[n][m];
}

// 空间优化
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int n = obstacleGrid.size(), m = obstacleGrid[0].size();
  auto f = vector<int>(m + 1, 0);
  f[1] = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (obstacleGrid[i - 1][j - 1] == 1)
        f[j] = 0;
      else
        f[j] = f[j] + f[j - 1];
    }
  }
  return f[m];
}

int main() {
  {
    vector<vector<int>> obs = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << uniquePathsWithObstacles(obs) << endl;
  }
  {
    vector<vector<int>> obs = {{0, 1}, {0, 0}};
    cout << uniquePathsWithObstacles(obs) << endl;
  }
}