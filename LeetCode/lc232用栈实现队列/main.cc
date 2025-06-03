#include <stack>
#include <iostream>

class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { in_st_.push(x); }

  int pop() {
    int tmp = peek();
    out_st_.pop();
    return tmp;
  }

  int peek() {
    if (out_st_.empty()) {
      while (!in_st_.empty()) {
        int tmp = in_st_.top();
        in_st_.pop();
        out_st_.push(tmp);
      }
    }
    return out_st_.top();
  }

  bool empty() { return in_st_.empty() && out_st_.empty(); }

 private:
  std::stack<int> in_st_;
  std::stack<int> out_st_;
};

int main() {
  {
    MyQueue que;
    que.push(1);
    que.push(2);
    std::cout << que.peek() << std::endl;
    std::cout << que.pop() << std::endl;
    std::cout << que.empty() << std::endl;
  }
  return 0;
}