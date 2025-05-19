#include <iostream>
#include "../vector_print.h"

std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
  if (nums.empty() || nums.size() < 4) {
    return {};
  }

  std::sort(nums.begin(), nums.end());
  std::vector<std::vector<int>> results;

  for (int i = 0; i < nums.size() - 3; i++) {
    // if (nums[i] > target) return results; // 注意这里不能加这个判断，本题的target数据范围是-10^9到10^9，和lc15不一样
    if (i > 0 && nums[i] == nums[i - 1]) continue;  // 第一个数去重

    for (int j = i + 1; j < nums.size() - 2; j++) {
      if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // 第二个数去重

      // int64_t cur_target = (int64_t)target - nums[i] - nums[j];  // 如果要这样先计算cur_target，也要注意整数overflow
      int k = j + 1;
      int l = nums.size() - 1;

      while (k < l) {
        // 本地的num数据范围是-10^9到10^9, sum的结果用64位整数存，防止overflow
        int64_t sum = (int64_t)nums[i] + nums[j] + nums[k] + nums[l];
        if (sum == target) {
          results.push_back({nums[i], nums[j], nums[k], nums[l]});
          do {
            k++;
          } while (k < l && nums[k] == nums[k - 1]);
          l--;
        } else if (sum > target) {
          l--;
        } else if (sum < target) {
          k++;
        }
      }
    }
  }
  return results;
}

int main() {
  {
    std::vector<int> nums{-3, -2, -1, 0, 0, 1, 2, 3};
    auto res = fourSum(nums, 0);
    std::cout << to_string(res) << std::endl;
  }

  {
    std::vector<int> nums{1, 0, -1, 0, -2, 2};
    auto res = fourSum(nums, 0);
    std::cout << to_string(res) << std::endl;
  }

  {
    std::vector<int> nums{1000000000, 1000000000, 1000000000, 1000000000};
    auto res = fourSum(nums, -294967296);
    std::cout << to_string(res) << std::endl;
  }

  {
    std::vector<int> nums{2, 2, 2, 2};
    auto res = fourSum(nums, 8);
    std::cout << to_string(res) << std::endl;
  }

  {
    std::vector<int> nums{0, 1, -1, 0};
    auto res = fourSum(nums, 0);
    std::cout << to_string(res) << std::endl;
  }

  {
    std::vector<int> nums{0, 0, -1, -1};
    auto res = fourSum(nums, 0);
    std::cout << to_string(res) << std::endl;
  }

  {
    std::vector<int> nums{-1};
    auto res = fourSum(nums, 0);
    std::cout << to_string(res) << std::endl;
  }

  {
    std::vector<int> nums{-1, 1};
    auto res = fourSum(nums, 0);
    std::cout << to_string(res) << std::endl;
  }

  return 0;
}