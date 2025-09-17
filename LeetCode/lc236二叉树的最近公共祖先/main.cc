#include "../tree_node.h"
#include <iostream>

// 函数返回值表示最近公共祖先的候选项
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  // 递归终止条件: 如果找到p或者q或者当前节点为空，则返回当前节点
  if (root == p || root == q || root == nullptr) return root;

  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);

  // 如果左子树找到p或q, 且右子树找到p或q, 则当前节点是p和q的公共祖先，返回当前节点
  if (left && right) return root;

  // 如果只有左子树找到，则返回递归左子树的结果
  // 如果只有右子树找到，则返回递归右子树的结果
  // 如果在左右子树中都没找到，则返回空节点；
  // 后两个情况合并成: 如果left不为空, 则返回left，否则返回right
  if (left) return left;
  return right;
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