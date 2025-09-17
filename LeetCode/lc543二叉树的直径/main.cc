#include "../tree_node.h"
#include <iostream>
using namespace std;

// 经过某个节点的路径的节点数 = 以该节点为根的左子树深度 + 右子树深度 + 1
// 路径长度 = 路径节点数 - 1
int length = 1;
int depth(TreeNode* node) {
  if (node == nullptr) return 0;
  int left = depth(node->left);
  int right = depth(node->right);
  length = max(length, left + right + 1);
  return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
  length = 1;
  depth(root);
  return length - 1;
}

int main() {
  {
    BinaryTree tree({1, 2, 3, 4, 5});
    cout << diameterOfBinaryTree(tree.root()) << endl;
  }
  {
    BinaryTree tree({1, 2});
    cout << diameterOfBinaryTree(tree.root()) << endl;
  }
}