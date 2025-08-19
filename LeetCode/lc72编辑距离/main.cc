#include <iostream>
#include <string>
using namespace std;

// 状态表示：f(i,j)集合：所有将a[:i]变成b[:j]的操作方式，属性：最小值
// 状态计算：枚举最后一步操作是什么:
// f(i-1, j) + 1, f(i, j-1) + 1, f(i-1, j-1) + a[i]==b[j]
// 边界条件：f(0, j)=j，表示将a[0]变成b[:j]，只能用添加的方式；f(i, 0)=i同理
int minDistance(string word1, string word2) {
  int n = word1.size(), m = word2.size();
  vector<vector<int>> f(n + 1, vector<int>(m + 1, INT_MAX / 2));
  for (int i = 0; i <= n; ++i) f[i][0] = i;
  for (int j = 0; j <= m; ++j) f[0][j] = j;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
      f[i][j] = min(f[i][j], f[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1));
    }
  }
  return f[n][m];
}

int main() {
  cout << minDistance("horse", "ros") << "\n";

  cout << minDistance("intention", "execution") << "\n";
}