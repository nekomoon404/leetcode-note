#include <iostream>
#include <vector>
using namespace std;

// f(i, j)表示的集合是从前i个数中选和为j的选法，f(i, j)表示的值是选法中最少元素个数
// 划分子集：
//    不选第i个数：f(i - 1, j)
//    选第i个数：f(i - 1, j - v_i) + 1, f(i - 1, j - 2 * v_i) + 2 ,..., f(i - 1, j - k * v_i) + k
//  f(i, j) = min(f(i - 1, j), f(i - 1, j - v_i) + 1,  f(i - 1, j - 2 * v_i) + 2, ..., )
//  令j = j - v_i：f(i, j - v_i) = min(f(i - 1, j - v_i), f(i - 1, j - 2 * v_i) + 1, f(i - 1, j - 3 * v_i) + 2, ..., )
//  所以：f(i, j) = min(f(i - 1, j), f(i, j - v_i) + 1)
//  f[0][0] = 0，表示需要0个元素; 其他值初始化为一个较大的值表示还没有选择
int coinChange2(vector<int>& coins, int amount) {
  if (amount == 0) return 0;
  int n = coins.size(), m = amount;
  // 如果初始化为INT_MAX，后面f[i][j - coins[i - 1]] + 1 会溢出
  vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX / 2));
  f[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      f[i][j] = f[i - 1][j];
      if (j >= coins[i - 1]) f[i][j] = min(f[i][j], f[i][j - coins[i - 1]] + 1);
    }
  }
  return f[n][m] < INT_MAX / 2 ? f[n][m] : -1;
}
// 时间复杂度：O(n * m)，空间复杂度：O(n * m)


// 空间优化为一维数组
int coinChange(vector<int>& coins, int amount) {
  if (amount == 0) return 0;
  int n = coins.size(), m = amount;
  // 如果初始化为INT_MAX，后面f[i][j - coins[i - 1]] + 1 会溢出
  vector<int> f(m + 1, INT_MAX / 2);
  f[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = coins[i - 1]; j <= m; ++j) {
      f[j] = min(f[j], f[j - coins[i - 1]] + 1);
    }
  }
  return f[m] < INT_MAX / 2 ? f[m] : -1;
}
// 时间复杂度：O(n * m)，空间复杂度：O(m)

int main() {
  {
    vector<int> nums{1, 2, 5};
    cout << coinChange(nums, 11) << "\n";
  }
  {
    vector<int> nums{2};
    cout << coinChange(nums, 3) << "\n";
  }
  {
    vector<int> nums{1};
    cout << coinChange(nums, 0) << "\n";
  }
}