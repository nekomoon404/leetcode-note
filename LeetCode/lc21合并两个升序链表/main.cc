#include "../list_node.h"
#include <iostream>
using namespace std;

// 双指针分别指向两个链表的头部，每次只移动数值小的那个
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode* dummy = new ListNode(INT_MIN);
  ListNode* cur = dummy;
  while (list1 && list2) {
    if (list1->val < list2->val) {
      cur->next = list1;
      list1 = list1->next;
    } else {
      cur->next = list2;
      list2 = list2->next;
    }
    cur = cur->next;
  }
  if (list1) cur->next = list1;
  if (list2) cur->next = list2;
  return dummy->next;
}

int main() {
  {
    LinkedList A({1, 2, 4});
    LinkedList B({1, 3, 4});
    cout << to_string(mergeTwoLists(A.getHead(), B.getHead())) << endl;
  }
}