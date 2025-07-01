#include <iostream>
#include "../tree_node.h"

// 其实是要比较左右子树，而不是左右子节点
bool compare(TreeNode* left, TreeNode* right) {
  if (left == nullptr && right == nullptr) return true;
  if (left == nullptr || right == nullptr || left->val != right->val) return false;
  return compare(left->left, right->right) && compare(left->right, right->left);
}

bool isSymmetric2(TreeNode* root) {
  if (root == nullptr) return true;
  return compare(root->left, root->right);
}

// 递归: 简洁的写法, 思路和上面一样
// 根节点自身是轴对称的
// 递归比较(左孩子的左子树, 右孩子的右子树), (左孩子的右子树, 右孩子的左子树)是否相同
bool isSymmetric(TreeNode* p, TreeNode* q) {
  if (!p || !q) return p == q;
  return p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
}

bool isSymmetric3(TreeNode* root) {
  if (root == nullptr) return true; // 可以不判空, 题目节点数大于0
  return isSymmetric(root->left, root->right);
}

// 迭代写法, 将左右子树要比较的节点成对插入/弹出队列
bool isSymmetric(TreeNode* root) {
  if (root == nullptr) return true;
  std::queue<TreeNode*> que;
  que.push(root->left);
  que.push(root->right);

  while (!que.empty()) {
    TreeNode* left = que.front();
    que.pop();
    TreeNode* right = que.front();
    que.pop();

    if (left == nullptr && right == nullptr) continue;

    if (left == nullptr || right == nullptr || left->val != right->val) return false;

    que.push(left->left);
    que.push(right->right);
    que.push(left->right);
    que.push(right->left);
  }
  return true;
}

int main() {
  {
    BinaryTree tree({4, 2, 7, 1, 3, 6, 9});
    std::cout << isSymmetric(tree.root()) << std::endl;
  }
  {
    BinaryTree tree({1, 2, 2, 3, 4, 4, 3});
    std::cout << isSymmetric(tree.root()) << std::endl;
  }
  {
    BinaryTree tree({1});
    std::cout << isSymmetric(tree.root()) << std::endl;
  }
  return 0;
}