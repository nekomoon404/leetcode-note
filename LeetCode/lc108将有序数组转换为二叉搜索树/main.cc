#include "../tree_node.h"
#include <iostream>
using namespace std;

// 将有序数组nums[i]到nums[j-1]转换为平衡二叉搜索树
TreeNode* dfs(vector<int>& nums, int i, int j) {
  if (i == j) return nullptr;
  int mid = (i + j) / 2;
  TreeNode* root = new TreeNode(nums[mid]);
  root->left = dfs(nums, i, mid);
  root->right = dfs(nums, mid + 1, j);
  return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
  return dfs(nums, 0, nums.size());
}

int main() {
  {
    vector<int> nums({-10, -3, 0, 5, 9});
    cout << to_string(sortedArrayToBST(nums)) << endl;
  }
}