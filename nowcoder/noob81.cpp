#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 逗号整合器
// https://www.nowcoder.com/practice/ff77cca50f5d4793a14a94f141de0af3

// to_string

class Solution {
public:
    /**
     * 将整数数组转换为逗号分隔的字符串
     * @param a 整数数组
     * @return 返回转换后的逗号分隔字符串
     */
    string commaTransformer(vector<int>& a) {
        if (a.empty()) return "";
        
        string s = "";
        for (size_t i = 0; i < a.size(); i++) {
            // s += a[i] + '0';
            // 之前的错误：a[i] + '0' 只能处理单个数字，不能处理多位数或负数

            // 修正之前的错误：使用 to_string 处理多位数和负数
            s += to_string(a[i]);
            
            if (i != a.size() - 1) {
                s += ",";
            }
        }
        return s;
    }
};

// 本地测试用的 main 函数
int main() {
    Solution sol;
    
    // 测试用例 1: [1, 3, 5]
    vector<int> test1 = {1, 3, 5};
    cout << "Test 1: " << sol.commaTransformer(test1) << endl; 
    
    // 测试用例 2: [-71] (对应你截图中报错的情况)
    vector<int> test2 = {-71};
    cout << "Test 2: " << sol.commaTransformer(test2) << endl;
    
    return 0;
}