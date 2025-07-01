#include <iostream>
#include "../tree_node.h"

// 平衡二叉树: 左右子树高度差小于等于1
// 递归计算左右子树的高度, 如果高度差大于则令高度值为-1
// -1归到上层, 判断为-1则返回-1, 即将不平衡的结果向上传递
int dfs(TreeNode* node) {
  if (node == nullptr) return 0;

  int left_height = dfs(node->left);
  if (left_height == -1) return -1;

  int right_height = dfs(node->right);
  if (right_height == -1 || std::abs(left_height - right_height) > 1) return -1;

  return std::max(left_height, right_height) + 1;
}

bool isBalanced(TreeNode* root) { return dfs(root) != -1; }

int main() {
  {
    BinaryTree tree({3, 9, 20, -1, -1, 15, 7});
    std::cout << isBalanced(tree.root()) << std::endl;
  }
  {
    BinaryTree tree({1, 2, 2, 3, 3, -1, -1, 4, 4});
    std::cout << isBalanced(tree.root()) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{});
    std::cout << isBalanced(tree.root()) << std::endl;
  }
}