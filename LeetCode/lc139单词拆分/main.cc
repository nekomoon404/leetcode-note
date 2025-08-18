#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// 记忆化搜索
// 原问题：dfs(i)表示能否s[0, i)这段子串能拆分成若干段，每段都在wordDict中
// 子问题：枚举最后一段的长度为j，如果s[j，i)的子串在字典中，且dfs(j)为真，则dfs(i)为真
// 考虑j的范围：不能超过字典中单词的最大长度
// 边界条件：dfs(0) = true，递归到空串表示s被成功拆分
int max_len;
unordered_set<string> words;
bool dfs(int i, const string& s, vector<int>& memo) {
  if (i == 0) return true;  // 表示成功拆分
  int& res = memo[i];
  if (res != -1) return res;

  for (int j = i - 1; j >= max(i - max_len, 0); j--) {
    // 子串在字典内且dfs(j)为true
    if (words.count(s.substr(j, i - j)) && dfs(j, s, memo)) {
      res = true;
      return res;
    }
  }
  res = false;
  return res;
}
bool wordBreak2(string s, vector<string>& wordDict) {
  max_len = 0;
  words.clear();
  for (const string& word : wordDict) {
    max_len = max(max_len, (int)word.size());
    words.insert(word);
  }
  int n = s.size();
  vector<int> memo(n + 1, -1);
  return dfs(n, s, memo);
}
// 时间复杂度：O(n*L^2 + m*L)，n是状态个数，单个状态计算时间为L^2（遍历j是O(L)，判断子串是否在哈希集合是O(L)); O(m*L)是创建哈希集合的时间
// 空间复杂度：O(n + m*L)，分别是记忆化搜索使用的memo数组的空间，哈希集合的空间


// 将记忆化搜索翻译成递推
bool wordBreak(string s, vector<string>& wordDict) {
  max_len = 0;
  words.clear();
  for (const string& word : wordDict) {
    max_len = max(max_len, (int)word.size());
    words.insert(word);
  }
  int n = s.size();
  vector<bool> f(n + 1, false);
  f[0] = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = i - 1; j >= max(i - max_len, 0); --j) { // 倒序遍历j可以利用单词最大长度来剪枝
      if (f[j] && words.count(s.substr(j, i - j))) {
        f[i] = true;
        break;
      }
    }
  }
  return f[n];
}

int main() {
  {
    string s{"leetcode"};
    vector<string> wordDict{"leet", "code"};
    cout << wordBreak(s, wordDict) << "\n";
  }
  {
    string s{"applepenapple"};
    vector<string> wordDict{"apple", "pen"};
    cout << wordBreak(s, wordDict) << "\n";
  }
  {
    string s{"catsandog"};
    vector<string> wordDict{"cats", "dog", "sand", "and", "cat"};
    cout << wordBreak(s, wordDict) << "\n";
  }
}