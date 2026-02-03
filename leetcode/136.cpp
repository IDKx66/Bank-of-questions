#include <iostream>
#include <vector>

using namespace std;

// 只出现一次的数字
// https://leetcode.cn/problems/single-number/

class Solution {
public:
    /**
     * @brief 找出数组中只出现一次的数字
     * 时间复杂度: O(n) - 遍历一次数组
     * 空间复杂度: O(1) - 只使用了常量级别的额外空间
     */
    int singleNumber(vector<int>& nums) {
        int val = 0;
        for (int e : nums) {
            val ^= e; // 核心逻辑：异或运算
        }
        return val;
    }
};

int main() {
    Solution solution;

    // 测试用例 1
    vector<int> nums1 = {2, 2, 1};
    cout << "测试用例 1 [2, 2, 1] 输出: " << solution.singleNumber(nums1) << " (预期: 1)" << endl;

    // 测试用例 2
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "测试用例 2 [4, 1, 2, 1, 2] 输出: " << solution.singleNumber(nums2) << " (预期: 4)" << endl;

    // 测试用例 3
    vector<int> nums3 = {1};
    cout << "测试用例 3 [1] 输出: " << solution.singleNumber(nums3) << " (预期: 1)" << endl;

    return 0;
}