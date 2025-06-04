#include <iostream>
#include <stack>
#include "../tree_node.h"
#include "../vector_print.h"

void traversal(TreeNode* cur, std::vector<int>& vec) {
  if (cur == nullptr) return;

  traversal(cur->left, vec);
  traversal(cur->right, vec);
  vec.push_back(cur->val);
}

std::vector<int> postorderTraversal2(TreeNode* root) {
  std::vector<int> res;
  traversal(root, res);
  return res;
}

std::vector<int> postorderTraversal(TreeNode* root) {
  std::vector<int> res;
  if (root == nullptr) return res;

  std::stack<TreeNode*> st;
  st.push(root);

  while (!st.empty()) {
    TreeNode* cur = st.top();
    st.pop();
    res.push_back(cur->val);
    
    // 先左子节点入栈，res顺序为中右左
    if (cur->left) st.push(cur->left);
    if (cur->right) st.push(cur->right);
  } 
  // 反转，res顺序为左右中
  std::reverse(res.begin(), res.end());
  return res;
}

int main() {
  {
    BinaryTree tree({1, -1, 2, 3});
    auto res = postorderTraversal(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree({1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9});
    auto res = postorderTraversal(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{});
    auto res = postorderTraversal(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{1});
    auto res = postorderTraversal(tree.root());
    std::cout << to_string(res) << std::endl;
  }
  return 0;
}
