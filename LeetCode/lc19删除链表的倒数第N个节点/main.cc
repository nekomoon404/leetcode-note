#include "../list_node.h"
#include<iostream>

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* pre = head;
  ListNode* end = pre;
  while (n--) {
    end = end->next;
  }

  if (end == nullptr) {
    head = head->next;
    return head;
  }

  while (end && end->next) {
    pre = pre->next;
    end = end->next;
  }

  if (pre->next) {
    pre->next = pre->next->next;
  } else {
    pre->next = nullptr;
  }
  return head;
}

int main() {
  {
    LinkedList list({1, 2, 3, 4, 5});
    ListNode* ret = removeNthFromEnd(list.getHead(), 2);
    std::cout << to_string(ret);
  }

  {
    LinkedList list({1, 2, 3, 4, 5});
    ListNode* ret = removeNthFromEnd(list.getHead(), 1);
    std::cout << to_string(ret);
  }

  {
    LinkedList list({1, 2, 3, 4, 5});
    ListNode* ret = removeNthFromEnd(list.getHead(), 5);
    std::cout << to_string(ret);
  }

  {
    LinkedList list({1});
    ListNode* ret = removeNthFromEnd(list.getHead(), 1);
    std::cout << to_string(ret);
  }

  return 0;
}