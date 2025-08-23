#include <iostream>
#include <vector>
using namespace std;

// 每笔交易需要付手续费，状态转移方程总体上没变化
// f(i, 0) = max(f(i-1, 0), f(i-1, 1) + w_i - fee)
// f(i, 1) = max(f(i-1, 1), f(i-1, 0) - w_i)
// 虽然有手续费，但不需要对有票和无票取max
int maxProfit(vector<int>& prices, int fee) {
  int n = prices.size();
  vector<array<int, 2>> f(n + 1, {0, 0});
  // 边界条件：第0天有票是非法的
  f[0][1] = INT_MIN / 2;
  for (int i = 1; i <= n; ++i) {
    f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i - 1] - fee);
    f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i - 1]);
  }
  return f[n][0];
}

int main() {
  {
    vector<int> nums{1, 3, 2, 8, 4, 9};
    cout << maxProfit(nums, 2) << endl;
  }
  {
    vector<int> nums{1, 3, 7, 5, 10, 3};
    cout << maxProfit(nums, 3) << endl;
  }
}