#include <iostream>
#include "../tree_node.h"

int pre = INT_MIN / 2;  // 防止减法溢出
int ans = INT_MAX;
// 利用二叉搜索树中序遍历序列严格递增的性质
void dfs(TreeNode* root) {
  if (root == nullptr) return;
  dfs(root->left);
  ans = std::min(ans, root->val - pre);
  pre = root->val;
  dfs(root->right);
}

int getMinimumDifference(TreeNode* root) {
  pre = INT_MIN / 2;
  ans = INT_MAX;
  dfs(root);
  return ans;
}

int main() {
  {
    BinaryTree tree({4, 2, 6, 1, 3});
    std::cout << getMinimumDifference(tree.root()) << std::endl;
  }
  {
    BinaryTree tree({1, 0, 48, -1, -1, 12, 49});
    std::cout << getMinimumDifference(tree.root()) << std::endl;
  }
}