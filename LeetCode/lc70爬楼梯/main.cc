#include <iostream>
#include <vector>
using namespace std;

// f(i)表示爬到第i阶的方法数
// f(i) = f(i - 1) + f(i - 2)
// 初始化f[0] = 1, f[1] = 1（为什么f[0] = 1，可以由f[2] = 2倒推出来）
int climbStairs2(int n) {
  vector<int> f(n + 1, 0);
  f[0] = 1, f[1] = 1;
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i - 1] + f[i - 2];
  }
  return f[n];
}

// 空间优化
int climbStairs(int n) {
  if (n < 2) return 1;
  int f0 = 1, f1 = 1, f2 = 0;
  for (int i = 2; i <= n; ++i) {
    f2 = f1 + f0;
    f0 = f1;
    f1 = f2;
  }
  return f2;
}

int main() {
  cout << climbStairs(2) << "\n";
  cout << climbStairs(3) << "\n";
}