#include <iostream>
#include <queue>
#include "../tree_node.h"
#include "../vector_print.h"

int maxDepth2(TreeNode* root) {
  if (root == nullptr) return 0;

  int depth = 0;
  std::queue<TreeNode*> que;
  que.push(root);

  while (!que.empty()) {
    int size = que.size();
    for (int i = 0; i < size; ++i) {
      TreeNode* node = que.front();
      que.pop();
      if (node->left) que.push(node->left);
      if (node->right) que.push(node->right);
    }
    depth++;
  }
  return depth;
}

// 自底向上归
int maxDepth(TreeNode* root) {
  if (root == nullptr) return 0;
  return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// 自顶向下递, cnt表示从根节点到node节点路径上的节点个数
int ans = -1;
void dfs(TreeNode* node, int cnt) {
  if (node == nullptr) return;
  cnt++;
  // 叶子节点
  if (!node->left && !node->right) {
    ans = std::max(ans, cnt);
    return;
  }
  dfs(node->left, cnt);
  dfs(node->right, cnt);
}
int maxDepth3(TreeNode* root) {
  dfs(root, 0);
  return root ? ans : 0;
}

int main() {
  {
    BinaryTree tree({3, 9, 20, -1, -1, 15, 7});
    std::cout << maxDepth(tree.root()) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{1});
    std::cout << maxDepth(tree.root()) << std::endl;
  }
  {
    BinaryTree tree(std::vector<int>{});
    std::cout << maxDepth(tree.root()) << std::endl;
  }
  return 0;
}