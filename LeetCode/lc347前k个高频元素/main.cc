#include <iostream>
#include <unordered_map>
#include <queue>
#include "../vector_print.h"

using ValCntPair = std::pair<int, int>;

struct CountCmp {
  bool operator()(const ValCntPair& left, const ValCntPair& right) {
    return left.second > right.second;
  }
};

// 借助小顶堆(优先级队列)找出前k大的数, 小顶堆每次弹出最小的数
std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> val_cnt_map;
  for (int val : nums) {
    val_cnt_map[val]++;
  }

  // 利用优先级队列定义小顶堆, 对频率排序
  std::priority_queue<ValCntPair, std::vector<ValCntPair>, CountCmp> pri_que;

  for (const auto& iter : val_cnt_map) {
    pri_que.emplace(iter.first, iter.second);
    if (pri_que.size() > k) {
      pri_que.pop();
    }
  }

  // 按照频率从高到低将数据保存到res中
  std::vector<int> res(k);
  while (k--) {
    res[k] = pri_que.top().first;
    pri_que.pop();
  }

  return res;
}
// 时间复杂度: O(n * log k)
// 空间复杂度: O(n)

int main() {
  {
    std::vector<int> nums{1, 1, 1, 2, 2, 3};
    auto res = topKFrequent(nums, 3);
    std::cout << to_string(res) << std::endl;
  }
  {
    std::vector<int> nums{1, 2};
    auto res = topKFrequent(nums, 2);
    std::cout << to_string(res) << std::endl;
  }
  {
    std::vector<int> nums{1, 1, 2, 2, 3};
    auto res = topKFrequent(nums, 2);
    std::cout << to_string(res) << std::endl;
  }
  return 0;
}
