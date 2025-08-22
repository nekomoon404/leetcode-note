#include <iostream>
#include <vector>
using namespace std;

// f[i][0]表示第i天手上没有股票的利润最大值
// f[i][1]表示第i天手上有股票的利润最大值
// f(i ,0) = max(f(i-1, 0), f(i-1, 1) + w[i])
// f(i, 1) = max(f(i-1, 1), f(i-1, 0) - w[i])
// 边界条件：第0天 f(0, 0) = 0， f(0, 1) = INT_MIN/2（第0天手上有票是非法的）
int maxProfit(vector<int>& prices) {
  int n = prices.size();
  vector<vector<int>> f(n + 1, vector<int>(2, 0));
  f[0][0] = 0;
  f[0][1] = INT_MIN / 2;

  for (int i = 1; i <= n; ++i) {
    f[i][0] = max(f[i - 1][0], f[i - 1][1] + prices[i - 1]);
    f[i][1] = max(f[i - 1][1], f[i - 1][0] - prices[i - 1]);
  }
  return f[n][0];
}

int main() {
  {
    vector<int> nums{7, 1, 5, 3, 6, 4};
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
}