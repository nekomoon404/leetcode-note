#include <iostream>
#include <vector>
using namespace std;

// f[i][j][0] 表示前i天交易了j次，当前手中无票的利润最大值
// f[i][j][1] 表示前i天交易了j-1次，当前手中有票的利润最大值
// f(i, j, 0) = max(f(i-1, j, 0), f(i-1, j, 1) + w[i])
// f(i, j, 1) = max(f(i-1, j, 1), f(i-1, j-1, 0) - w[i])
// 边界条件：第0天 f(0, j, 0) = 0, f(0, j, 1) = INT_MIN/2
//         第0次交易 f(i, 0, 0) = 0,
int maxProfit2(int k, vector<int>& prices) {
  int n = prices.size();
  auto f = vector<vector<array<int, 2>>>(n + 1, vector<array<int, 2>>(k + 1, {0, 0}));
  for (int j = 0; j <= k; ++j) f[0][j][1] = INT_MIN / 2;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + prices[i - 1]);
      f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - prices[i - 1]);
    }
  }
  return f[n][k][0];
}

// 空间优化：推导后发现可以直接去掉第一维，i和j的遍历顺序不用变
int maxProfit(int k, vector<int>& prices) {
  int n = prices.size();
  auto f = vector<array<int, 2>>(k + 1, {0, 0});
  for (int j = 0; j <= k; ++j) f[j][1] = INT_MIN / 2;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      f[j][0] = max(f[j][0], f[j][1] + prices[i - 1]);
      f[j][1] = max(f[j][1], f[j - 1][0] - prices[i - 1]);
    }
  }
  return f[k][0];
}

int main() {
  {
    vector<int> nums{2, 4, 1};
    cout << maxProfit(2, nums) << endl;
  }
  {
    vector<int> nums{3, 2, 6, 5, 0, 3};
    cout << maxProfit(2, nums) << endl;
  }
}