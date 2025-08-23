#include <iostream>
#include <vector>
using namespace std;

// 限制卖出股票后，第2天才能买入股票；因此无票-->有票状态的转移，要从前天-->今天
// f(i, 0) = max(f(i-1, 0), f(i-1, 1) + w_i)
// f(i, 1) = max(f(i-1, 1), f(i-2, 0) - w_i)
int maxProfit(vector<int>& prices) {
  int n = prices.size();
  vector<array<int, 2>> f(n + 1, {0, 0});
  // 边界条件：第0天有票是非法的
  f[0][1] = INT_MIN / 2;
  // 提前把f[1][0] = 0, f[1][1] = -w算出来，i从2开始遍历，避免下标越界
  f[1][0] = 0, f[1][1] = -prices[0];
  for (int i = 2; i <= n; ++i) {
    f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i - 1]);
    f[i][1] = max(f[i - 1][1], f[i - 2][0] - prices[i - 1]);
  }
  return f[n][0];
}

int main() {
  {
    vector<int> nums{1, 2, 3, 0, 2};
    cout << maxProfit(nums) << endl;
  }
  {
    vector<int> nums{1};
    cout << maxProfit(nums) << endl;
  }
}