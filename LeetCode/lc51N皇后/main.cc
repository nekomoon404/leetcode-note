#include <iostream>
#include "../vector_print.h"
using namespace std;

class Solution {
  vector<bool> onPath;  // 记录col是否有选, c相等
  vector<bool> diag1;   // 记录右上是否有选, r+c相等
  vector<bool> diag2;   // 记录左上是否有选, r-c+n-1相等

  // dfs(row)->dfs(row+1)
  void dfs(int row, const int n, vector<string>& board, vector<vector<string>>& ans) {
    if (row == n) {
      ans.push_back(board);
    }
    // 对于当前行, 遍历可选的列
    for (int col = 0; col < n; ++col) {
      if (!onPath[col] && !diag1[row + col] && !diag2[row - col + n - 1]) {
        board[row][col] = 'Q';
        onPath[col] = diag1[row + col] = diag2[row - col + n - 1] = true;
        dfs(row + 1, n, board, ans);
        onPath[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
        board[row][col] = '.';
      }
    }
  }
  // 时间复杂度: O(n^2 * n!), 全排列个数为n!, 生成答案需要n^2(拷贝board); 不考虑生成答案就是O(n!)
  // 空间复杂度: O(n)
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    onPath.resize(n, false);
    diag1.resize(2 * n - 1, false);
    diag2.resize(2 * n - 1, false);
    dfs(0, n, board, ans);
    return ans;
  }
};

int main() {
  {
    Solution s;
    cout << to_string(s.solveNQueens(4)) << "\n";
  }
  {
    Solution s;
    cout << to_string(s.solveNQueens(1)) << "\n";
  }
}