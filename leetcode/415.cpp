#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 字符串相加
// https://leetcode.cn/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        int next = 0;
        string retstr;

        while (i >= 0 || j >= 0 || next > 0)
        {
            int n1 = (i >= 0) ? num1[i] - '0': 0;
            int n2 = (j >= 0) ? num2[j] - '0': 0;
            int sum = n1 + n2 + next;
            next = sum / 10;
            retstr += (sum % 10) + '0';
            --i;
            --j;
        }
        reverse(retstr.begin(), retstr.end());
        return retstr;
    }
};

int main()
{
    Solution sol;
    string num1 = "4566516514648516965167894516";
    string num2 = "7156516354761684446464834348648443";
    cout << sol.addStrings(num1, num2) << endl; // Output: "7156520921278199094981799516542959"
    return 0;
}

