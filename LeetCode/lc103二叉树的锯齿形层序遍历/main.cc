#include <iostream>
#include <queue>
#include "../tree_node.h"
#include "../vector_print.h"

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
  std::vector<std::vector<int>> res;
  if (root == nullptr) return res;

  std::queue<TreeNode*> que;
  que.push(root);
  int level = 0;

  while (!que.empty()) {
    int size = que.size();
    std::vector<int> vec;
    for (int i = 0; i < size; ++i) {
      TreeNode* node = que.front();
      que.pop();
      vec.push_back(node->val);

      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }

    if (level % 2) std::reverse(vec.begin(), vec.end());
    res.push_back(vec);
    level++;
  }
  return res;
}

int main() {
  {
    BinaryTree tree({3, 9, 20, -1, -1, 15, 7});
    auto res = zigzagLevelOrder(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree({1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9});
    auto res = zigzagLevelOrder(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{});
    auto res = zigzagLevelOrder(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{1});
    auto res = zigzagLevelOrder(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  return 0;
}