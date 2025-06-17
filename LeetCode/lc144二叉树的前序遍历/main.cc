#include <iostream>
#include <stack>
#include "../tree_node.h"
#include "../vector_print.h"

void traversal(TreeNode* cur, std::vector<int>& vec) {
  if (cur == nullptr) return;

  vec.push_back(cur->val);
  traversal(cur->left, vec);
  traversal(cur->right, vec);
}

// 递归写法
std::vector<int> preorderTraversal2(TreeNode* root) {
  std::vector<int> res;
  traversal(root, res);
  return res;
}

// 迭代写法
std::vector<int> preorderTraversal3(TreeNode* root) {
  std::vector<int> res;
  if (root == nullptr) return res;

  std::stack<TreeNode*> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode* cur = st.top();
    st.pop();
    res.push_back(cur->val);  // 处理中间节点

    // 右子节点先入栈，最后顺序才是中左右
    if (cur->right) st.push(cur->right);
    if (cur->left) st.push(cur->left);
  }

  return res;
}

// 迭代写法--空节点标记法
std::vector<int> preorderTraversal4(TreeNode* root) {
  std::vector<int> res;
  if (root == nullptr) return res;

  std::stack<TreeNode*> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode* cur = st.top();
    if (cur != nullptr) {
      st.pop();
      if (cur->right) st.push(cur->right); // 右
      if (cur->left) st.push(cur->left); // 左

      st.push(cur);
      st.push(nullptr); // 中
    } else {
      st.pop();
      cur = st.top();
      st.pop();
      res.push_back(cur->val);
    }
  }
  return res;
}

// 迭代--回溯的方法
void visitAlongLeftBranch(TreeNode* root, std::vector<int>& res, std::stack<TreeNode*>& st) {
  while (root) {
    res.push_back(root->val);
    st.push(root->right);
    root = root->left;
  }
}

std::vector<int> preorderTraversal(TreeNode* root) {
  std::vector<int> res;
  if (root == nullptr) return res;

  std::stack<TreeNode*> st;
  TreeNode* x = root;
  while (true) {
    visitAlongLeftBranch(x, res, st);
    if (st.empty()) break;
    x = st.top();
    st.pop();
  }
  return res;
}

int main() {
  {
    BinaryTree tree({1, -1, 2, 3});
    auto res = preorderTraversal(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree({1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9});
    auto res = preorderTraversal(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{});
    auto res = preorderTraversal(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{1});
    auto res = preorderTraversal(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  return 0;
}
