#include <iostream>
#include <vector>
using namespace std;

// 双指针l, r指向两个端点, l, r盛水的面积为area, l、r中较低的假设是l, 高度为height
// 如果l, r中间一个点, 高度<height，宽度小了，那么面积肯定比area小
// 如果l, r中间一个点，高度>=height，但宽度小了，面积也比area小
// 那么如果要找到面积更大的端点，肯定不会包含l, 可以直接去掉，找下一个端点
int maxArea(vector<int>& height) {
  int ans = 0;
  int left = 0;
  int right = height.size() - 1;
  while (left < right) {
    int area = (right - left) * min(height[left], height[right]);
    ans = max(ans, area);
    if (height[left] < height[right]) {
      left++;
    } else {
      right--;
    }
  }
  return ans;
}
// 时间复杂度: O(n)
// 空间复杂度: O(1)

int main() {
  {
    vector<int> heights{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(heights) << "\n";
  }
  {
    vector<int> heights{1, 1};
    cout << maxArea(heights) << "\n";
  }
}