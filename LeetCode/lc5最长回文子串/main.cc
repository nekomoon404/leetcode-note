#include <iostream>
#include <string>
using namespace std;

// 中心扩散方法：枚举第i个字母，向两边扩展，并考虑奇数和偶数长度的子串
string longestPalindrome(string s) {
  int left = 0, right = 0, len = 0;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    // odd length
    int l = i, r = i;
    while (l >= 0 && r < n && s[l] == s[r]) {
      if (r - l + 1 > len) {
        left = l;
        right = r;
        len = r - l + 1;
      }
      l--;
      r++;
    }

    // even length
    l = i, r = i + 1;
    while (l >= 0 && r < n && s[l] == s[r]) {
      if (r - l + 1 > len) {
        left = l;
        right = r;
        len = r - l + 1;
      }
      l--;
      r++;
    }
  }
  return s.substr(left, right - left + 1);
}
// 时间复杂度：O(n^2)，空间复杂度：O(1)

int main() {
  cout << longestPalindrome("babad") << endl;

  cout << longestPalindrome("cbbd") <<  endl;
}