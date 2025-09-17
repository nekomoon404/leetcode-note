#include <iostream>
#include <vector>
using namespace std;

// 不定滑动窗口的思路：枚举右端点，缩小左端点
int minSubArrayLen(int target, vector<int>& nums) {
  int n = nums.size(), ans = n + 1, sum = 0, left = 0;
  for (int right = 0; right < n; ++right) {
    sum += nums[right];
    while (sum - nums[left] >= target) {
      sum -= nums[left];
      left++;
    }
    if (sum >= target) {
      ans = min(ans, right - left + 1);
    }
  }
  return ans <= n ? ans : 0;
}

int main() {
  {
    vector<int> nums{2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(7, nums) << endl;
  }
  {
    vector<int> nums{1, 4, 4};
    cout << minSubArrayLen(4, nums) << endl;
  }
  {
    vector<int> nums{1, 1, 1, 1, 1, 1, 1, 1};
    cout << minSubArrayLen(11, nums) << endl;
  }
}