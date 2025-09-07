/**
 * Definition for singly-linked list.
 */
#include <vector>
#include <sstream>
#include <unordered_set>
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::string to_string(ListNode* head) {
  std::ostringstream oss;
  oss << "[";
  ListNode* curr = head;
  while (curr) {
    oss << curr->val;
    if (curr->next) oss << ", ";
    curr = curr->next;
  }
  oss << "]" << std::endl;
  return oss.str();
}

// RAII封装一个链表类
class LinkedList {
  private:
    ListNode* head;
    std::unordered_set<ListNode*> cache_;
  public:
    LinkedList() : head(nullptr) {}
    
    explicit LinkedList(const std::vector<int>& nums) : head(nullptr) {
      if (nums.empty()) return;

      head = new ListNode(nums[0]);
      ListNode* curr = head;

      for (size_t i = 1; i < nums.size(); ++i) {
        cache_.insert(curr);
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
      }
    }

    // 禁止拷贝构造和拷贝赋值，避免浅拷贝
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    // 支持移动语义
    LinkedList(LinkedList&& other) noexcept : head(other.head) {
      other.head = nullptr;
    }

    LinkedList& operator=(LinkedList&& other) noexcept {
      if (this != &other) {
        freeLinkedList();
        head = other.head;
        other.head = nullptr;
      }
      return *this;
    }

    ~LinkedList() {
      freeLinkedList();
    }

    const ListNode* getHead() const { return head; }
    ListNode* getHead() { return head; }

    ListNode* getTail() {
      ListNode* cur = head;
      while (cur->next) {
        cur = cur->next;
      }
      return cur;
    }

    ListNode* getNode(int pos) {
      ListNode* cur = head;
      while (pos-- && cur) {
        cur = cur->next;
      }
      return cur;
    }

    // for: 一些返回值是头结点的题目, 避免double free, 比如lc19
    void setHead(ListNode* _head) { head = _head; }

    std::string to_string() const {
      std::ostringstream oss;
      oss << "[";
      ListNode* curr = head;
      while (curr) {
        oss << curr->val;
        if (curr->next) oss << ", ";
        curr = curr->next;
      }
      oss << "]" << std::endl;
      return oss.str();
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
      os << list.to_string();
      return os;
    }

  private:
    void freeLinkedList() {
      for (auto it : cache_) {
        ListNode** node = &it;
        delete (*node);
        *node = nullptr;
      }
    }
};