#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool is_covered(const vector<int>& s_cnt, const vector<int>& p_cnt) {
  for (int i = 'A'; i <= 'Z'; ++i) {
    if (s_cnt[i] < p_cnt[i]) {
      return false;
    }
  }
  for (int i = 'a'; i <= 'z'; ++i) {
    if (s_cnt[i] < p_cnt[i]) {
      return false;
    }
  }
  return true;
}

// 维护滑动窗口，遍历right直到窗口合法，然后left++直到窗口不合法，过程中记录窗口最小值
string minWindow2(string s, string t) {
  vector<int> s_cnt(128, 0);
  vector<int> p_cnt(128, 0);
  for (char ch : t) {
    p_cnt[ch]++;
  }

  int m = s.size();
  int ans_left = -1, ans_right = m;
  int left = 0;
  for (int right = 0; right < m; ++right) {
    // 右端点进窗口
    s_cnt[s[right]]++;
    while (is_covered(s_cnt, p_cnt)) {
      if (right - left < ans_right - ans_left) {
        // 窗口大小=right-left+1，两边都+1，可以不写+1
        ans_left = left;
        ans_right = right;
      }
      s_cnt[s[left]]--; //左端点出窗口
      left++;
    }
  }
  if (ans_left != -1) {
    return s.substr(ans_left, ans_right - ans_left + 1);
  }
  return "";
}
// 时间复杂度: O(52m + n)，空间复杂度：O(1)


// 在时间复杂度上优化为O(m + n)
// 维护一个变量less，表示窗口中有less种字母小于p_cnt中对应字母的次数
// cnt记录字符串p的{字母,次数}，右端点进窗口
string minWindow(string s, string t) {
  vector<int> p_cnt(128, 0);
  int less = 0;  // 记录不重复字母个数
  for (char ch : t) {
    if (p_cnt[ch] == 0) {
      less++;
    }
    p_cnt[ch]++;
  }

  int m = s.size();
  int ans_left = -1, ans_right = m;
  int left = 0;
  for (int right = 0; right < m; ++right) {
    // 右端点进窗口
    char x = s[right];
    p_cnt[x]--;
    if (p_cnt[x] == 0) {
      less--;
    }
    while (less == 0) {
      if (right - left < ans_right - ans_left) {
        // 窗口大小=right-left+1，两边都+1，可以不写+1
        ans_left = left;
        ans_right = right;
      }
      int x = s[left];
      if (p_cnt[x] == 0) {
        less++;
      }
      p_cnt[x]++; //左端点出窗口
      left++;
    }
  }
  if (ans_left != -1) {
    return s.substr(ans_left, ans_right - ans_left + 1);
  }
  return "";
}


int main() {
  {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t) << endl;
  }
  {
    string s = "a";
    string t = "a";
    cout << minWindow(s, t) << endl;
  }
  {
    string s = "a";
    string t = "aa";
    cout << minWindow(s, t) << endl;
  }
}