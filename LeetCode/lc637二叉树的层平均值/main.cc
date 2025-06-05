#include <iostream>
#include <queue>
#include "../tree_node.h"
#include "../vector_print.h"

std::vector<double> averageOfLevels(TreeNode* root) {
  std::vector<double> res;
  if (root == nullptr) return res;

  std::queue<TreeNode*> que;
  que.push(root);

  while (!que.empty()) {
    size_t size = que.size();
    double sum = 0.0;
    for (size_t i = 0; i < size; ++i) {
      TreeNode* node = que.front();
      que.pop();
      sum += node->val;
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
    res.push_back(sum / size);
  }

  return res;
}

int main() {
  {
    BinaryTree tree({1, -1, 2, 3});
    auto res = averageOfLevels(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree({INT_MAX, INT_MAX, INT_MAX});
    auto res = averageOfLevels(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree({1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9});
    auto res = averageOfLevels(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{});
    auto res = averageOfLevels(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{1});
    auto res = averageOfLevels(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  return 0;
}