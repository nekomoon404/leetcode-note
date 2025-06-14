#include <iostream>
#include <stack>
#include "../tree_node.h"

class BSTIterator {
 private:
  std::stack<TreeNode*> st;

  void leftmost_dfs(TreeNode* root) {
    while (root) {
      st.push(root);
      root = root->left;
    }
  }

 public:
  BSTIterator(TreeNode* root) { leftmost_dfs(root); }

  int next() {
    TreeNode* node = st.top();
    st.pop();
    int res = node->val;
    leftmost_dfs(node->right);
    return res;
  }

  bool hasNext() { return !st.empty(); }
};

int main() {
  {
    BinaryTree tree({7, 3, 15, -1, -1, 9, 20});
    BSTIterator iter(tree.root());
    std::cout << iter.next() << "\n";
    std::cout << iter.next() << "\n";
    std::cout << iter.hasNext() << "\n";
    std::cout << iter.next() << "\n";
    std::cout << iter.hasNext() << "\n";
    std::cout << iter.next() << "\n";
    std::cout << iter.hasNext() << "\n";
    std::cout << iter.next() << "\n";
    std::cout << iter.hasNext() << "\n";
  }
}