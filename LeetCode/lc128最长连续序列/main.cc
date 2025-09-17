#include <vector>
#include <set>
#include <iostream>
using namespace std;

int longestConsecutive(vector<int>& nums) {
  set<int> num_set;
  for (int num : nums) num_set.insert(num);
  
  int last = INT_MIN / 2;
  int ans = 0;
  int length = 0;
  for (int cur : num_set) {
    if (cur - last == 1) {
      length++;
      last = cur;
    } else {
      ans = max(ans, length);
      length = 1;
      last = cur;
    }
  }
  ans = max(ans, length);
  return ans;
}

int main() {
  {
    vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums) << endl;
  }
}