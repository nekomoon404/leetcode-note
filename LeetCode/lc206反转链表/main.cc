#include "../list_node.h"
#include<iostream>

ListNode* reverseList(ListNode* head) {
  ListNode* tmp = nullptr;
  ListNode* cur = head;
  ListNode* pre = nullptr;

  while (cur) {
      tmp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tmp;
  }

  return pre;
}

int main() {
  {
    LinkedList list({1, 2, 3, 4, 5});
    ListNode* ret = reverseList(list.getHead());
    std::cout << to_string(ret);
  }

  {
    LinkedList list({1});
    ListNode* ret = reverseList(list.getHead());
    std::cout << to_string(ret);
  }
  
  {
    // LinkedList list({}); // 会歧义, 会匹配到参数为vetor的构造函数或者移动构造函数
    LinkedList list(std::vector<int>{});
    ListNode* ret = reverseList(list.getHead());
    std::cout << to_string(ret);
  }

  {
    LinkedList list;
    ListNode* ret = reverseList(list.getHead());
    std::cout << to_string(ret);
  }

  return 0;
}