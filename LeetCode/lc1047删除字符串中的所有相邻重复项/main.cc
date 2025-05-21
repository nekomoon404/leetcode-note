#include <iostream>
#include <string>

std::string removeDuplicates(std::string s) {
  std::string res;
  for (char ch : s) {
    if (res.empty()) {
      res.push_back(ch);
      continue;
    }
    if (res.back() == ch) {
      res.pop_back();
    } else {
      res.push_back(ch);
    }
  }
  return res;
}

int main() {
  std::cout << removeDuplicates("a") << std::endl;
  std::cout << removeDuplicates("aa") << std::endl;
  std::cout << removeDuplicates("abba") << std::endl;
  std::cout << removeDuplicates("abccba") << std::endl;
  std::cout << removeDuplicates("abbaca") << std::endl;

  return 0;
}