#include <iostream>
#include <vector>
using namespace std;

// 假设每个位置有宽度为1的桶，需要计算min(左边木板高度，右边木板高度)-height[i]就是该位置能接的水
// 左边木板高度=左边的最大高度，因为低于这个高度的水不会流出去
// 同理，右边木板高度=右边的最大高度

// 方法一：借助两个数组
// 第一个数组存储从最左边到第i个位置的最大高度，即前缀最大值
// 第二个数组存储从最右边到第i个位置的最大高度，即后缀最大值
int trap2(vector<int>& height) {
  int n = height.size();
  vector<int> pre_max(n, 0);
  pre_max[0] = height[0];
  for (int i = 1; i < n; ++i) {
    pre_max[i] = max(pre_max[i - 1], height[i]);
  }
  vector<int> suf_max(n, 0);
  suf_max[n - 1] = height[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    suf_max[i] = max(suf_max[i + 1], height[i]);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += min(pre_max[i], suf_max[i]) - height[i];
  }
  return ans;
}
// 时间复杂度: O(n)
// 空间复杂度: O(n)

// 方法二：在空间上优化
// 两个指针指向0和n-1，假设已经算出了一部分前缀最大值，和一部分后缀最大值
// 如果前缀最大值比后缀最大值小，则左边的木桶能装的水就是前缀最大值-height[left]，然后向左扩展left++
// 如果后缀最大值比前缀最大值小，则右边的木桶能装的水就是后缀最大值-height[right], 然后向右扩展right--
int trap(vector<int>& height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int pre_max = 0, suf_max = 0;

  int ans = 0;
  // 注意这里是小于等于
  while (left <= right) {
    // 更新前缀最大值和后缀最大值
    pre_max = max(pre_max, height[left]);
    suf_max = max(suf_max, height[right]);
    if (pre_max < suf_max) {
      ans += pre_max - height[left];
      left++;
    } else {
      // 如果pre_max = suf_max，则更新哪边都可以
      ans += suf_max - height[right];
      right--;
    }
  }
  return ans;
}
// 时间复杂度: O(n)
// 空间复杂度: O(1)

int main() {
  {
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(height) << "\n";
  }
  {
    vector<int> height{4, 2, 0, 3, 2, 5};
    cout << trap(height) << "\n";
  }
}