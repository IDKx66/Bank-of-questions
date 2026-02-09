#include <iostream>
#include <vector>
using namespace std;

// 只出现一次的数字 II
// https://leetcode.cn/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        // 依次检查每一个二进制位（int 总共有 32 位）
        for (int j = 0; j < 32; j++) {
            int cnt = 0; 
            for (int x : nums) {
                // 使用无符号转换，统计所有数字在第 j 位上 1 出现的次数
                if (((unsigned int)x >> j) & 1) {
                    cnt++;
                }
            }
            // 如果第 j 位 1 出现的次数不能被 3 整除，说明目标数在这一位是 1
            if (cnt % 3 != 0) {
                ans |= (1U << j);
            }
        }
        return ans; // 这里的 return 一定要在 for 循环外面
    }
};

// --- 本地测试用的 main 函数 ---
int main() {
    Solution sol;

    // 测试样例 1
    vector<int> nums1 = {2, 2, 3, 2};
    cout << "测试样例 1 [2, 2, 3, 2] -> 预期输出: 3, 实际输出: " << sol.singleNumber(nums1) << endl;

    // 测试样例 2 (包含负数)
    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};
    cout << "测试样例 2 [0, 1, 0, 1, 0, 1, 99] -> 预期输出: 99, 实际输出: " << sol.singleNumber(nums2) << endl;

    // 测试样例 3 (全负数情况)
    vector<int> nums3 = {-2, -2, -1, -2};
    cout << "测试样例 3 [-2, -2, -1, -2] -> 预期输出: -1, 实际输出: " << sol.singleNumber(nums3) << endl;

    return 0;
}