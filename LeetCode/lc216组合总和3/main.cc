#include <iostream>
#include "../vector_print.h"

// 从答案的角度，剪枝条件：假设还要选d=k-m个数(m为当前path的长度)，还需要选和为t的数字
// 1. 剩余数字数目不够 i < d
// 2. t < 0
// 3. 剩余数字即使全部选最大的，和也不够t
void dfs(int i, const int k, int target, std::vector<int>& path, std::vector<std::vector<int>>& ans) {
  if (path.size() == k && target == 0) {
    ans.push_back(path);
    return;
  }
  // 剪枝条件也可以放到判断ans push_back之前
  int d = k - path.size();
  if (i < d || target < 0 || (i + i - d + 1) * d / 2 < target) return;

  for (int j = i; j >= 1; --j) {
    path.push_back(j);
    target -= j;
    dfs(j - 1, k, target, path, ans);
    target += j;
    path.pop_back();
  }
}

// 从选或不选的角度，剪枝条件同上
void dfs2(int i, const int k, int target, std::vector<int>& path, std::vector<std::vector<int>>& ans) {
  if (path.size() == k && target == 0) {
    ans.push_back(path);
    return;
  }
  // 剪枝条件也可以放到ans push_back之前
  int d = k - path.size();
  if (i < d || target < 0 || (i + i - d + 1) * d / 2 < target) return;

  // 选
  path.push_back(i);
  // target参数是值传递，因此dfs2这一行调用结束后，target还是原来的值，相当于回溯了
  dfs2(i - 1, k, target - i, path, ans);
  path.pop_back();
  // 不选
  dfs2(i - 1, k, target, path, ans);
}

// 时间复杂度: O(k * C(9, k))
// 空间复杂度: O(k)

std::vector<std::vector<int>> combinationSum3(int k, int n) {
  std::vector<int> path;
  std::vector<std::vector<int>> ans;
  // dfs(9, k, n, path, ans);
  dfs2(9, k, n, path, ans);
  return ans;
}

int main() {
  std::cout << to_string(combinationSum3(3, 7)) << "\n";

  std::cout << to_string(combinationSum3(3, 9)) << "\n";

  std::cout << to_string(combinationSum3(4, 1)) << "\n";
}