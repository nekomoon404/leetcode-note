#include <iostream>
#include <queue>
#include "../tree_node.h"
#include "../vector_print.h"

int maxDepth(TreeNode* root) {
  if (root == nullptr) return 0;

  int depth = 0;
  std::queue<TreeNode*> que;
  que.push(root);

  while (!que.empty()) {
    int size = que.size();
    for (int i = 0; i < size; ++i) {
      TreeNode* node = que.front();
      que.pop();
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
    depth++;
  }
  return depth;
}

int main() {
  {
    BinaryTree tree({3, 9, 20, -1, -1, 15, 7});
    std::cout << maxDepth(tree.root()) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{});
    std::cout << maxDepth(tree.root()) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{1});
    std::cout << maxDepth(tree.root()) << std::endl;
  }
  return 0;
}