#include <string>
#include "../vector_print.h"
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> findAnagrams(string s, string p) {
  if (s.size() < p.size()) return {};

  vector<int> p_cnt(26, 0);
  for (char ch : p) {
    p_cnt[ch - 'a']++;
  }
  vector<int> ans;
  vector<int> s_cnt(26, 0);
  for (int right = 0; right < p.size(); right++) {
    s_cnt[s[right] - 'a']++;
  }
  if (s_cnt == p_cnt) ans.push_back(0);

  for (int left = 0, right = p.size(); right < s.size(); left++, right++) {
    s_cnt[s[right] - 'a']++;
    s_cnt[s[left] - 'a']--;
    if (s_cnt == p_cnt) ans.push_back(left + 1);
  }
  return ans;
}

// 另一种简洁的写法：
vector<int> findAnagrams2(string s, string p) {
  // 异位词每个字母出现的次数一样
  vector<int> ans;
  vector<int> src_cnt(26, 0);
  vector<int> win_cnt(26, 0);
  for (char ch : p) {
    src_cnt[ch - 'a']++;
  }
  int left = 0;
  for (int right = 0; right < s.size(); ++right) {
    win_cnt[s[right] - 'a']++;
    if (right - left + 1 < p.size()) {
      // 窗口大小不足
      continue;
    }
    if (win_cnt == src_cnt) {
      ans.push_back(left);
    }
    // 移动窗口左边界
    win_cnt[s[left] - 'a']--;
    left++;
  }
  return ans;
}

int main() {
  cout << to_string(findAnagrams("cbaebabacd", "abc")) << endl;

  cout << to_string(findAnagrams("abab", "ab")) << endl;
}