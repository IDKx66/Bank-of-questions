#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 字符串相乘
// https://leetcode.cn/problems/multiply-strings/

class Solution {
public:
    
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.size(), n = num2.size();
        vector<int> ret(m + n, 0);

        for(int i = m - 1; i >= 0 ; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                int n1 = num1[i] - '0';
                int n2 = num2[j] - '0';
                int mul = n1 * n2;
                int sum = mul + ret[i + j + 1];

                ret[i + j + 1] = sum % 10;
                ret[i + j] += sum / 10;
            }   
        }

        string result;
        for (size_t i = 0; i < ret.size(); i++)
        {
            // 跳过前导0
            if (result.empty() && ret[i] == 0)
                continue;

            result += ret[i] + '0';
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string num1 = "4566516514648516965167894516";
    string num2 = "7156516354761684446464834348648443";
    cout << sol.multiply(num1, num2) << endl; // Output: "326997769246507769263983208205246597628"
    return 0;
}