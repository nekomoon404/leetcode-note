#include <iostream>
#include <stack>
#include <string>

bool isValid(std::string s) {
  std::stack<char> st;
  for (char ch : s) {
    if (st.empty()) {
      st.push(ch);
      continue;
    }
    char top = st.top();
    if ((top == '(' && ch == ')') || (top == '[' && ch == ']') || (top == '{' && ch == '}')) {
      st.pop();
    } else {
      st.push(ch);
    }
  }
  return st.empty();
}

int main() {
  std::cout << isValid("()") << std::endl;
  std::cout << isValid("()()[]{}") << std::endl;
  std::cout << isValid("((()))") << std::endl;
  std::cout << isValid("([{}])") << std::endl;
  std::cout << isValid("{") << std::endl;
  std::cout << isValid(")(") << std::endl;

  return 0;
}