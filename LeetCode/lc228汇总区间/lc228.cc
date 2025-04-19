#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void push_interal(vector<string>& res, int l, int r) {
    if (l == r) {
        res.emplace_back(to_string(l));
        return;
    }
    res.emplace_back(to_string(l) + "->" + to_string(r));  
}

vector<string> summaryRanges(const vector<int>& nums) {
    size_t size = nums.size();
    size_t st = 0, end = 0;
    vector<string> res;
    while (st < size && end < size) {
        if (end + 1 < size && nums[end] + 1 == nums[end + 1]) {
            end++;
            continue;
        }
        push_interal(res, nums[st], nums[end]);
        end++;
        st = end;
    }
    return res;     
}

void print_res(const vector<string>& res) {
    for (const auto& str : res) {
        cout << str << ", ";
    }
    cout << endl;
}
int main() {
    vector<string> res;
    res = summaryRanges({0,2,3,4,6,8,9});
    print_res(res);

    res = summaryRanges({0,1,2,4,5,7});
    print_res(res);

    res = summaryRanges({-1,0,2});
    print_res(res);

    res = summaryRanges({0});
    print_res(res);

    res = summaryRanges({});
    print_res(res);

    // uint32_t a = 2;
    // uint32_t b = 3;
    // cout << a - b << endl;
    // cout << (1ul<<32) - b + a << endl;
    return 0;
}