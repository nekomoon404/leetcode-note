#include <iostream>
#include <vector>

using namespace std;

// dfs(i) = max(dfs(i - 1), dfs(i - 2) + nums[i])
// 将记忆化搜索翻译成递推: f[i] = max(f[i - 1], f[i - 2] + nums[i])
// 方便处理i < 2的情况：f[i + 2] = max(f[i + 1], f[i] + nums[i]), i < n, 那么最后的结果是f[n - 1 + 2] = f[n + 1]
int rob2(vector<int>& nums) {
  int n = nums.size();
  vector<int> f(n + 2, 0);
  for (int i = 0; i < n; ++i) {
    f[i + 2] = max(f[i + 1], f[i] + nums[i]);
  }
  return f[n + 1];
}
// 时间复杂度: O(n)
// 空间复杂度：O(1)

// 从优化空间负责度考虑，当前=max(上一个，上上一个 + nums[i])
// 实际上只需维护三个变量
int rob(vector<int>& nums) {
  int f0 = 0, f1 = 0, f2 = 0;
  for (int i = 0; i < nums.size(); ++i) {
    f2 = max(f1, f0 + nums[i]);
    f0 = f1;
    f1 = f2;
  }
  return f2;
}
// 时间复杂度: O(n)
// 空间复杂度：O(1)

int main() {
  {
    vector<int> nums{1, 2, 3, 1};
    cout << rob(nums) << "\n";
  }
  {
    vector<int> nums{2, 7, 9, 3, 1};
    cout << rob(nums) << "\n";
  }
}
