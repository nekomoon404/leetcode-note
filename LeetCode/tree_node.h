#pragma once
#include <memory>
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* _left, TreeNode* _right) : val(x), left(_left), right(_right) {}
};

class BinaryTree {
 public:
  BinaryTree() : root_(nullptr) {}
  BinaryTree(const std::vector<int>& arr) { root_ = buildTree(arr); }
  ~BinaryTree() { releaseTree(root_); }
  TreeNode* root() const { return root_; }

 private:
  // 根据输入的数组形式表示的二叉树来构造TreeNode*表示的二叉树, -1表示空节点
  TreeNode* buildTree(const std::vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(arr[0]);
    std::queue<TreeNode*> nodes;
    nodes.push(root);
    int idx = 1;
    int n = arr.size();

    while (!nodes.empty() && idx < n) {
      TreeNode* cur = nodes.front();
      nodes.pop();

      // 处理左子节点
      if (idx < n && arr[idx] != -1) {
        cur->left = new TreeNode(arr[idx]);
        nodes.push(cur->left);
      }
      idx++;

      // 处理右子节点
      if (idx < n && arr[idx] != -1) {
        cur->right = new TreeNode(arr[idx]);
        nodes.push(cur->right);
      }
      idx++;
    }
    return root;
  }
  // 释放二叉树的内存
  void releaseTree(TreeNode* root) {
    if (root == nullptr) return;
    releaseTree(root->left);
    releaseTree(root->right);
    delete root;
  }

 private:
  TreeNode* root_;
};
