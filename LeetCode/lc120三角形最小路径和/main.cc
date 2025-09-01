#include <iostream>
#include <vector>
using namespace std;

// f(i, j)表示从顶部到第i行第j列的元素的最小路径和
// f(i, j) = min(f(i-1, j), f(i-1, j-1)) + triangle[i-1][j-1]
// 边界条件：f(0, 0)=0，因为要求最小值，其他f(i, j)初始化为INT_MAX/2
int minimumTotal(vector<vector<int>>& triangle) {
  int n = triangle.size();
  int m = triangle[triangle.size() - 1].size();
  auto f = vector<vector<int>>(n + 1, vector<int>(m + 1, INT_MAX / 2));
  f[0][0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {  // 注意j的最大值是i，否则triangle下标会越界
      f[i][j] = min(f[i - 1][j], f[i - 1][j - 1]) + triangle[i - 1][j - 1];
    }
  }
  int res = INT_MAX;
  for (int j = 1; j <= m; ++j) {
    res = min(res, f[n][j]);
  }
  return res;
}

int main() {
  {
    vector<vector<int>> nums{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << minimumTotal(nums) << endl;
  }
  {
    vector<vector<int>> nums{{-10}};
    cout << minimumTotal(nums) << endl;
  }
}