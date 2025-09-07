#include <iostream>
#include "../list_node.h"
using namespace std;

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  ListNode* nodeA = headA;
  ListNode* nodeB = headB;

  bool A_end = false, B_end = false;
  while (nodeA != nodeB) {
    nodeA = nodeA->next;
    nodeB = nodeB->next;
    if (!nodeA && nodeB) nodeA = headB;
    if (!nodeB && nodeA) nodeB = headA;
    // 加上&&后面的条件，避免A和B链表不想交的情况下无限循环
  }
  return nodeA;
}

int main() {
  {
    LinkedList A({4, 1});
    LinkedList B({5, 6, 1});
    LinkedList C({8, 4, 5});
    A.getTail()->next = C.getHead();
    B.getTail()->next = C.getHead();
    getIntersectionNode(A.getHead(), B.getHead());
  }
}