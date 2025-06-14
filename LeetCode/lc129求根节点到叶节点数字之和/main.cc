#include <iostream>
#include "../tree_node.h"

int sum = 0;

void dfs(TreeNode* root, int pathSum) {
  if (root == nullptr) return;
  pathSum = pathSum * 10 + root->val;
  if (!root->left && !root->right) {
    sum += pathSum;
    return;
  }
  dfs(root->left, pathSum);
  dfs(root->right, pathSum);
}

int sumNumbers(TreeNode* root) {
  sum = 0;
  dfs(root, 0);
  return sum;
}

int main () {
  {
    BinaryTree tree({1, 2, 3});
    std::cout << sumNumbers(tree.root()) << "\n";
  }
  {
    BinaryTree tree({4, 9, 0, 5, 1});
    std::cout << sumNumbers(tree.root()) << "\n";
  }
}