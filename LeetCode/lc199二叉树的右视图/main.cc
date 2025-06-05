#include <iostream>
#include <queue>
#include "../tree_node.h"
#include "../vector_print.h"

std::vector<int> rightSideView(TreeNode* root) {
  std::vector<int> res;
  if (root == nullptr) return res;

  std::queue<TreeNode*> que;
  que.push(root);

  while (!que.empty()) {
    int size = que.size();
    int val = 0;
    for (int i = 0; i < size; ++i) {
      TreeNode* node = que.front();
      que.pop();
      val = node->val;
      
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
    res.push_back(val);
  }
  return res;
}

int main() {
  {
    BinaryTree tree({1, -1, 2, 3});
    auto res = rightSideView(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree({1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9});
    auto res = rightSideView(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{});
    auto res = rightSideView(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{1});
    auto res = rightSideView(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  return 0;
}