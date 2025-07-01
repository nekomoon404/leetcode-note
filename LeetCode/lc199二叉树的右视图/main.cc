#include <iostream>
#include <queue>
#include "../tree_node.h"
#include "../vector_print.h"

std::vector<int> rightSideView2(TreeNode* root) {
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

// 递归: 先递归右子树, 再递归左子树
// 记录ans和递归深度, 当ans长度=递归深度时, 则把节点值加入到ans
std::vector<int> ans;
void dfs(TreeNode* node, int depth) {
  if (node == nullptr) return;
  if (ans.size() == depth) ans.push_back(node->val);

  dfs(node->right, depth + 1);
  dfs(node->left, depth + 1);
}

std::vector<int> rightSideView(TreeNode* root) {
  ans.clear();
  dfs(root, 0);
  return ans;
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