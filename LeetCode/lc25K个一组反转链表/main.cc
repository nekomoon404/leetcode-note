#include "../list_node.h"
#include <iostream>
using namespace std;

// 首先计算链表的长度，在反转过程中如果剩余长度不足k，则无需反转
// 在反转链表2的基础上，每次反转结束后，需要将p更新为下一组K个节点的前一个节点，也就是p->next
// p->1->2->3->4->5->6  反转一次：p(->1) 3->2->1 4->5->6
ListNode* reverseKGroup(ListNode* head, int k) {
  int length = 0;
  ListNode* cur = head;
  while (cur) {
    length++;
    cur = cur->next;
  }

  ListNode* dummy = new ListNode(-1);
  dummy->next = head;
  ListNode* p = dummy;

  ListNode* pre = p;
  cur = pre->next;
  ListNode* nxt = nullptr;
  while (length >= k) {
    length -= k;
    int step = k;
    while (step--) {
      nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }

    ListNode* tmp = p->next;
    p->next->next = cur;
    p->next = pre;
    p = tmp;
  }
  return dummy->next;
}

int main() {
  {
    LinkedList list({1, 2, 3, 4, 5});
    cout << to_string(reverseKGroup(list.getHead(), 2)) << endl;
  }
  {
    LinkedList list({1, 2, 3, 4, 5});
    cout << to_string(reverseKGroup(list.getHead(), 3)) << endl;
  }
}