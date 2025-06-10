#include <iostream>
#include <unordered_map>
#include "../tree_node.h"

std::unordered_map<int, int> val_idx_map;

TreeNode* dfs(std::vector<int>& preorder, std::vector<int>& inorder, int preLeft, int preRight, int inLeft,
              int inRight) {
  if (preRight == preLeft) return nullptr;

  // 前序遍历第一个节点是根节点
  TreeNode* root = new TreeNode(preorder[preLeft]);
  int pIndex = val_idx_map[root->val];
  int leftLength = pIndex - inLeft;
  // 左闭右开区间
  // 中序遍历: 左子树[inLeft, pIndex), 右子树[pIndex + 1, inRight) ==> 左子树的长度为 leftLength = pIndex - inLeft
  // 前序遍历: 左子树[preLeft + 1, preLeft + 1 + leftLength), 右子树[preLeft + leftLength + 1, preRight)
  root->left = dfs(preorder, inorder, preLeft + 1, preLeft + 1 + leftLength, inLeft, pIndex);
  root->right = dfs(preorder, inorder, preLeft + leftLength + 1, preRight, pIndex + 1, inRight);
  return root;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
  if (preorder.empty()) return nullptr;
  for (int i = 0; i < inorder.size(); ++i) {
    val_idx_map[inorder[i]] = i;
  }
  return dfs(preorder, inorder, 0, preorder.size(), 0, inorder.size());
}

int main() {
  {
    std::vector<int> preorder{3, 9, 20, 15, 7};
    std::vector<int> inorder{9, 3, 15, 20, 7};
    TreeNode* root = buildTree(preorder, inorder);
    std::cout << to_string(root) << std::endl;
  }
  {
    std::vector<int> preorder{1};
    std::vector<int> inorder{1};
    TreeNode* root = buildTree(preorder, inorder);
    std::cout << to_string(root) << std::endl;
  }
  return 0;
}