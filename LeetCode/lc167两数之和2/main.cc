#include <iostream>
#include "../vector_print.h"

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
  int left = 0;
  int right = numbers.size() - 1;
  while (left < right) {
    int sum = numbers[left] + numbers[right];
    if (sum == target) break;
    if (sum > target) {
      right--;
    } else {
      left++;
    }
  }
  return {left + 1, right + 1};
}
// 时间复杂度: O(n)
// 空间复杂度：O(1)

int main() {
  {
    vector<int> nums{2, 7, 11, 15};
    cout << to_string(twoSum(nums, 9)) << "\n";
  }
  {
    vector<int> nums{2, 3, 4};
    cout << to_string(twoSum(nums, 6)) << "\n";
  }
  {
    vector<int> nums{-1, 0};
    cout << to_string(twoSum(nums, -1)) << "\n";
  }
}