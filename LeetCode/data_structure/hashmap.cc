#include <vector>
#include <list>
#include <iostream>
using namespace std;

// 拉链法，或者叫链地址法
// 优化方法：桶数量自动扩容，扩容之后需要rehash；链表转换为红黑树，将最坏情况下O(n)优化为O(log n)
class MyHashMap {
 private:
  vector<list<pair<int, int>>> data;
  static const int base = 769; // 质数
  static int hash(int key) {
    return key % base;
  }
 public:
  MyHashMap() : data(base) {}

  void put(int key, int value) {
    int h = hash(key);
    for (auto iter = data[h].begin(); iter != data[h].end(); ++iter) {
      if ((*iter).first == key) {
        (*iter).second = value;
        return;
      }
    }
    data[h].push_back({key, value});
  }

  int get(int key) {
    int h = hash(key);
    for (auto iter = data[h].begin(); iter != data[h].end(); ++iter) {
      if ((*iter).first == key) {
        return (*iter).second;
      }
    }
    return -1;
  }

  void remove(int key) {
    int h = hash(key);
    for (auto iter = data[h].begin(); iter != data[h].end(); ++iter) {
      if ((*iter).first == key) {
        data[h].erase(iter);
        return;
      }
    }
  }
};

int main() {
  {
    MyHashMap map;
    map.put(1, 1);
    map.put(2, 2);
    cout << map.get(1) << endl;
    cout << map.get(3) << endl;
    map.put(2, 1);
    cout << map.get(2) << endl;
    map.remove(2);
    cout << map.get(2) << endl;
  }
}