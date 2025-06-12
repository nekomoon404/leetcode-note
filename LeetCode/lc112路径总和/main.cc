#include <iostream>
#include "../tree_node.h"

bool hasPathSum2(TreeNode* root, int targetSum) {
  if (root == nullptr) return false;
  targetSum -= root->val;
  if (targetSum == 0 && !root->left && !root->right) return true;
  bool ret = false;
  if (root->left) {
    ret |= hasPathSum2(root->left, targetSum);
  }
  if (ret) return true;
  if (root->right) {
    ret |= hasPathSum2(root->right, targetSum);
  }
  return ret;
}

// 精简写法
bool hasPathSum(TreeNode* root, int targetSum) {
  if (root == nullptr) return false;
  targetSum -= root->val;
  if (!root->left && !root->right) return targetSum == 0;

  return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}
// 时间复杂度：O(n)
// 空间复杂度：O(n)，最坏情况树退化成链，递归需要O(n)栈空间

int main() {
  {
    BinaryTree tree({1, 2});
    std::cout << hasPathSum(tree.root(), 1) << std::endl;
  }
  {
    BinaryTree tree({5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, 1});
    std::cout << hasPathSum(tree.root(), 18) << std::endl;
  }
  {
    BinaryTree tree({1, 2, 3});
    std::cout << hasPathSum(tree.root(), 5) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{});
    std::cout << hasPathSum(tree.root(), 0) << std::endl;
  }
}