#include <iostream>
#include <vector>
using namespace std;

// 问题转化为选择一部分数（和为p）取正，另一个数（和为q）取负，设nums和为s，目标和为t
// if t > 0, 则p > q, (s-q)-q = t，则q=(s-t)/2，即s-t一定是偶数且>=0
// if t < 0, 则p < q, p-(s-p) = t, 则p=(s+t)/2=(s-abs(t))/2，即s-abs(t)一定是偶数且>=0
// f(i, j)表示的集合是从前i个数中选择，和为j的选法，表示的值是方案个数
// f(i, j)划分子集：第i个数不选：f(i - 1, j)，第i个数选：f(i - 1, j - nums[i - 1]), 注意i表示第i个数，对应的nums下标为i-1
int findTargetSumWays2(vector<int>& nums, int target) {
  int sum = 0;
  for (int num : nums) sum+= num;
  sum -= abs(target);
  if (sum % 2 || sum < 0) return 0;
  int n = nums.size();
  int m = sum / 2;
  vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
  f[0][0] = 1;
  // f[0][0]表示从前0个数中选和为0的方案数，初始化为1，f[0][j](j >= 1)表示从前0个数中选和为j的方案数，为0
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j)  {
      f[i][j] = f[i - 1][j];
      if (j >= nums[i - 1]) f[i][j] += f[i - 1][j - nums[i - 1]];
      // 注意i表示第i个数，对应的nums下标为i-1
    }
  }
  return f[n][m];
}
// 时间复杂度：O(n * m)，空间复杂度：O(n * m)

// 空间优化为一维数组
int findTargetSumWays(vector<int>& nums, int target) {
  int sum = 0;
  for (int num : nums) sum+= num;
  sum -= abs(target);
  if (sum % 2 || sum < 0) return 0;
  int n = nums.size();
  int m = sum / 2;
  vector<int> f(m + 1, 0);
  f[0] = 1;
  // f[0]初始化为1，表示从前0个数中选和为0的方案数为1
  for (int i = 1; i <= n; ++i) {
    for (int j = m; j >= nums[i - 1]; --j)  {
      // 注意i表示第i个数，对应的nums下标为i-1
      f[j] = f[j] + f[j - nums[i - 1]];
    }
  }
  return f[m];
}
// 时间复杂度：O(n * m)，空间复杂度：O(m)

int main() {
  {
    vector<int> nums{1, 1, 1, 1, 1};
    cout << findTargetSumWays(nums, 3) << endl;
  }
  {
    vector<int> nums{1};
    cout << findTargetSumWays(nums, 1) << endl;
  }
}