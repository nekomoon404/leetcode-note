#include <iostream>
#include <vector>
using namespace std;

// 状态表示：f(i)集合：表示以第i数（a_i）结尾的递增子序列的集合；属性：子序列最大长度
// 状态计算：枚举子序列中倒数第二个数，可能是第1到i-1个数
// f(i) = max(f(j)+1), a_j < a_i, j = 1,..,i-1
// 最后遍历f(i)，得到最长递增子序列的长度
int lengthOfLIS(vector<int>& nums) {
  int n = nums.size();
  vector<int> f(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    f[i] = 1; // 以第i个数结尾的上升子序列，长度至少为1
    for (int j = 1; j < i; ++j) {
      if (nums[j - 1] < nums[i - 1]) {
        f[i] = max(f[i], f[j] + 1);
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    res = max(res, f[i]);
  }
  return res;
}
// 时间复杂度：O(n^2)，空间复杂度：O(n)

int main() {
  {
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;
  }
  {
    vector<int> nums{0, 1, 0, 3, 2, 3};
    cout << lengthOfLIS(nums) << endl;
  }
  {
    vector<int> nums{7, 7, 7, 7, 7, 7, 7};
    cout << lengthOfLIS(nums) << endl;
  }
}