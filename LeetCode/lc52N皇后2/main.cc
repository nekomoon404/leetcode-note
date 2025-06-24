#include <vector>
#include <iostream>
using namespace std;

void dfs(int row, const int n, vector<bool>& onPath, vector<bool>& diag1, vector<bool>& diag2, int& ans) {
  if (row == n) {
    ans++;
    return;
  }
  for (int col = 0; col < n; ++col) {
    if (!onPath[col] && !diag1[row + col] && !diag2[row - col + n - 1]) {
      onPath[col] = diag1[row + col] = diag2[row - col + n - 1] = true;
      dfs(row + 1, n, onPath, diag1, diag2, ans);
      onPath[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
    }
  }
}

// 时间复杂度: O(n!)
// 空间复杂度: O(n)

int totalNQueens(int n) {
  // 用vector<uint8_t>效率更高, vector<bool>是特化版本实现, 内部用bitmap存元素
  vector<bool> onPath(n, false);
  vector<bool> diag1(2 * n - 1, false);
  vector<bool> diag2(2 * n - 1, false);
  int ans = 0;
  dfs(0, n, onPath, diag1, diag2, ans);
  return ans;
}

int main() {
  cout << totalNQueens(4) << "\n";

  cout << totalNQueens(9) << "\n";

  return 0;
}