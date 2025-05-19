#include "../list_node.h"
#include<iostream>

// 链表中结点的数目为 sz
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
ListNode* removeNthFromEnd2(ListNode* head, int n) {
  ListNode* pre = head;
  ListNode* end = pre;
  while (n-- && end) {
    end = end->next;
  }

  // 倒数第n个节点是头节点的情况
  if (end == nullptr) {
    head = pre->next;
    delete pre;
    return head;
  }

  while (end && end->next) {
    pre = pre->next;
    end = end->next;
  }

  if (pre->next) {
    ListNode* tmp = pre->next;
    pre->next = tmp->next;
    delete tmp;
  } else {
    pre->next = nullptr;
  }
  return head;
}

// 虚拟头结点的写法
ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* dummy = new ListNode(-1);
  dummy->next = head;
  ListNode* pre = dummy;
  ListNode* end = dummy;

  while (n-- && end) {
    end = end->next;
  }

  while (end && end->next) {
    pre = pre->next;
    end = end->next;
  }

  if (pre->next) {
    ListNode* tmp = pre->next;
    pre->next = tmp->next;
    delete tmp;
  } else {
    pre->next = nullptr;
  }

  head = dummy->next;
  delete dummy;
  return head;
}

int main() {
  {
    LinkedList list({1, 2, 3, 4, 5});
    ListNode* ret = removeNthFromEnd(list.getHead(), 2);
    std::cout << to_string(ret);
    list.setHead(ret);
  }

  {
    LinkedList list({1, 2, 3, 4, 5});
    ListNode* ret = removeNthFromEnd(list.getHead(), 1);
    std::cout << to_string(ret);
    list.setHead(ret);
  }

  {
    LinkedList list({1, 2, 3, 4, 5});
    ListNode* ret = removeNthFromEnd(list.getHead(), 5);
    std::cout << to_string(ret);
    list.setHead(ret);
  }

  {
    LinkedList list({1});
    ListNode* ret = removeNthFromEnd(list.getHead(), 1);
    std::cout << to_string(ret);
    list.setHead(ret);
  }

  return 0;
}