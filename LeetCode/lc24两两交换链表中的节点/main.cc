#include "../list_node.h"
#include <iostream>
using namespace std;

// 主要是利用链表的性质
ListNode* swapPairs(ListNode* head) {
  ListNode* dummy = new ListNode(-1);
  dummy->next = head;
  ListNode* pre = dummy;
  ListNode* cur = head;
  ListNode* nxt = dummy;
  ListNode* tmp = dummy;

  while (cur) {
    nxt = cur->next;
    if (!nxt) break;
    tmp = nxt->next;

    pre->next = nxt;
    nxt->next = cur;
    cur->next = tmp;

    pre = cur;
    cur = tmp;
  }

  return dummy->next;
}

int main() {
  {
    LinkedList list({1, 2, 3, 4});
    cout << to_string(swapPairs(list.getHead())) << endl;
  }
}