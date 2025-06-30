#include <iostream>
#include <map>
#include "../tree_node.h"
#include "../vector_print.h"

using namespace std;
using PII = std::pair<int, int>;

// dfs遍历二叉树的过程中, 记录当前的row和col
// 维护key是col, value是{row, val}列表的map
// dfs结束后遍历map, 对每个value的{row, val}列表排序，取排序后的{val}列表即是答案
map<int, vector<PII>> groups;
void dfs(TreeNode* node, int row, int col) {
  if (node == nullptr) return;
  groups[col].emplace_back(row, node->val);
  if (node->left == node->right) return;

  dfs(node->left, row + 1, col - 1);
  dfs(node->right, row + 1, col + 1);
}

vector<vector<int>> verticalTraversal(TreeNode* root) {
  groups.clear();
  dfs(root, 0, 0);

  vector<vector<int>> ans;
  ans.reserve(groups.size());
  for (auto& iter : groups) {
    vector<PII>& group = iter.second;
    std::sort(group.begin(), group.end());
    vector<int> path;
    path.reserve(group.size());
    for (const auto& item : group) {
      path.emplace_back(item.second);
    }
    ans.emplace_back(std::move(path));
  }
  return ans;
}

// 时间复杂度: O(n * log n), n为节点个数, 瓶颈在排序上，最坏情况下有n/4个节点在同一个坐标
// 空间复杂度: O(n)

int main() {
  {
    BinaryTree tree({3, 9, 20, -1, -1, 15, 7});
    std::cout << to_string(verticalTraversal(tree.root())) << "\n";
  }
  {
    BinaryTree tree({1, 2, 3, 4, 5, 6, 7});
    std::cout << to_string(verticalTraversal(tree.root())) << "\n";
  }
  {
    BinaryTree tree({1, 2, 3, 4, 6, 5, 7});
    std::cout << to_string(verticalTraversal(tree.root())) << "\n";
  }
}