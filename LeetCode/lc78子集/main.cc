#include <functional>
#include <iostream>
#include "../vector_print.h"

// 从选哪个的角度：
void dfs(int i, int n, const std::vector<int>& nums, std::vector<int>& path, std::vector<std::vector<int>>& ans) {
  ans.emplace_back(path);
  if (i == n) return;  // 可以不加这行判断, for循环中限制了j < n, 不会无限递归下去
  for (int j = i; j < n; ++j) {
    path.push_back(nums[j]);
    dfs(j + 1, n, nums, path, ans);
    path.pop_back();
  }
}

// 从选和不选的的角度：
void dfs2(int i, int n, const std::vector<int>& nums, std::vector<int>& path, std::vector<std::vector<int>>& ans) {
  if (i == n) { // 子集构造完毕
    ans.emplace_back(path);
    return;
  }
  // 不选 nums[i]
  dfs2(i + 1, n, nums, path, ans);

  // 选择 nums[i]
  path.push_back(nums[i]);
  dfs2(i + 1, n, nums, path, ans);
  path.pop_back();
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
  if (nums.empty()) return {};
  std::vector<std::vector<int>> ans;
  std::vector<int> path;
  int n = nums.size();
  dfs2(0, n, nums, path, ans);
  return ans;
}

// 时间复杂度：O(n ^ 2)，每个数字都有选或者不选，相当于遍历高为n的满二叉树
// 空间复杂度：O(n)

int main() {
  {
    std::vector<int> nums{1, 2, 3};
    std::cout << to_string(subsets(nums)) << "\n";
  }
  {
    std::vector<int> nums{0};
    std::cout << to_string(subsets(nums)) << "\n";
  }
}