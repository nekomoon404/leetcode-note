#include <functional>
#include <iostream>
#include "../vector_print.h"

std::array<std::string, 11> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void dfs(int i, int n, const std::string& digits, std::string path, std::vector<std::string>& ans) {
  if (i == n) ans.push_back(path);
  const std::string& ss = mapping[digits[i] - '0'];
  for (char ch : ss) {
    dfs(i + 1, n, digits, path + ch, ans);
    // 等价于：
    //    path += ch;
    //    dfs(i + 1, n, digits, path, ans);
    //    path.pop_back();
  }
}

std::vector<std::string> letterCombinations(std::string digits) {
  if (digits.empty()) return {};
  std::vector<std::string> ans;
  int n = digits.size();
  std::string path;
  dfs(0, n, digits, path, ans);
  return ans;
}

// lambda表达式的写法
std::vector<std::string> letterCombinations2(std::string digits) {
  if (digits.empty()) return {};
  std::vector<std::string> ans;
  int n = digits.size();
  std::string path(n, 0);
  std::function<void(int)> dfs = [&](int i) {
    if (i == n) {
      ans.emplace_back(path);
      return;
    }
    for (char ch : mapping[digits[i] - '0']) {
      path[i] = ch;
      dfs(i + 1);
    }
  };
  dfs(0);
  return ans;
}

// 时间复杂度：O(3 ^ m * 4 ^ n)，m是对应3个字母的数字个数，n是对应4个字母的数字个数
// （push_back string时会调用string的构造函数，时间复杂度是O(m+n)，是否要考虑进去）
// 空间复杂度：O(m + n)

int main() {
  {
    std::string input = "23";
    std::cout << to_string(letterCombinations(input)) << "\n";
  }
  {
    std::string input = "2";
    std::cout << to_string(letterCombinations(input)) << "\n";
  }
  {
    std::string input = "";
    std::cout << to_string(letterCombinations(input)) << "\n";
  }
}