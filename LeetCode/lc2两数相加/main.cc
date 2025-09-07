#include "../list_node.h"
#include <iostream>
using namespace std;

// 模拟两个数的加法运算，注意节点的数量<=100，即表示的数字范围在10^100，因此不能直接计算出l1表示的数
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  int carry = 0;
  ListNode* dummy = new ListNode(-1);
  ListNode* cur = dummy;
  while (l1 && l2) {
    int sum = l1->val + l2->val + carry;
    carry = sum / 10;
    cur->next = new ListNode(sum % 10);
    cur = cur->next;
    l1 = l1->next;
    l2 = l2->next;
  }
  while (l1) {
    int sum = l1->val + carry;
    carry = sum / 10;
    cur->next = new ListNode(sum % 10);
    cur = cur->next;
    l1 = l1->next;
  }
  while (l2) {
    int sum = l2->val + carry;
    carry = sum / 10;
    cur->next = new ListNode(sum % 10);
    cur = cur->next;
    l2 = l2->next;
  }
  if (carry) cur->next = new ListNode(carry);

  return dummy->next;
}

int main() {
  {
    LinkedList A({2, 4, 3});
    LinkedList B({5, 6, 4});
    cout << to_string(addTwoNumbers(A.getHead(), B.getHead())) << endl;
  }
  {
    LinkedList A({0});
    LinkedList B({0});
    cout << to_string(addTwoNumbers(A.getHead(), B.getHead())) << endl;
  }
  {
    LinkedList A({9, 9, 9, 9, 9, 9, 9});
    LinkedList B({9, 9, 9, 9});
    cout << to_string(addTwoNumbers(A.getHead(), B.getHead())) << endl;
  }
}