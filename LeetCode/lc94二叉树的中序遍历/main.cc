#include <iostream>
#include <stack>
#include "../tree_node.h"
#include "../vector_print.h"

void traversal(TreeNode* cur, std::vector<int>& vec) {
  if (cur == nullptr) return;

  traversal(cur->left, vec);
  vec.push_back(cur->val);
  traversal(cur->right, vec);
}

std::vector<int> inorderTraversal2(TreeNode* root) {
  std::vector<int> res;
  traversal(root, res);
  return res;
}

std::vector<int> inorderTraversal3(TreeNode* root) {
  std::vector<int> res;
  if (root == nullptr) return res;

  std::stack<TreeNode*> st;
  TreeNode* cur = root;

  while (cur || !st.empty()) {
    if (cur) {
      st.push(cur);
      cur = cur->left;  // 左
    } else {
      cur = st.top();
      st.pop();
      res.push_back(cur->val); // 中
      cur = cur->right; // 右
    }
  }

  return res;
}

// 迭代写法--空节点标记法
std::vector<int> inorderTraversal(TreeNode* root) {
  std::vector<int> res;
  if (root == nullptr) return res;

  std::stack<TreeNode*> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode* cur = st.top();
    if (cur != nullptr) {
      st.pop();
      if (cur->right) st.push(cur->right); // 右

      st.push(cur);
      st.push(nullptr); // 中

      if (cur->left) st.push(cur->left); // 左
    } else {
      st.pop();
      cur = st.top();
      st.pop();
      res.push_back(cur->val);
    }
  }
  return res;
}

int main() {
  {
    BinaryTree tree({1, -1, 2, 3});
    auto res = inorderTraversal(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree({1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9});
    auto res = inorderTraversal(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{});
    auto res = inorderTraversal(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{1});
    auto res = inorderTraversal(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  return 0;
}
