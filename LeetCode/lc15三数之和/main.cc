#include "../vector_print.h"

#include <iostream>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
  std::vector<std::vector<int>> results;
  if (nums.empty() || nums.size() < 3) {
    return results;
  }
  std::sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 2; i++) {
    // 如果排序后的第一个数就大于0了，则说明无解
    if (nums[i] > 0) return results;

    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }  // 对第一个数去重，避免结果中不能有重复的三元组,

    int j = i + 1;
    int k = nums.size() - 1;

    while (j < k) {
      int sum = nums[i] + nums[j] + nums[k];
      if (sum == 0) {
        results.push_back({nums[i], nums[j], nums[k]});
        do {
          j++;
        } while (j < k && nums[j] == nums[j - 1]);
        k--;
        // 对第二个数去重，对k的去重可以省略，因为前两个数去重的情况下，第三个数不会重复
      } else if (sum > 0) {
        k--;
      } else if (sum < 0) {
        j++;
      }
    }
  }

  return results;
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