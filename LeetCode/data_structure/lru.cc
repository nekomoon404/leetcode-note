#include <unordered_map>
#include <iostream>
using namespace std;

// 维护一个双向链表，get/put操作将node移动/插入到链表头，这样链表尾就是最近最少使用的元素
// 当超过容量时，优先删除链表尾部
struct Node {
  int key;
  int value;
  Node* prev;
  Node* next;

  explicit Node(int k = 0, int v = 0) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
 private:
  int capacity;
  Node* dummy; // 哨兵节点
  unordered_map<int, Node*> key_to_node;

  // 从链表中删除一个节点
  void remove(Node* x) {
    x->prev->next = x->next;
    x->next->prev = x->prev;
  }

  // 在链表头添加一个节点
  void push_front(Node* x) {
    x->prev = dummy;
    x->next = dummy->next;
    dummy->next->prev = x;
    dummy->next = x;
  }

  // 获取key对应的节点，同时把该节点移动到链表头部
  Node* get_node(int key) {
    auto it = key_to_node.find(key);
    if (it == key_to_node.end()) {
      return nullptr;
    }
    Node* node = it->second;
    remove(node);
    push_front(node);
    return node;
  }
 public:
  explicit LRUCache(int _capacity) : capacity(_capacity) {
    dummy = new Node();
    dummy->next = dummy;
    dummy->prev = dummy;
  }

  ~LRUCache() {
    if (dummy) delete dummy;
    for (auto it : key_to_node) {
      Node* node = it.second;
      if (node) delete node;
    }
  }

  int get(int key) {
    Node* node = get_node(key);
    return node == nullptr ? -1 : node->value;
  }

  void put(int key, int value) {
    Node* node = get_node(key);
    // 如果找到key，则更新节点的value
    if (node != nullptr) {
      node->value = value;
      return;
    }
    // 如果没有找到key，则创建新节点并插入链表头部
    node = new Node(key, value);
    key_to_node[key] = node;
    push_front(node);
    // 如果容量超出，则删除链表尾部的节点
    if (key_to_node.size() > capacity) {
      Node* back_node = dummy->prev;
      key_to_node.erase(back_node->key);
      remove(back_node);
      delete back_node;
    }
  }
};

int main() {
  {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;

    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
  }
}