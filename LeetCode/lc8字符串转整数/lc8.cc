#include <iostream>
#include <string>
#include <vector>
using namespace std;
int myAtoi(std::string s) {
  bool has_start = false;
  bool positive = true;
  unsigned long long ret = 0;
  for (auto ch : s) {
    if (ch == ' ' && ret == 0 && !has_start) {
      continue;
    }
    if ((ch == '+' || ch == '-') && ret == 0) {
      if (!has_start) {
        positive = ch == '+' ? true : false;
        has_start = true;
        continue;
      } else {
        break;
      }
    }
    if (ch >= '0' && ch <= '9') {
      has_start = true;
      ret = ret * 10 + ch - '0'; // 如果超出unsigned long long的范围则取模
      if (positive && ret >= INT_MAX) {
        return INT_MAX;
      } else if (!positive && ret >= 1LL + INT_MAX){
        return INT_MIN;
      }
    } else {
      break;
    }
  }
  return positive ? ret : -1 * ret;
}

int main() {
  std::cout << myAtoi("42") << std::endl;
  std::cout << myAtoi("   -042") << std::endl;
  std::cout << myAtoi("1337c0d3") << std::endl;
  std::cout << myAtoi("0-1") << std::endl;
  std::cout << myAtoi("words and 987") << std::endl;
  std::cout << myAtoi("+-12") << std::endl;
  std::cout << myAtoi("   +0 123") << std::endl;
  std::cout << myAtoi("20000000000000000000") << std::endl;
  std::cout << myAtoi("-20000000000000000000") << std::endl;
  std::cout << myAtoi("18446744073709551617") << std::endl;
  std::cout << myAtoi("-18446744073709551617") << std::endl;

  return 0;
}