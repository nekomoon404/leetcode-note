#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
// 保证有效元素的顺序
int removeElement(std::vector<int>& nums, int val) {
  int i = 0;
  for (int j = 0; j < nums.size(); j++) {
    if (nums[j] != val) {
      nums[i] = nums[j];
      i++;
    }
  }
  return i;
}

// 不保证有效元素的顺序
int removeElement2(std::vector<int>& nums, int val) {
  int i = 0, j = nums.size() - 1;
  while (i <= j) {
    if (nums[i] == val) {
      nums[i] = nums[j];
      j--;
    } else {
      i++;
    }
  }
  return i;
}

std::string to_string(const std::vector<int>& nums) {
  std::ostringstream oss;
  oss << "[";
  bool first = true;
  for (const int num : nums) {
    if (!first) {
      oss << " ,";
    }
    oss << num;
    first = false;
  }
  oss << "]" << std::endl;
  return oss.str();
}

int main() {
  std::vector<int> nums = {3, 2, 2, 3};
  std::cout << "expectedNums: " << removeElement(nums, 3) << ", nums: " << to_string(nums) << std::endl;

  nums = {3, 3, 3, 3};
  std::cout << "expectedNums: " << removeElement(nums, 3) << ", nums: " << to_string(nums) << std::endl;

  nums = {3, 2, 2, 3};
  std::cout << "expectedNums: " << removeElement(nums, 0) << ", nums: " << to_string(nums) << std::endl;
  return 0;
}