#include <iostream>
#include <vector>
using namespace std;

// 在最多买卖K次的基础上，令K=2
int maxProfit2(vector<int>& prices) {
  int n = prices.size();
  auto f = vector<array<array<int, 2>, 3>>(n + 1);
  // 边界条件，第0天手上有票是非法的
  for (int j = 0; j <= 2; ++j) f[0][j][1] = INT_MIN / 2;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 2; ++j) {
      f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + prices[i - 1]);
      f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - prices[i - 1]);
    }
  }
  return f[n][2][0];
}

// 空间优化：可以直接去掉第一维
int maxProfit(vector<int>& prices) {
  int n = prices.size();
  auto f = array<array<int, 2>, 3>();
  // 边界条件，第0天手上有票是非法的
  for (int j = 0; j <= 2; ++j) f[j][1] = INT_MIN / 2;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 2; ++j) {
      f[j][0] = max(f[j][0], f[j][1] + prices[i - 1]);
      f[j][1] = max(f[j][1], f[j - 1][0] - prices[i - 1]);
    }
  }
  return f[2][0];
}

int main() {
  {
    vector<int> nums{3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(nums) << endl;
  }
  {
    vector<int> nums{1, 2, 3, 4, 5};
    cout << maxProfit(nums) << endl;
  }
  {
    vector<int> nums{7, 6, 4, 3, 1};
    cout << maxProfit(nums) << endl;
  }
  {
    vector<int> nums{1};
    cout << maxProfit(nums) << endl;
  }
}