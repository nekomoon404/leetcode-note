#include <iostream>
#include "../tree_node.h"

// 前序遍历, 额外传两个参数, 表示根节点值必须处于这个开区间范围内
bool isValidBST2(TreeNode* root, long long left = LLONG_MIN, long long right = LLONG_MAX) {
  if (root == nullptr) return true;
  long long val = root->val;

  // 访问根节点
  if (left >= val || val >= right) return false;

  // 递归左右子树
  return isValidBST2(root->left, left, val) && isValidBST2(root->right, val, right);
}

// 中序遍历, 二叉搜索树的中序遍历序列是严格递增的数组，因此只需判断相邻元素是否是递增的
long long pre = LLONG_MIN;
bool isValidBST3(TreeNode* root) {
  if (root == nullptr) return true;
  if (!isValidBST3(root->left)) return false;

  if (pre >= root->val) return false;
  pre = root->val;

  return isValidBST3(root->right);
}

// 后序遍历, 先递归再判断, 返回子树的最小值和最大值，供根节点来判断
std::pair<long long, long long> dfs(TreeNode* root) {
  if (root == nullptr) return {LLONG_MAX, LLONG_MIN};
  long long val = root->val;

  auto[l_min, l_max] = dfs(root->left);
  if (l_max >= val) return {LLONG_MIN, LLONG_MAX};

  auto[r_min, r_max] = dfs(root->right);
  if (val >= r_min) return {LLONG_MIN, LLONG_MAX};

  return {std::min(l_min, val), std::max(r_max, val)};
}

bool isValidBST(TreeNode* root) {
  return dfs(root).second != LLONG_MAX;
}

int main() {
  {
    pre = LLONG_MIN;
    BinaryTree tree({5, 1, 4, -1, -1, 3, 6});
    std::cout << isValidBST(tree.root()) << "\n";
  }
  {
    pre = LLONG_MIN;
    BinaryTree tree({2, 1, 3});
    std::cout << isValidBST(tree.root()) << "\n";
  }
  {
    pre = LLONG_MIN;
    BinaryTree tree({INT_MIN});
    std::cout << isValidBST(tree.root()) << "\n";
  }
}