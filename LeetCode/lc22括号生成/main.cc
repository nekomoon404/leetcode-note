#include <iostream>
#include "../vector_print.h"

// 用辅助栈来判断括号匹配；
// 剪枝条件: 1. 左括号数太多，超过n
// 2. 括号与栈顶不匹配
void dfs(int i, const int n, int left_cnt, std::stack<char>& st, std::string& path, std::vector<std::string>& ans) {
  if (i == n * 2) {
    ans.push_back(path);
    return;
  }
  // 选左括号
  if ((st.empty() || st.top() == '(') && left_cnt < n) {
    path[i] = '(';
    st.push('(');
    dfs(i + 1, n, left_cnt + 1, st, path, ans);
    st.pop();
    path[i] = ' ';
  }

  // 选右括号
  if (!st.empty() && st.top() == '(') {
    path[i] = ')';
    st.pop(); // 括号匹配
    dfs(i + 1, n, left_cnt, st, path, ans);
    st.push('('); // 还原
    path[i] = ' ';
  }
}

// 从选或不选的角度: 从2n个下标中选择n个填左括号, 不选的则填右括号
// 剪枝条件: 1. 左括号个数 open < n: 才能继续选左括号; dfs(i, open)-->dfs(i + 1, open + 1)
// 2. 右括号个数 i - open < 左括号个数: 才能继续选右括号; dfs(i, open)-->dfs(i + 1, open)
void dfs2(int i, const int n, int open, std::string& path, std::vector<std::string>& ans) {
  if (i == n * 2) {
    ans.push_back(path);
    return;
  }
  // 选-填左括号
  if (open < n) {
    path[i] = '(';
    dfs2(i + 1, n, open + 1, path, ans);
    path[i] = ' ';
  }
  // 不选-填右括号
  if (i - open < open) {
    path[i] = ')';
    dfs2(i + 1, n, open, path, ans);
  }
}

// 从选哪个的角度, path要全初始化为右括号, 枚举下一个要填左括号的位置
// 剪枝条件: 枚举过程中要时刻保证: 1. 左括号数 open < n
// 2. 右括号数 i - open 不能超过左括号数
// **何时添加答案**: 左括号数 = n
void dfs3(int i, const int n, int open, std::string& path, std::vector<std::string>& ans) {
  if (open == n) {
    ans.push_back(path);
    return;
  }
  for (int j = i; j < n * 2; ++j) {
    if (j - open <= open && open < n) {
      path[j] = '(';
      dfs3(j + 1, n, open + 1, path, ans);
      path[j] = ')';
    }
  }
}

// 时间复杂度: O(n * C(2n, n)), 但由于左右括号之间有约束, 实际的递归次数没这么多 -- 卡特兰数
// 空间复杂度: O(n)

std::vector<std::string> generateParenthesis(int n) {
  std::vector<std::string> ans;
  // std::stack<char> st;
  // std::string path(n * 2, ' ');
  // dfs(0, n, 0, st, path, ans);

//  std::string path(n * 2, ' ');
//  dfs2(0, n, 0, path, ans);

  std::string path(n * 2, ')');
  dfs3(0, n, 0, path, ans);
  return ans;
}

int main() {
  std::cout << to_string(generateParenthesis(3)) << "\n";

  std::cout << to_string(generateParenthesis(1)) << "\n";
}