#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void reverseString(vector<char>& s) {
  for (int i = 0, j = s.size() - 1; i < s.size() && i < j; i++, j--) {
    swap(s[i], s[j]);
  }
}

template<typename T>
std::string to_string(const std::vector<T>& nums) {
  std::ostringstream oss;
  oss << "[";
  bool first = true;
  for (auto& num : nums) {
    if (!first) {
      oss << " ,";
    }
    oss << num;
    first = false;
  }
  oss << "]" << std::endl;
  return oss.str();
}

int main() {
  std::vector<char> str = {'h', 'e', 'l', 'l', 'o'};
  reverseString(str);
  std::cout << to_string(str) << std::endl;

  str = {'h', 'e', 'l', 'o'};
  reverseString(str);
  std::cout << to_string(str) << std::endl;

  str = {'h'};
  reverseString(str);
  std::cout << to_string(str) << std::endl;

  str = {};
  reverseString(str);
  std::cout << to_string(str) << std::endl;

  // 或者可以用std::reverse

  return 0;
}