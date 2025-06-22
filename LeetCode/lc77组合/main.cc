#include "../vector_print.h"
#include <iostream>

// 从答案的角度，倒序遍历, 剪枝条件: 备选元素个数小于k - path.size()
void dfs(int i, const int k, std::vector<int>& path, std::vector<std::vector<int>>& ans) {
  if (path.size() == k) {
    ans.push_back(path);
    return;
  }
  int d = k - path.size();
  if (i < d) return;
  for (int j = i; j >= 1; --j) {
    path.push_back(j);
    dfs(j - 1, k, path, ans);
    path.pop_back();
  }
}

// 从答案的角度，顺序遍历，需要额外把n传入
void dfs2(int i, const int k, const int n, std::vector<int>& path, std::vector<std::vector<int>>& ans) {
  if (path.size() == k) {
    ans.push_back(path);
    return;
  }
  int d = k - path.size();
  if (n - i + 1 < d) return;
  for (int j = i; j <= n; ++j) {
    path.push_back(j);
    dfs2(j + 1, k, n,  path, ans);
    path.pop_back();
  }
}

// 从选或不选的角度
void dfs3(int i, const int k, std::vector<int>& path, std::vector<std::vector<int>>& ans) {
  if (path.size() == k) {
    ans.push_back(path);
    return;
  }
  if (i < k - path.size()) return;
  // 选
  path.push_back(i);
  dfs3(i - 1, k, path, ans);
  path.pop_back();
  // 不选
  dfs3(i - 1, k, path, ans);
}

// 时间复杂度: O(k * C(n, k))，即路径长度 * 组合个数
// 空间复杂度: O(k)

std::vector<std::vector<int>> combine(int n, int k) {
  std::vector<int> path;
  std::vector<std::vector<int>> ans;
  // dfs(n, k, path, ans);
  // dfs2(1, k, n, path, ans);
  dfs3(n, k, path, ans);
  return ans;
}

int main() {
  {
    std::cout << to_string(combine(4, 2)) << "\n";
  }
  {
    std::cout << to_string(combine(1, 1)) << "\n";
  }
}