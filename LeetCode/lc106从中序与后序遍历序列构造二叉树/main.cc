#include <iostream>
#include <unordered_map>
#include "../tree_node.h"

std::unordered_map<int, int> val_idx_map;

TreeNode* dfs(std::vector<int>& inorder, std::vector<int>& postorder, int inLeft, int inRigth, int postLeft,
              int postRight) {
  if (postLeft == postRight) return nullptr;

  TreeNode* root = new TreeNode(postorder[postRight - 1]);
  int pIndex = val_idx_map[root->val];
  int leftLength = pIndex - inLeft;

  // 区间左闭右开
  // 中序遍历: 左子树[inLeft, pIndex), 右子树[pIndex + 1, inRight)
  // 后序遍历: 左子树[postLeft, postLeft + leftLength), 右子树[postLeft + leftLength, postRight - 1)
  root->left = dfs(inorder, postorder, inLeft, pIndex, postLeft, postLeft + leftLength);
  root->right = dfs(inorder, postorder, pIndex + 1, inRigth, postLeft + leftLength, postRight - 1);
  return root;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
  if (postorder.empty()) return nullptr;
  for (int i = 0; i < inorder.size(); ++i) {
    val_idx_map[inorder[i]] = i;
  }
  return dfs(inorder, postorder, 0, inorder.size(), 0, postorder.size());
}

int main() {
  {
    std::vector<int> inorder{9, 3, 15, 20, 7};
    std::vector<int> postorder{9, 15, 7, 20, 3};
    TreeNode* root = buildTree(inorder, postorder);
    std::cout << to_string(root) << std::endl;
  }
  {
    std::vector<int> inorder{1};
    std::vector<int> postorder{1};
    TreeNode* root = buildTree(inorder, postorder);
    std::cout << to_string(root) << std::endl;
  }
}