#include <iostream>
#include <string>
using namespace std;

// 记忆化搜索：从后往前遍历
// dfs(i, j)表示由s1[:i]和s2[:j]能否交错组成s3[:i+j]，i和j都表示长度
// 如果s3[i+j-1]来自s1[i-1]，则去掉s3和s1的最后两个字母，问题转移为s3[:i+j-1]能否由s1[:i-1]和s2[:j]交错组成
// 如果s3[i+j-1]来自s2[j-1]，则去掉s3和s2的最后两个字母，问题转移为s3[:i+j-1]能否由s1[:i]和s2[:j-1]交错组成
// 两种情况只要一个为true，则dfs(i, j)为true
// 边界条件：dfs(0, 0)=true，表示检查成功
string gs1, gs2, gs3;
bool dfs(int i, int j, vector<vector<int>>& memo) {
  if (i <= 0 & j <= 0) return true;
  if (memo[i][j] != -1) return memo[i][j];

  bool ans = false;
  // 注意这里要检查i, j>=1，避免下标越界
  // 两个情况都要检查，而不是if, elseif
  if (i >= 1 && gs3[i + j - 1] == gs1[i - 1])
    ans |= dfs(i - 1, j, memo);
  if (j >= 1 && gs3[i + j - 1] == gs2[j - 1])
    ans |= dfs(i, j - 1, memo);
  memo[i][j] = ans;
  return ans;
}

bool isInterleave2(string s1, string s2, string s3) {
  int n = s1.size(), m = s2.size();
  if (n + m != s3.size()) return false;

  gs1 = s1, gs2 = s2, gs3 = s3;
  auto memo = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));

  return dfs(n, m, memo);
}


// 将记忆化搜索翻译成动态规划
bool isInterleave3(string s1, string s2, string s3) {
  int n = s1.size(), m = s2.size();
  if (n + m != s3.size()) return false;
  auto f = vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));
  f[0][0] = true;
  // 这里让i和j从0开始，是因为f(i, 0)和f(0, j)的状态也需要计算；
  // 否则就先单独处理f(i, 0)和f(0, j)，这里让i和j从1开始，内部就不用判断i，j >= 1
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (i >= 1 && s3[i + j - 1] == s1[i - 1]) f[i][j] = f[i - 1][j];
      if (j >= 1 && s3[i + j - 1] == s2[j - 1]) f[i][j] = f[i][j] | f[i][j - 1];
    }
  }
  return f[n][m];
}

// 空间优化
bool isInterleave(string s1, string s2, string s3) {
  int n = s1.size(), m = s2.size();
  if (n + m != s3.size()) return false;
  auto f = vector<bool>(m + 1, false);
  f[0] = true;

  // 这里应该单独处理f(i, 0)和f(0, j)，因为无法从f[m]得出第i层的f[m]是否是更新过的
  for (int j = 1; j <= m; ++j) {
    f[j] = f[j - 1] && s3[j - 1] == s2[j - 1];
  }
  for (int i = 1; i <= n; ++i) {
    // 单独计算f(i, 0)
    f[0] = f[0] && s3[i - 1] == s1[i -1];
    for (int j = 1; j <= m; ++j) {
      f[j] = (f[j] && s3[i + j - 1] == s1[i - 1]) ||
             (f[j - 1] && s3[i + j - 1] == s2[j - 1]);
    }
  }
  return f[m];
}

int main() {
  cout << isInterleave("a", "", "c") << endl;

  cout << isInterleave("aabc", "abad", "aabadabc") << endl;

  cout << isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;

  cout << isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;

  cout << isInterleave("", "", "") << endl;

  cout << isInterleave("", "", "a") << endl;
}