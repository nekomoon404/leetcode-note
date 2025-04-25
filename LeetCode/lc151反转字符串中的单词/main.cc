#include <iostream>
#include <algorithm>
using namespace std;

void reverseString(std::string& s, size_t start_idx, size_t end_idx) {
  if (s.empty() || start_idx > end_idx) {
    return;
  }
  for (size_t i = start_idx, j = end_idx; i < end_idx && i < j; i++, j--) {
    swap(s[i], s[j]);
  }
}

string reverseWords(string s) {
  size_t st_idx = 0, ed_idx = 0;
  string results;
  while (st_idx < s.size()) {
    if (s[st_idx] == ' ') {
      st_idx++;
    } else {
      ed_idx = st_idx;
      while (s[ed_idx] != ' ' && ed_idx < s.size()) {
        ed_idx++;
      }
      // reverseString(s, st_idx, ed_idx - 1);
      std::reverse(s.begin() + st_idx, s.begin() + ed_idx);
      if (!results.empty()) results += " ";
      results += s.substr(st_idx, ed_idx - st_idx);
      st_idx = ed_idx;
    }
  }
  // reverseString(results, 0, results.size() - 1);
  std::reverse(results.begin(), results.end());
  return results;
}

int main() {
  std::cout << reverseWords("the sky is blue") << std::endl;
  std::cout << reverseWords("  hello world  ") << std::endl;
  std::cout << reverseWords("a good   example") << std::endl;

  std::cout << reverseWords("") << std::endl;
  std::cout << reverseWords(" ") << std::endl;
  std::cout << reverseWords("  ") << std::endl;
  std::cout << reverseWords(" hello ") << std::endl;
  std::cout << reverseWords(" a b c ") << std::endl;
  return 0;
}