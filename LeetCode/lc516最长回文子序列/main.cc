#include <iostream>
#include <string>
using namespace std;

// f(i, j)表示s[i:j]的回文子序列的最大长度
// 子集划分：考虑左右两个端点选或不选
// 如果s[i]=s[j]，f(i, j) = f(i+1, j-1) + 2
// 如果s[i]!=s[j]，f(i,j) = max(f(i+1, j), f(i, j-1))
// 边界条件：f(i,i)=1，即只有一个字母时它本身就是回文子序列
int longestPalindromeSubseq2(string s) {
  int n = s.size();
  vector<vector<int>> f(n, vector<int>(n, 0));
  // 计算f(i, j)要用到f(i+1, j-1)，因此i要倒序遍历，j要从i+1开始顺序遍历
  for (int i = n - 1; i >= 0; --i) {
    f[i][i] = 1;
    for (int j = i + 1; j < n; ++j) {
      if (s[i] == s[j]) f[i][j] = max(f[i][j], f[i + 1][j - 1] + 2);
      else f[i][j] = max(f[i + 1][j], f[i][j - 1]);
    }
  }
  return f[0][n - 1];
}

// 空间优化：
// 计算第i层的f[j]要用到第i+1层的f[j-1], f[j]，第i层的f[j-1]
// 因此要保存第i+1层的f[j-1]
int longestPalindromeSubseq(string s) {
  int n = s.size();
  vector<int> f(n, 0);
  // 计算f(i, j)要用到f(i+1, j-1)，因此i要倒序遍历，j要从i+1开始顺序遍历
  for (int i = n - 1; i >= 0; --i) {
    f[i] = 1;
    for (int j = i + 1, pre = 0; j < n; ++j) {
      int tmp = f[j];
      if (s[i] == s[j]) f[j] = max(f[j], pre + 2);
      else f[j] = max(f[j], f[j - 1]);
      pre = tmp;
    }
  }
  return f[n - 1];
}

int main() {
  cout << longestPalindromeSubseq("bbbab") << endl;

  cout << longestPalindromeSubseq("cbbd") << endl;
}