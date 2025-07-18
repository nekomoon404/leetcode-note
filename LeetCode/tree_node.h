#pragma once
#include <memory>
#include <queue>
#include <vector>
#include <sstream>
#include <unordered_set>

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

  TreeNode* getNode(int val) {
    return dfs(root_, val);
  }

 private:
  // 根据输入的数组形式表示的二叉树来构造TreeNode*表示的二叉树, -1表示空节点
  TreeNode* buildTree(const std::vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(arr[0]);
    std::queue<TreeNode*> que;
    que.push(root);
    nodes_.insert(root);
    int idx = 1;
    int n = arr.size();

    while (!que.empty() && idx < n) {
      TreeNode* cur = que.front();
      que.pop();

      // 处理左子节点
      if (idx < n && arr[idx] != -1) {
        cur->left = new TreeNode(arr[idx]);
        que.push(cur->left);
        nodes_.insert(cur->left);
      }
      idx++;

      // 处理右子节点
      if (idx < n && arr[idx] != -1) {
        cur->right = new TreeNode(arr[idx]);
        que.push(cur->right);
        nodes_.insert(cur->right);
      }
      idx++;
    }
    return root;
  }
  // 释放二叉树的内存
  void releaseTree(TreeNode* root) {
    // 通过集合统一释放内存
    for (auto node : nodes_) {
      delete node;
    }
    nodes_.clear();
    root_ = nullptr;  // 防止野指针
  }

  TreeNode* dfs(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    TreeNode* left = dfs(root->left, val);
    if (left) return left;
    TreeNode* right = dfs(root->right, val);
    if (right) return right;
    return nullptr;
  }
 private:
  TreeNode* root_;
  std::unordered_set<TreeNode*> nodes_;  // 新增节点集合
};

std::vector<int> to_array(TreeNode* root) {
  std::vector<int> result;
  if (!root) return result;

  std::queue<TreeNode*> que;
  que.push(root);

  while (!que.empty()) {
    TreeNode* node = que.front();
    que.pop();

    if (node) {
      result.push_back(node->val);
      que.push(node->left);
      que.push(node->right);
    } else {
      result.push_back(-1);  // 用 -1 表示 null
    }
  }

  // 移除末尾连续的 null
  while (!result.empty() && result.back() == -1) {
    result.pop_back();
  }

  return result;
}

std::string to_string(TreeNode* root) {
  std::vector<int> nums = to_array(root);
  std::ostringstream oss;
    oss << "[";
    bool first = true;
    for (auto num : nums) {
        if (!first) {
            oss << " ,";
        }
        oss << num;
        first = false;
    }
    oss << "]";
    return oss.str();
}
