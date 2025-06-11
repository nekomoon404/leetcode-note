#include <iostream>
#include "../tree_node.h"

TreeNode* head = nullptr;

// 头插法, 需要按右-左-根遍历树
void flatten(TreeNode* root) {
  if (root == nullptr) return;
  flatten(root->right);
  flatten(root->left);
  root->left = nullptr;
  root->right = head;
  head = root;
}

// 分治的思想
TreeNode* dfs(TreeNode* root) {
  if (root == nullptr) return root;
  TreeNode* left_tail = dfs(root->left);
  TreeNode* right_tail = dfs(root->right);

  if (left_tail) {
    left_tail->right = root->right;  // 左子树链表-->右子树链表
    root->right = root->left;  // 当前根节点-->左右子树合并后的链表
    root->left = nullptr;
  }
  // 返回当前的尾节点
  return right_tail ? right_tail : (left_tail ?  left_tail : root);
}

void flatten2(TreeNode* root) {
  root = dfs(root);
}

int main() {
  {
    BinaryTree tree({1, 2, 5, 3, 4, -1, 6});
    flatten2(tree.root());
    std::cout << to_string(tree.root()) << std::endl;
  }
  {
    BinaryTree tree({1});
    flatten2(tree.root());
    std::cout << to_string(tree.root()) << std::endl;
  }
}