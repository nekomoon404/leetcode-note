#include <iostream>
#include "../vector_print.h"
using namespace std;

void dfs(int i, const vector<int>& nums, vector<bool>& onPath, vector<int>& path,
         vector<vector<int>>& ans) {
  if (i == nums.size()) {
    ans.push_back(path);
    return;
  }
  // 遍历onPath, 找下一个可以选择的数, 赋值给path[i]
  for (int j = 0; j < nums.size(); ++j) {
    if (!onPath[j]) {
      path[i] = nums[j];
      onPath[j] = true;
      dfs(i + 1, nums, onPath, path, ans);
      onPath[j] = false;
      path[i] = 0;  // 也可以不写这行, 因为path长度固定, 后面一定会覆盖新值
    }
  }
}
// 时间复杂度: O(n * n!)，全排列的个数是n!
// 空间复杂度: O(n)

vector<vector<int>> permute(vector<int>& nums) {
  vector<int> path(nums.size(), 0);
  vector<bool> onPath(nums.size(), false);
  vector<vector<int>> ans;
  dfs(0, nums, onPath, path, ans);
  return ans;
}

int main() {
  {
    vector<int> nums{1, 2, 3};
    cout << to_string(permute(nums)) << "\n";
  }
  {
    vector<int> nums{0, 1};
    cout << to_string(permute(nums)) << "\n";
  }
  {
    vector<int> nums{1};
    cout << to_string(permute(nums)) << "\n";
  }
}