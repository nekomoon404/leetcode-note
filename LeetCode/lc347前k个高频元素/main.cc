#include <iostream>
#include <map>
#include "../vector_print.h"

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
  std::sort(nums.begin(), nums.end());
  std::multimap<int, int> cnt_val_map;

  int last_val = *nums.begin();
  int count = 0;
  for (int val : nums) {
    if (val == last_val) {
      count++;
    } else {
      cnt_val_map.emplace(count, last_val);
      last_val = val;
      count = 1;
    }
  }
  cnt_val_map.emplace(count, last_val);

  std::vector<int> res;

  for (auto iter = cnt_val_map.rbegin(); iter != cnt_val_map.rend() && k > 0; iter++, k--) {
    res.push_back(iter->second);
  }

  return res;
}
// 时间复杂度: O(n * log n)

int main() {
  {
    std::vector<int> nums{1, 1, 1, 2, 2, 3};
    auto res = topKFrequent(nums, 3);
    std::cout << to_string(res) << std::endl;
  }
  {
    std::vector<int> nums{1, 2};
    auto res = topKFrequent(nums, 2);
    std::cout << to_string(res) << std::endl;
  }
  {
    std::vector<int> nums{1, 1, 2, 2, 3};
    auto res = topKFrequent(nums, 2);
    std::cout << to_string(res) << std::endl;
  }
  return 0;
}
