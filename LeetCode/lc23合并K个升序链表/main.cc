#include "../list_node.h"
#include <iostream>
using namespace std;

// 分而治之：将前一半链表合并，将后一半链表合并，再将两个单链表合并
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

// 合并从lists[i]到list[j]的链表
ListNode* mergeKLists(vector<ListNode*>& lists, int i, int j) {
  if (j < i) {
    return nullptr;
  }
  if (j == i) {
    return lists[i];
  }
  ListNode* left = mergeKLists(lists, i, (i + j) / 2);
  ListNode* right = mergeKLists(lists, (i + j) / 2 + 1, j);

  return mergeTwoList(left, right);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
  return mergeKLists(lists, 0, lists.size() - 1);
}
// 时间复杂度：O(L * logm)，m为lists的长度，L为所有节点总个数
// 空间复杂度：O(logm)，递归需要的额外栈空间

int main() {
  {
    LinkedList l1({1, 4, 5});
    LinkedList l2({1, 3, 4});
    LinkedList l3({2, 6});
    vector<ListNode*> lists{l1.getHead(), l2.getHead(), l3.getHead()};
    cout << to_string(mergeKLists(lists)) << endl;
  }
  {
    vector<ListNode*> lists{};
    cout << to_string(mergeKLists(lists)) << endl;
  }
  {
    LinkedList l1(vector<int>{});
    vector<ListNode*> lists{l1.getHead()};
    cout << to_string(mergeKLists(lists)) << endl;
  }
}