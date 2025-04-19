#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> insert(const vector<vector<int>> &intervals, const vector<int> &newInterval) {
    vector<vector<int>> res;
    int st = newInterval[0], end = newInterval[1];
    bool is_placed = false;
    for (const auto& iter : intervals) {
        int l = iter[0], r = iter[1];
        if (end < l) {
            // end比当前区间左端点小，直接插入
            if (!is_placed) {
                res.push_back({st, end});
                is_placed = true;
            }
            res.push_back({l, r});
            continue;
        }
        // st比当前区间右端点大，插入当前区间
        if (st > r){
            res.push_back({l ,r});
            continue;
        }
        // 有重叠
        st = min(st, l);
        end = max(end, r);
    }
    if (!is_placed) {
        res.push_back({st, end});
    }
    return res;
}

void print_res(const vector<vector<int>> &intervals) {
  for (const auto& iter : intervals) {
    cout << "{" << iter[0] << ", " << iter[1] << "}, ";
  }
  cout << endl;
}

int main() {
    // vector<vector<int>> res = insert({{1, 3}, {6, 9}}, {2, 5});
    // print_res(res);

    vector<vector<int>> res = insert({{1,2},{3,5},{6,7},{8,10},{12,16}}, {4, 8});
    print_res(res);
    return 0;
}