#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

// 比如输入是"abcabcbb"，枚举到"abc"时，把下一个字符b接到后面，发现有重复元素，
// 则要将左端点右移，直到没有重复元素为止，因为要找的是子串，不是子序列
int lengthOfLongestSubstring(string s) {
  int n = s.size(), left = 0;
  int ans = 0;
  unordered_map<char, int> cnt;  // 记录[left, right]子串中的字符个数
  for (int right = 0; right < n; right++) {
    char ch = s[right];
    cnt[ch]++;
    while (cnt[ch] > 1) {
      cnt[s[left]]--;
      left++;
    }
    ans = max(ans, right - left + 1);
  }
  return ans;
}

int main() {
  cout << lengthOfLongestSubstring("abcabcbb") << endl;

  cout << lengthOfLongestSubstring("bbbbb") << endl;

  cout << lengthOfLongestSubstring("pwwkew") << endl;
}