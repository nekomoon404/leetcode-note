#include "../vector_print.h"
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

// 先将原字符串排序，异位词排序后的结果是一样的
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string, vector<string>> map;
  for (const string& str : strs) {
    string temp = str;
    sort(temp.begin(), temp.end());
    auto iter = map.find(temp);
    if (iter == map.end()) {
      map.emplace(temp, vector<string>{str});
    } else {
      iter->second.emplace_back(str);
    }
  }
  vector<vector<string>> ans;
  for (const auto& iter : map) {
    ans.emplace_back(std::move(iter.second));
  }
  return ans;
}

int main() {
  {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ans = groupAnagrams(strs);
    for (auto vec : ans) {
      cout << "[" << to_string(vec) << "], ";
    }
  }
}