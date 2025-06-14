#include "../tree_node.h"
#include <queue>
#include <iostream>

int countNodes2(TreeNode* root) {
  if (root == nullptr) return 0;

  int count = 0;
  std::queue<TreeNode*> que;
  que.push(root);
  while (!que.empty()) {
    int size = que.size();
    for (int i = 0; i < size; ++i) {
      TreeNode* node = que.front();
      que.pop();
      count++;
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
  }
  return count;
}
// 时间复杂度：O(n)
// 空间复杂度：O(n)

// 完全二叉树递归到某一深度,其左子树或右子树为满二叉树
// 满二叉树节点的个数：2 ^ depth - 1 （根的depth = 1）
int countNodes(TreeNode* root) {
  if (root == nullptr) return 0;

  TreeNode* left = root->left;
  TreeNode* right = root->right;
  int left_depth = 0, right_depth = 0;
  while (left) {
    left_depth++;
    left = left->left;
  }
  while (right) {
    right_depth++;
    right = right->right;
  }
  if (left_depth == right_depth) return (2 << left_depth) - 1;

  return countNodes(root->left) + countNodes(root->right) + 1;
}

int main() {
  {
    BinaryTree tree({1,2,3,4,5,6});
    std::cout << countNodes(tree.root()) << "\n";
  }
  {
    BinaryTree tree({1});
    std::cout << countNodes(tree.root()) << "\n";
  }
  {
    BinaryTree tree(std::vector<int>{});
    std::cout << countNodes(tree.root()) << "\n";
  }
}