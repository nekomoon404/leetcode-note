#include <iostream>
#include "../tree_node.h"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  // 实际上不需要判断当前节点是空节点
  // 如果p和q都在左子树，则返回递归左子树的结果
  if (p->val < root->val && q->val < root->val) {
    return lowestCommonAncestor(root->left, p, q);
  }
  // 如果p和q都在右子树，则返回递归右子树的结果
  if (p->val > root->val && q->val > root->val) {
    return lowestCommonAncestor(root->right, p, q);
  }
  // 其余情况返回当前节点：p和q分别在左右子树、当前节点是p、当前节点是q
  return root;
}

int main() {
  {
    BinaryTree tree({6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5});
    auto node = lowestCommonAncestor(tree.root(), tree.getNode(2), tree.getNode(8));
    std::cout << node->val << "\n";
  }
  {
    BinaryTree tree({6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5});
    auto node = lowestCommonAncestor(tree.root(), tree.getNode(2), tree.getNode(4));
    std::cout << node->val << "\n";
  }
  {
    BinaryTree tree({2, 1});
    auto node = lowestCommonAncestor(tree.root(), tree.getNode(2), tree.getNode(1));
    std::cout << node->val << "\n";
  }
}