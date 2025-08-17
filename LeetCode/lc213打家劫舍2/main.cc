#include <iostream>
#include <vector>

using namespace std;

// [start, end)左闭右开区间
int rob_range(vector<int>& nums, int start, int end) {
  int f0 = 0, f1 = 0, f2 = 0;
  for (int i = start; i < end; ++i) {
    f2 = max(f1, f0 + nums[i]);
    f0 = f1;
    f1 = f2;
  }
  return f2;
}

// 在打家劫舍1的基础上增加首尾不能同时选择的条件
int rob(vector<int>& nums) {
  // 选择nums[0]，则nums[1], nums[n - 1]不能选，则从[2, n -2]区间选
  // 不选nums[0]，则从[1, n - 1]区间选
  int n = nums.size();
  return max(nums[0] + rob_range(nums, 2, n - 1), rob_range(nums, 1, n));
}

int main() {
  {
    vector<int> nums{1};
    cout << rob(nums) << "\n";
  }
  {
    vector<int> nums{2, 3, 2};
    cout << rob(nums) << "\n";
  }
  {
    vector<int> nums{1, 2, 3, 1};
    cout << rob(nums) << "\n";
  }
  {
    vector<int> nums{1, 2, 3};
    cout << rob(nums) << "\n";
  }
}