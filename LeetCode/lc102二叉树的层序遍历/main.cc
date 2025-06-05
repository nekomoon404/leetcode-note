#include <iostream>
#include <queue>
#include "../tree_node.h"
#include "../vector_print.h"

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  std::vector<std::vector<int>> res;
  if (root == nullptr) return res;
  
  std::queue<TreeNode*> que;
  que.push(root);

  while(!que.empty()) {
    size_t size = que.size();
    std::vector<int> level;
    for (size_t i = 0; i < size; ++i) {
      TreeNode* node = que.front();
      que.pop();
      level.push_back(node->val);

      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
    res.push_back(level);
  }

  return res;
}

int main() {
  {
    BinaryTree tree({1, -1, 2, 3});
    auto res = levelOrder(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree({1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9});
    auto res = levelOrder(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{});
    auto res = levelOrder(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{1});
    auto res = levelOrder(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  return 0;
}
