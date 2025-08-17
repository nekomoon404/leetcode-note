#include <iostream>
#include <vector>
using namespace std;

// 要能分成两个元素和相等的子集，nums的sum必须是偶数
// f(i, j)集合表示从前i个数中选出和为j的选法，值表示方案数
// f(i, j) = f(i - 1, j) + f(i - 1, j - nums[i - 1]), 过程中判断f[i][m]是否大于0
bool canPartition2(vector<int>& nums) {
  int sum = 0;
  for (int num : nums) sum += num;
  if (sum % 2) return false;
  int n = nums.size();
  int m = sum / 2;
  vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      f[i][j] = f[i - 1][j];
      if (j >= nums[i - 1]) f[i][j] += f[i - 1][j - nums[i - 1]];
    }
    if (f[i][m] > 0) return true;
  }
  return f[n][m] > 0;
}

// 要能分成两个元素和相等的子集，nums的sum必须是偶数
// f(i, j)集合表示从前i个数中选出和为j的选法，值是bool类型表示是否能恰好装满
// f(i, j) = f(i - 1, j) || f(i - 1, j - nums[i - 1]), 过程中判断f[i][m]是否大于0
bool canPartition3(vector<int>& nums) {
  int sum = 0;
  for (int num : nums) sum += num;
  if (sum % 2) return false;
  int n = nums.size();
  int m = sum / 2;
  vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
  f[0][0] = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      f[i][j] = f[i - 1][j];
      if (j >= nums[i - 1]) f[i][j] = f[i][j] || f[i - 1][j - nums[i - 1]];
    }
    if (f[i][m]) return true;
  }
  return f[n][m];
}
// 时间复杂度：O(n * m)，空间复杂度：O(n * m)


// 空间优化为一维数组
bool canPartition(vector<int>& nums) {
  int sum = 0;
  for (int num : nums) sum += num;
  if (sum % 2) return false;
  int n = nums.size();
  int m = sum / 2;
  vector<bool> f(m + 1, false);
  f[0] = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = m; j >= nums[i - 1]; --j) {
      f[j] = f[j] || f[j - nums[i - 1]];
    }
    if (f[m]) return true;
  }
  return f[m];
}

int main() {
  {
    vector<int> nums{1, 5, 11, 5};
    cout << canPartition(nums) << endl;
  }
  {
    vector<int> nums{1, 2, 3, 5};
    cout << canPartition(nums) << endl;
  }
}