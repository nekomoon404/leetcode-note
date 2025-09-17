#include <iostream>
#include <vector>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
  //计算前缀和，存到哈希表里，然后查找
  int n = nums.size();
  vector<int> pre_sum(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    pre_sum[i + 1] = pre_sum[i] + nums[i];
  }
  unordered_map<int, int> cnt; // {pre_sum, cnt}
  int ans = 0;
  for (int sj : pre_sum) {
    // 查找si = sj - k的前缀和的个数
    ans += cnt.count(sj - k) ? cnt[sj - k] : 0;
    cnt[sj]++;
  }
  return ans;
}

int main() {
  {
    vector<int> nums{1, 1, 1};
    cout << subarraySum(nums, 2) << endl;
  }
  {
    vector<int> nums{1, 2, 3};
    cout << subarraySum(nums, 3) << endl;
  }
}