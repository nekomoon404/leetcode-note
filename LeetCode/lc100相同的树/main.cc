#include <iostream>
#include "../tree_node.h"

bool isSameTree2(TreeNode* p, TreeNode* q) {
  if (p == nullptr && q == nullptr) return true;
  if (p == nullptr || q == nullptr || p->val != q->val) return false;
  return isSameTree2(p->left, q->left) && isSameTree2(p->right, q->right);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
  std::queue<TreeNode*> que;
  que.push(p);
  que.push(q);

  while (!que.empty()) {
    TreeNode* left = que.front();
    que.pop();
    TreeNode* right = que.front();
    que.pop();

    if (left == nullptr && right == nullptr) continue;
    if (left == nullptr || right == nullptr || left->val != right->val) return false;

    que.push(left->left);
    que.push(right->left);
    que.push(left->right);
    que.push(right->right);
  }
  return true;
}

int main () {
  {
    BinaryTree tree1({1, 2, 3});
    BinaryTree tree2({1, 2, 3});
    std::cout << isSameTree(tree1.root(), tree2.root()) << std::endl;
  }
  {
    BinaryTree tree1({1, 2});
    BinaryTree tree2({1, -1, 2});
    std::cout << isSameTree(tree1.root(), tree2.root()) << std::endl;
  }
  {
    BinaryTree tree1({1, 2, 1});
    BinaryTree tree2({1, 1, 2});
    std::cout << isSameTree(tree1.root(), tree2.root()) << std::endl;
  }
  return 0;
}