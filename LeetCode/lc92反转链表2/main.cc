#include "../list_node.h"
#include <iostream>
using namespace std;

// 反转结束后，从原来的链表上看：pre指向反转这一段的末尾；
// cur指向反转这一段后续的下一个节点
// 1->2->3->4->5 反转后：1(->2) 4->3->2 5, pre指向4，cur指向5，
// 记p0是left的前一个节点，则让p0->next->next = cur, po->next = pre, 就变成1->4->3->2->5
ListNode* reverseBetween(ListNode* head, int left, int right) {
  ListNode* dummy = new ListNode(-1);
  dummy->next = head;
  ListNode* p = dummy;
  int step = left - 1;
  while (step--) {
    p = p->next;
  }
  ListNode* pre = p;
  ListNode* cur = p->next;
  ListNode* nxt = nullptr;
  step = right - left + 1;
  while (step--) {
    nxt = cur->next;
    cur->next = pre;
    pre = cur;
    cur = nxt;
  }
  p->next->next = cur;
  p->next = pre;
  return dummy->next;
}

int main() {
  {
    LinkedList list({1, 2, 3, 4, 5});
    cout << to_string(reverseBetween(list.getHead(), 2, 4)) << endl;
  }
}