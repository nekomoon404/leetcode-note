#include "../tree_node.h"
#include <iostream>

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  // 递归终止条件: 如果找到p活q或者root为空，则返回
  if (root == p || root == q || root == nullptr) return root;

  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);

  // 如果左子树找到p或q, 且右子树找到p或q, 则root是p和q的公共祖先，返回root
  if (left && right) return root;
  // 如果left为空, right不为空, 则返回right, 向上回溯
  // 如果left不为空, right为空, 则返回left
  // 如果left和right都为空，则返回空
  if (!left) return right;
  return left;
}

int main() {
  {
    BinaryTree tree({3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4});
    auto node = lowestCommonAncestor(tree.root(), tree.getNode(5), tree.getNode(1));
    std::cout << node->val << "\n";
  }
  {
    BinaryTree tree({3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4});
    auto node = lowestCommonAncestor(tree.root(), tree.getNode(5), tree.getNode(4));
    std::cout << node->val << "\n";
  }
  {
    BinaryTree tree({1, 2});
    auto node = lowestCommonAncestor(tree.root(), tree.getNode(1), tree.getNode(2));
    std::cout << node->val << "\n";
  }
}