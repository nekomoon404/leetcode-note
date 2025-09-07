#include "../list_node.h"
#include <iostream>
using namespace std;

// 空间O(n)的方法：将链表值存放到数组中，再用双指针
bool isPalindrome2(ListNode* head) {
  vector<int> nums;
  while (head) {
    nums.push_back(head->val);
    head = head->next;
  }
  for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
    if (nums[i] != nums[j])
      return false;
  }
  return true;
}

// 空间I(1)的方法：先找到链表中间节点，则翻转后半部分链表
// 如果是奇数个，则返回中间节点；如果是偶数个，则返回中间右边的节点
ListNode* middleNode(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

ListNode* revreseList(ListNode* head) {
  ListNode* pre = nullptr;
  ListNode* cur = head;
  ListNode* next = nullptr;
  while (cur) {
    next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
  }
  return pre;
}

bool isPalindrome(ListNode* head) {
  ListNode* mid = middleNode(head);
  ListNode* head2 = revreseList(mid);
  // 偶数个节点的情况下，head2链表更短
  while (head2) {
    if (head->val != head2->val) return false;
    head = head->next;
    head2 = head2->next;
  }
  return true;
}

int main() {
  {
    LinkedList A({1, 2, 2, 1});
    cout << isPalindrome(A.getHead()) << endl;
  }
  {
    LinkedList A({1, 2});
    cout << isPalindrome(A.getHead()) << endl;
  }
  {
    LinkedList A({1, 2, 1});
    cout << isPalindrome(A.getHead()) << endl;
  }
}