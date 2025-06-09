#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include "../tree_node.h"

// 前序遍历，使用后序遍历也可以
TreeNode* invertTree(TreeNode* root) {
  if (root == nullptr) return root;
  std::swap(root->left, root->right);
  invertTree(root->left);
  invertTree(root->right);
  return root;
}

// 前序遍历-迭代写法
TreeNode* invertTree2(TreeNode* root) {
  if (root == nullptr) return root;
  std::stack<TreeNode*> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode* cur = st.top();
    st.pop();

    std::swap(cur->left, cur->right);
    if (cur->right) st.push(cur->right);
    if (cur->left) st.push(cur->left);
  }
  return root;
}

// 层序遍历
TreeNode* invertTree3(TreeNode* root) {
  if (root == nullptr) return root;
  std::queue<TreeNode*> que;
  que.push(root);

  while (!que.empty()) {
    int size = que.size();
    for (int i = 0; i < size; ++i) {
      TreeNode* node = que.front();
      que.pop();

      std::swap(node->left, node->right);
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
  }
  return root;
}

int main() {
  {
    BinaryTree tree({4, 2, 7, 1, 3, 6, 9});
    auto res = invertTree3(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree({2, 1, 3});
    auto res = invertTree3(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree({1});
    auto res = invertTree3(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{});
    auto res = invertTree3(tree.root());
    std::cout << to_string(res) << std::endl;
  }

  return 0;
}
