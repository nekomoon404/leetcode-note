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
std::vector<int> preorderTraversal(TreeNode* root) {
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
