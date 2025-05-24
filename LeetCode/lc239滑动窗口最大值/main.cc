#include <deque>
#include <iostream>
#include "../vector_print.h"

// 维护一个单调递减队列, 后一个元素要小于等于前一个元素
// 注意是小于等于, 而不是小于, 目的是维护可能作为窗口最大值的元素
class MonoQueue {
 public:
  void push(int val) {
    while (!que_.empty() && que_.back() < val) {
      que_.pop_back();
    }
    que_.push_back(val);
  }
  void pop(int val) {
    if (!que_.empty() && que_.front() == val) {
      que_.pop_front();
    }
  }
  int front() const { return que_.front(); }

 private:
  std::deque<int> que_;
};

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
  int window = 0;
  MonoQueue win;
  std::vector<int> res;

  for (int i = 0; i < k; ++i) {
    win.push(nums[i]);
  }
  res.push_back(win.front());

  for (int i = k; i < nums.size(); ++i) {
    win.pop(nums[i - k]);
    win.push(nums[i]);
    res.push_back(win.front());
  }

  return res;
}
// 时间复杂度：O(n)，每个元素最多被push和pop给单调队列一次
// 空间复杂度：O(k)

int main() {
  {
    std::vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    auto res = maxSlidingWindow(nums, 3);
    std::cout << to_string(res) << std::endl;
  }
  {
    std::vector<int> nums{-7, -8, 7, 5, 7, 1, 6, 0};
    auto res = maxSlidingWindow(nums, 4);
    std::cout << to_string(res) << std::endl;
  }
  {
    std::vector<int> nums{1, 2, 3};
    auto res = maxSlidingWindow(nums, 3);
    std::cout << to_string(res) << std::endl;
  }
  return 0;
}
