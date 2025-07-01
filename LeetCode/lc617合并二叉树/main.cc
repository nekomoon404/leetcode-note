#include <iostream>
#include "../tree_node.h"

// 递归: 合并的结果直接赋值给root1
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
  if (!root1 && !root2) return nullptr;
  if (!root1) return root2;
  if (!root2) return root1;

  root1->val += root2->val;
  root1->left = mergeTrees(root1->left, root2->left);
  root1->right = mergeTrees(root1->right, root2->right);

  return root1;
}

int main() {
  {
    BinaryTree tree1({1, 3, 2, 5});
    BinaryTree tree2({2, 1, 3, -1, 4, -1, 7});
    auto res = mergeTrees(tree1.root(), tree2.root());
    std::cout << to_string(res) << std::endl;
  }
  {
    BinaryTree tree1({1});
    BinaryTree tree2({1, 2});
    auto res = mergeTrees(tree1.root(), tree2.root());
    std::cout << to_string(res) << std::endl;
  }
}