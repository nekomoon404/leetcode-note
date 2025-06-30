#include <iostream>
#include "../tree_node.h"
#include "../vector_print.h"

// 自底向上归
int minDepth(TreeNode* root) {
  if (root == nullptr) return 0;
  if (!root->left && !root->right) return 1;
  if (!root->left) return minDepth(root->right) + 1;
  if (!root->right) return minDepth(root->left) + 1;
  return std::min(minDepth(root->left), minDepth(root->right)) + 1;
}

// 自顶向下递 + 剪枝
int ans = INT_MAX;
// cnt表示从根节点出发到node节点路径上的节点个数
void dfs(TreeNode* node, int cnt) {
  if (node == nullptr) return;
  cnt++;
  if (cnt >= ans) return; // 如果cnt已经大于ans，则继续递归下去也不会让ans变小，直接返回
  if (!node->left && !node->right) {
    ans = cnt;  // 由于已经剪枝过，这里直接让ans=cnt，不用取min
  }
  dfs(node->left, cnt);
  dfs(node->right, cnt);
}
int minDepth2(TreeNode* root) {
  dfs(root, 0);
  return root ? ans : 0;
}

int main() {
  {
    BinaryTree tree({3, 9, 20, -1, -1, 15, 7});
    std::cout << minDepth(tree.root()) << std::endl;
  }
  {
    BinaryTree tree({2, -1, 3, -1, 4, -1, 5, -1, 6});
    std::cout << minDepth(tree.root()) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{1});
    std::cout << minDepth(tree.root()) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{});
    std::cout << minDepth(tree.root()) << std::endl;
  }
}