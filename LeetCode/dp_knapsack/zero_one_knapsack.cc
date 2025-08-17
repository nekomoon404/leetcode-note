#include <iostream>
#include <vector>
using namespace std;

// 01背包问题
// 状态表示：f(i, j)表示的集合：只从前i个物品中选，选出的物品总体积<=j的所有选法，f(i, j)的值表示选法的最大价值
// 状态计算：将f(i, j)划分为更小的子集
//    不选i：f(i - 1, j)
//    选择i：f(i - 1, j - v[i])，再加上物品i的价值 w[i]
//    f(i, j) = max(f(i-1, j), f(i-1, j-v[i]) + w[i])
// 初始值：f(0, 0) = 0

// n表示物品数量，m表示背包容积
int zero_one_knapsack(const vector<int>& v, const vector<int>& w, int m) {
  int n = v.size();
  // f(i, j) 其中i是从0到n，所以要分配 n+1 长度
  vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
  // f[0][0] 到 f[0][m] 都是0，因为没有选任何物品，所以i从1开始遍历;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      f[i][j] = f[i - 1][j];
      if (j >= v[i]) {  // 当j大于v[i]时，选择i的情况才成立
        f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
      }
    }
  }
  return f[n][m];
}
// 时间复杂度: O(n * m)，空间复杂度：O(n * m)


// 优化空间复杂度：注意当计算完f[i+1]之后，f[i]就不再使用了，所以过程中只有两个数组参与状态计算
// f[i][j] = max(f[i-1][j], f[i-1][j-v[i]] + w[i])
// f[i+i][j] = max(f[i][j], f[i][j - v[i+1]] + w[i+1])
// 可以转化为：
// f[i % 2][j] = max(f[(i-1) % 2][j], f[(i-1) % 2][j - v[i]] + w[i])
int zero_one_knapsack2(const vector<int>& v, const vector<int>& w, int m) {
  int n = v.size();
  // f(i, j) 其中i是从0到n，所以要分配 n+1 长度
  vector<vector<int>> f(2, vector<int>(m + 1, 0));
  // f[0][0] 到 f[0][m] 都是0，因为没有选任何物品，所以i从1开始遍历;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      f[i % 2][j] = f[(i - 1) % 2][j];
      if (j >= v[i]) {  // 当j大于v[i]时，选择i的情况才成立
        f[i % 2][j] = max(f[i % 2][j], f[(i - 1) % 2][j - v[i]] + w[i]);
      }
    }
  }
  return f[n % 2][m];
}
// 时间复杂度: O(n * m)，空间复杂度：O(m)


// 进一步优化空间：使用一个数组
// f[j] = max(f[j], f[j - v[i]] + w[i])  // 等号右边是第i-1层的结果
// 因此j要从大到小遍历，这样计算f[j]时，f[j-v[i]]还是第i-i层的值，还没有被更新过
int zero_one_knapsack3(const vector<int>& v, const vector<int>& w, int m) {
  int n = v.size();
  // f(i, j) 其中i是从0到n，所以要分配 n+1 长度
  vector<int> f(m + 1, 0);
  // f[0][0] 到 f[0][m] 都是0，因为没有选任何物品，所以i从1开始遍历;
  for (int i = 1; i <= n; ++i) {
    for (int j = m; j >= v[i]; --j) {
      f[j] = max(f[j], f[j - v[i]] + w[i]);
    }
  }
  return f[m];
}
// 时间复杂度: O(n * m)，空间复杂度：O(m)

int main() {
  cout << zero_one_knapsack({1, 2, 3, 4}, {2, 4, 4, 5}, 5) << "\n";

  cout << zero_one_knapsack2({1, 2, 3, 4}, {2, 4, 4, 5}, 5) << "\n";

  cout << zero_one_knapsack3({1, 2, 3, 4}, {2, 4, 4, 5}, 5) << "\n";
}

