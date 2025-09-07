#include "../list_node.h"
#include <iostream>
using namespace std;

// 先找到快慢指针的相遇点，然后一个指针从头出发，一个指针从相遇点出发
// 两个指针相遇的地方就是环的入口
ListNode *detectCycle(ListNode *head) {
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      slow = head;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
  }
  return nullptr;
}

int main() {
  {
    LinkedList list({3, 2, 0, -4});
    list.getTail() ->next = list.getNode(1);
    ListNode* node = detectCycle(list.getHead());
    cout << (node ? node->val : -1) << endl;
  }
  {
    LinkedList list({1, 2});
    list.getTail() ->next = list.getNode(0);
    ListNode* node = detectCycle(list.getHead());
    cout << (node ? node->val : -1) << endl;
  }
  {
    LinkedList list({1});
    ListNode* node = detectCycle(list.getHead());
    cout << (node ? node->val : -1) << endl;
  }
}