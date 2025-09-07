#include "../list_node.h"
#include <iostream>
using namespace std;

// 归并排序（递归）：找到链表的中间节点，断开成两条链，分别进行排序
// 再将排序好的两条链表合并
ListNode* middleNode(ListNode* head) {
  ListNode* pre = head;
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast && fast->next) {
    pre = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  pre->next = nullptr;  // 将原链表从中间节点断开
  return slow;
}

ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
  ListNode* dummy = new ListNode(-1);
  ListNode* cur = dummy;
  while (list1 && list2) {
    if (list1->val <= list2->val) {
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

ListNode* sortList(ListNode* head) {
  // 递归终止条件：只剩一个节点或者是空节点
  if (!head || !head->next) {
    return head;
  }
  ListNode* head2 = middleNode(head);
  // 分治
  head = sortList(head);
  head2 = sortList(head2);
  // 合并
  return mergeTwoList(head, head2);
}

int main() {
  {
    LinkedList list({4, 2, 1, 3});
    cout << to_string(sortList(list.getHead())) << endl;
  }
  {
    LinkedList list({-1, 5, 3, 4, 0});
    cout << to_string(sortList(list.getHead())) << endl;
  }
  {
    LinkedList list(vector<int>{});
    cout << to_string(sortList(list.getHead())) << endl;
  }
}