#include <stack>
#include <string>
#include <vector>
#include <iostream>

bool isOperator(const std::string& s) { return s == "+" || s == "-" || s == "*" || s == "/"; }

int evalRPN(const std::vector<std::string>& tokens) {
  // 如果遇到操作符就从栈顶pop出两个数字，并将结果压入栈中
  std::stack<int> st;
  for (const std::string& token : tokens) {
    if (!isOperator(token)) {
      st.push(std::stoi(token));
      continue;
    }

    int right = st.top();
    st.pop();
    int left = st.top();
    st.pop();
    int ret = 0;
    if (token == "+") {
      ret = left + right;
    } else if (token == "-") {
      ret = left - right;
    } else if (token == "*") {
      ret = left * right;
    } else {
      ret = left / right;
    }
    st.push(ret);
  }

  return st.top();
}

int main() {
  std::cout << evalRPN({"2","1","+","3","*"}) << std::endl;
  std::cout << evalRPN({"4","13","5","/","+"}) << std::endl;
  std::cout << evalRPN({"10","6","9","3","+","-11","*","/","*","17","+","5","+"}) << std::endl;
  return 0;
}