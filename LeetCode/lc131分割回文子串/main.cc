#include <iostream>
#include "../vector_print.h"

bool check(const std::string& s, int st, int end) {
  if (s.empty() || st > end) return false;
  for (int i = st, j = end; i < j; ++i, --j) {
    if (s[i] != s[j]) return false;
  }
  return true;
}

// 选和不选的角度：last是上次选择的idx，i是本次处理的idx
void dfs(int i, int last, const std::string& s, std::vector<std::string>& path,
         std::vector<std::vector<std::string>>& ans) {
  if (i == s.size()) {
    if (last == s.size()) ans.push_back(path);
    return;
  }

  // 不选s[i]: last不变
  dfs(i + 1, last, s, path, ans);

  // 选s[i]：检查[last, i]的子串
  if (check(s, last, i)) {
    path.push_back(s.substr(last, i - last + 1));
    dfs(i + 1, i + 1, s, path, ans);
    path.pop_back();
  }
}

// 从答案的角度：当前操作是枚举[i, j]的子串;
// 子问题：从下标>=i的后缀中构造回文分割； 下一个子问题：从下标>=j+1的后缀中构造回文分割
void dfs2(int i, const std::string& s, std::vector<std::string>& path,
         std::vector<std::vector<std::string>>& ans) {
  if (i == s.size()) {
    ans.push_back(path);
    return;
  }

  // 枚举子串结束的位置
  for (int j = i; j < s.size(); ++j) {
    if (check(s, i, j)) {
      path.push_back(s.substr(i, j - i + 1));
      dfs2(j + 1, s, path, ans);
      path.pop_back();
    }
  }
}
// 时间复杂度：O(n * 2 ^ n)
// 空间复杂度：O(n)

std::vector<std::vector<std::string>> partition(std::string s) {
  if (s.empty()) return {};
  std::vector<std::vector<std::string>> ans;
  std::vector<std::string> path;
  // dfs(0, 0, s, path, ans);
  dfs2(0, s, path, ans);
  return ans;
}

int main() {
  {
    std::cout << to_string(partition("aab")) << "\n";
  }
  {
    std::cout << to_string(partition("a")) << "\n";
  }
}