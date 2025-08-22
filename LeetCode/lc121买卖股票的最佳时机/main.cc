#include <iostream>
#include <vector>
using namespace std;

// 题目限制只能买卖一次股票，其实就不需要DP了
// 从左到右枚举股票卖出的价格，减去前i个数的最小值（买入价格）就是利润
int maxProfit(vector<int>& prices) {
  int ans = 0;
  int min_price = prices[0];
  for (int p : prices) {
    ans = max(ans, p - min_price);
    min_price = min(p, min_price);
  }
  return ans;
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