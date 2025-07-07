#include "../tree_node.h"
#include <iostream>

int cnt = 0;
int ans = 0;
// 二叉搜索树中序遍历序列是严格递增的，找到第k个数字即是答案
void dfs(TreeNode* node) {
  if (node == nullptr) return;
  dfs(node->left);
  --cnt;
  if (cnt == 0)  {
    ans = node->val;
    return;
  }
  dfs(node->right);
}
// 时间复杂度: O(n)
// 空间复杂度: O(n)

int kthSmallest(TreeNode* root, int k) {
  cnt = k;
  ans = 0;
  dfs(root);
  return ans;
}

int main() {
  {
    BinaryTree tree({3, 1, 3, -1, 2});
    std::cout << kthSmallest(tree.root(), 1) << std::endl;
  }
  {
    BinaryTree tree({5, 3, 6, 2, 4, -1, -1, 1});
    std::cout << kthSmallest(tree.root(), 3) << std::endl;
  }
}