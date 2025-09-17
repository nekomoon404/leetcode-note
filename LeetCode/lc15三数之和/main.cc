#include "../vector_print.h"

#include <iostream>
using namespace std;

// 题目要求{i, j, k}不重复，因此需要对i和j去重，i和j去重后，k就不能重复了
vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  int n = nums.size();
  for (int i = 0; i < n - 2; ++i) {
    int x = nums[i];
    if (i > 0 && x == nums[i - 1]) continue;  // 对i去重

    // 如果x加上最小的两个数已经大于0，或者x加上最大的两个数已经小于0，则跳过
    if (x + nums[i + 1] + nums[i + 2] > 0) continue;
    if (x + nums[n - 2] + nums[n - 1] < 0) continue;

    int j = i + 1;
    int k = n - 1;
    while (j < k) {
      int sum = x + nums[j] + nums[k];
      if (sum > 0) {
        k--;
      } else if (sum < 0) {
        j++;
      } else {
        ans.push_back({x, nums[j], nums[k]});
        j++;
        while (j < k && nums[j] == nums[j - 1]) j++;  // 对j去重
        k--; //对k的去重可以省略，因为前两个数去重的情况下，第三个数不可能重复
      }
    }
  }
  return ans;
}
// 时间复杂度：O(n ^ 2)
// 空间复杂度：O(1)

int main() {
  {
    std::vector<int> nums{2, -3, 0, -2, -5, -5, -4, 1, 2, -2, 2, 0, 2, -4, 5, 5, -10};
    auto res = threeSum(nums);
    std::cout << to_string(res) << std::endl;
  }

  {
    std::vector<int> nums{-1, 0, 1, 2, -1, -4};
    auto res = threeSum(nums);
    std::cout << to_string(res) << std::endl;
  }

  {
    std::vector<int> nums{0, 0, 0};
    auto res = threeSum(nums);
    std::cout << to_string(res) << std::endl;
  }

  {
    std::vector<int> nums{0, 1, -1};
    auto res = threeSum(nums);
    std::cout << to_string(res) << std::endl;
  }

  {
    std::vector<int> nums{0, 0, -1};
    auto res = threeSum(nums);
    std::cout << to_string(res) << std::endl;
  }

  {
    std::vector<int> nums{-1};
    auto res = threeSum(nums);
    std::cout << to_string(res) << std::endl;
  }

  {
    std::vector<int> nums{-1, 1};
    auto res = threeSum(nums);
    std::cout << to_string(res) << std::endl;
  }

  return 0;
}