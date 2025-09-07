#include "../list_node.h"
#include <iostream>
using namespace std;

// 快慢指针，若有环则一定相遇
bool hasCycle(ListNode *head) {
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true;
  }
  return false;
}

int main() {
  {
    LinkedList list({3, 2, 0, -4});
    list.getTail() ->next = list.getNode(1);
    cout << hasCycle(list.getHead()) << endl;
  }
  {
    LinkedList list({1, 2});
    list.getTail() ->next = list.getNode(0);
    cout << hasCycle(list.getHead()) << endl;
  }
  {
    LinkedList list({1});
    cout << hasCycle(list.getHead()) << endl;
  }
}