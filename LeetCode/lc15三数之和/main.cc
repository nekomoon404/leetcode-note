#include "../vector_print.h"

#include <iostream>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> results;
    if (nums.empty()) {
        return results;
    }
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        } // 避免结果中不能有重复的三元组

        int target = 0 - nums[i];
        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k) {
            int sum = nums[j] + nums[k];
            if (sum == target) {
                results.push_back({nums[i], nums[j], nums[k]});
                do {
                    j++;
                } while (j < k && nums[j] == nums[j - 1]);
                do {
                    k--;
                } while (j < k && nums[k] == nums[k + 1]);
                // 避免结果中不能有重复的三元组
            } else if (sum > target) {
                k--;
            } else if (sum < target) {
                j++;
            }
        }
    }

    return results;
}

int main() {
    {
        std::vector<int> nums{2, -3, 0, -2, -5, -5, -4, 1, 2, -2, 2, 0, 2, -4, 5, 5, -10};
        auto res = threeSum(nums);
        std::cout << to_string(res) << std::endl;
    }

    {
        std::vector<int> nums{-1, 0, 1, 2, -1, -4};
        auto res = threeSum(nums);
        std::cout << to_string(res) << std::endl;
    }

    {
        std::vector<int> nums{0, 0, 0};
        auto res = threeSum(nums);
        std::cout << to_string(res) << std::endl;
    }

    {
        std::vector<int> nums{0, 1, -1};
        auto res = threeSum(nums);
        std::cout << to_string(res) << std::endl;
    }

    {
        std::vector<int> nums{0, 0, -1};
        auto res = threeSum(nums);
        std::cout << to_string(res) << std::endl;
    }

    {
        std::vector<int> nums{-1};
        auto res = threeSum(nums);
        std::cout << to_string(res) << std::endl;
    }

    {
        std::vector<int> nums{-1, 1};
        auto res = threeSum(nums);
        std::cout << to_string(res) << std::endl;
    }

    return 0;
}