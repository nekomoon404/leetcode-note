#include <iostream>
#include <vector>
using namespace std;

// f(i, j)表示右下角是第i行和第j列的正方形的最大边长
// 如果m_i_j = 0, f(i, j) = 0
// 如果m_i_j = 1, f(i, j) = min(f(i-1, j), f(i, j-1), f(i-1, j-1)) + 1
// 最后取f(i, j)的最大值
int maximalSquare(vector<vector<char>>& matrix) {
  int n = matrix.size(), m = matrix[0].size();
  auto f = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (matrix[i - 1][j - 1] == '1') {
        f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
        ans = max(ans, f[i][j]);
      }
    }
  }
  return ans * ans;
}

int main() {
  {
    vector<vector<char>> matrix{
        {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << maximalSquare(matrix) << endl;
  }
  {
    vector<vector<char>> matrix{{'1', '0'}, {'1', '0'}};
    cout << maximalSquare(matrix) << endl;
  }
  {
    vector<vector<char>> matrix{{'0'}};
    cout << maximalSquare(matrix) << endl;
  }
}