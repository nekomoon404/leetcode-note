#include <iostream>

// 剑指offer05: 将字符串里的空格替换成"%20"
void replaceSpace(std::string& s) {
  int space_cnt = 0, old_size = s.size();
  for (char c : s) {
    if (c == ' ') {
      space_cnt++;
    }
  }
  s.resize(s.size() + space_cnt * 2);
  for (int i = old_size, j = s.size(); i >= 0; i--, j--) {
    if (s[i] == ' ') {
      s[j] = '0';
      s[j - 1] = '2';
      s[j - 2] = '%';
      j -= 2;
    } else {
      s[j] = s[i];
    }
  }
}

int main() {
  std::string str = "ab c";
  replaceSpace(str);
  std::cout << str << std::endl;

  str = " abc";
  replaceSpace(str);
  std::cout << str << std::endl;

  str = "abc ";
  replaceSpace(str);
  std::cout << str << std::endl;

  str = " a b c ";
  replaceSpace(str);
  std::cout << str << std::endl;

  str = "";
  replaceSpace(str);
  std::cout << str << std::endl;

  str = " ";
  replaceSpace(str);
  std::cout << str << std::endl;

  str = "  ";
  replaceSpace(str);
  std::cout << str << std::endl;

  return 0;
}