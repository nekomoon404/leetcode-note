#include "../vector_print.h"
#include <iostream>

// 从选哪个的角度, 设剩余要选的数之和为t, 剪枝的条件:
// 1. t < 0;
// 2. 将nums从小到大排序，如果nums[j] > t, 则备选中最小的数已经大于t, 无法将t减成0;
// (条件1可省略, 因为t不会为负数)
void dfs(int i, const std::vector<int> nums, int target, std::vector<int>& path, std::vector<std::vector<int>>& ans) {
  if (target == 0) {
    ans.push_back(path);
    return;
  }

  for (int j = i; j < nums.size() && nums[j] <= target; ++j) {
    path.push_back(nums[j]);
    // 注意下一次递归从j开始, 而不是j + 1, 表示j可以重复选择
    dfs(j, nums, target - nums[j], path, ans);
    path.pop_back();
  }
}

// 从选或不选的角度, nums中每个数选或者不选
// 选: dfs(i, t) -> dfs(i, t - nums[i]);  不选: dfs(i, t) -> dfs(i + 1, t)
// 递归终止条件:  i == n 或者 最小的数 > target
void dfs2(int i, const std::vector<int>& nums, int target, std::vector<int>& path, std::vector<std::vector<int>>& ans) {
  if (target == 0) {
    ans.push_back(path);
    return;
  }
  if (i == nums.size() || target < nums[i]) return;

  // 选
  if (nums[i] <= target) {
    path.push_back(nums[i]);
    dfs2(i, nums, target - nums[i], path, ans);
    path.pop_back();
  }

  // 不选
  dfs2(i + 1, nums, target, path, ans);
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  std::vector<int> path;
  std::vector<std::vector<int>> ans;
  dfs2(0, candidates, target, path, ans);
  return ans;
}

// 时间复杂度: O(n * 2 ^ n), 这是较松的上界, n个位置每个位置考虑选或不选, 较紧的上界不好计算
// 空间复杂度: O(target), path长度至多为target

int main() {
  {
    std::vector<int> nums{2, 3, 6, 7};
    std::cout << to_string(combinationSum(nums, 7) )<< "\n";
  }
  {
    std::vector<int> nums{2, 3, 5};
    std::cout << to_string(combinationSum(nums, 8) )<< "\n";
  }
  {
    std::vector<int> nums{2};
    std::cout << to_string(combinationSum(nums, 1) )<< "\n";
  }
}