#include <iostream>
#include <vector>
using namespace std;

// 完全背包问题：每个物品可以选择无限次
// 状态表示：f(i, j)表示的集合：只从前i个物品中选，选出的物品总体积<=j的所有选法，f(i, j)的值表示选法的最大价值
// 状态计算：将f(i, j)划分为更小的子集; 注意下面v, w为了方便表示下标从1开始，实际写题时应该是v[i-1], w[i-1]
//    不选i：f(i - 1, j)
//    选择i：f(i - 1, j - v[i]) + w[i], f(i - 1, j - 2 * v[i]) + 2 * w[i], ... , f(i - 1, j - k * v[i]) + k * w[i]
//    需要推导过程才能得出：f(i, j) = max(f(i - 1, j), f(i, j - v[i]) + w[i])
// 初始值：f(0, 0) = 0 (求最值一般初始化为1，求方案数一般初始化为0)

// n表示物品数量，m表示背包容积
int unbounded_knapsack(const vector<int>& v, const vector<int>& w, int m) {
  int n = v.size();
  // f(i, j) 其中i是从0到n，所以要分配 n+1 长度
  vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
  // f[0][0] 到 f[0][m] 都是0，因为没有选任何物品，所以i从1开始遍历;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      f[i][j] = f[i - 1][j];
      if (j >= v[i - 1]) {  // 当j大于v_i时，选择i的情况才成立
        f[i][j] = max(f[i][j], f[i][j - v[i - 1]] + w[i - 1]);
      }
    }
  }
  return f[n][m];
}
// 时间复杂度：O(n * m)，空间复杂度：O(n * m)


// 空间优化为一维数组
// f[j] = max(f[j], f[j - v[i - 1] + w[i - 1])
// 计算第i层时，等号右边的f[j - v[i - 1]是第i层的值，且在计算f[j]之前已经计算过了，所以j可以从小到大遍历
int unbounded_knapsack2(const vector<int>& v, const vector<int>& w, int m) {
  int n = v.size();
  vector<int> f(m + 1, 0);
  // f[0]是0，因为没有选任何物品，所以i从1开始遍历;
  for (int i = 1; i <= n; ++i) {
    for (int j = v[i - 1]; j <= m; ++j) {
      f[j] = max(f[j], f[j - v[i - 1]] + w[i - 1]);
    }
  }
  return f[m];
}
// 时间复杂度：O(n * m)，空间复杂度：O(m)

int main() {
  cout << unbounded_knapsack({1, 2, 3, 4}, {2, 4, 4, 5}, 5) << endl;

  cout << unbounded_knapsack2({1, 2, 3, 4}, {2, 4, 4, 5}, 5) << endl;
}