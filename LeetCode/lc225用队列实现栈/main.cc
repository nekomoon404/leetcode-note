#include <queue>
#include <iostream>

class MyStack {
 public:
  MyStack() {}

  void push(int x) { que_.push(x); }

  // 将剩余元素从队头弹出再添加到队尾
  int pop() {
    size_t size = que_.size();
    size--;
    while (size--) {
      int tmp = que_.front();
      que_.pop();
      que_.push(tmp);
    }
    int tmp = que_.front();
    que_.pop();
    return tmp;
  }

  int top() {
    int tmp = pop();
    que_.push(tmp);
    return tmp;
  }

  bool empty() { return que_.empty(); }

 private:
  std::queue<int> que_;
};

int main() {
  {
    MyStack st;
    st.push(1);
    st.push(2);
    std::cout << st.top() << std::endl;
    std::cout << st.pop() << std::endl;
    std::cout << st.empty() << std::endl;
  }
  return 0;
}