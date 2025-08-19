#include <iostream>
#include <string>
using namespace std;

// f(i, j)集合：a[:i]与b[:j]的公共子序列的集合(下标从1开始)，属性：公共子序列的最大长度
// 划分子集：根据a[i]与b[j]选或者不选：
// f(i-1, j-1), f(i-1, j), f(i, j-1), 当a[i]=b[j]时：f(i-1, j-1) + 1
// 而f(i-1, j-1)是包含在f(i-1, j)或者f(i, j-1)中的
int longestCommonSubsequence(string text1, string text2) {
  int n = text1.size(), m = text2.size();
  vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      f[i][j] = max(f[i - 1][j], f[i][j - 1]);
      if (text1[i - 1] == text2[j - 1]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
    }
  }
  return f[n][m];
}

int main () {
  cout << longestCommonSubsequence("abcde", "ace") << "\n";

  cout << longestCommonSubsequence("abc", "abc") << "\n";

  cout << longestCommonSubsequence("abc", "def") << "\n";
}