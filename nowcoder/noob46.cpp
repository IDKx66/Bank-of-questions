#include <iostream>
#include <vector>
using namespace std;

// 约瑟夫环
// https://www.nowcoder.com/practice/e417cfe32c74416ca38247f619ddb322

// 模拟法
int solve_by_simulation(int n, int k, int m)
{
    // 1. 初始化容器
    vector<int> people;
    for (int i = 0; i < n; i++)
    {
        people.push_back(i);
    }

    // 2. 确定初始位置：题目说从编号 k 开始报数
    // 在我们的 vector 中，编号为 k 的人初始下标正好就是 k
    int cur = k;

    while (people.size() > 1)
    {
        // 关键点：(当前位置 + 报数长度 - 1) % 当前人数
        // 为什么要 -1？因为报数是从当前人开始的，走 m 步实际只跨越了 m-1 个间隔
        cur = (cur + m - 1) % people.size();

        // 执行删除，erase 后后面的元素会自动前移
        people.erase(people.begin() + cur);
    }

    return people[0];
}

// 数学法
int solve_by_math(int n, int k, int m)
{
    /* 1. 标准约瑟夫环公式：f(i) = (f(i-1) + m) % i
       这里计算的是：如果从 0 开始报数，最后活下来的人在 0~n-1 中的下标
    */
    int res = 0; // 当只有 1 个人时，幸存者下标必为 0
    for (int i = 2; i <= n; i++)
    {
        // 这里的 +m 是为了在每一轮增加人数时，将坐标还原回上一层
        res = (res + m) % i;
    }

    /* 2. 处理偏移量 k：
       由于题目是从编号 k 开始报数，相当于把整个环顺时针旋转了 k 位
    */
    return (res + k) % n;
}

int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    
    cout << solve_by_simulation(n, k, m) << endl;
    cout << solve_by_math(n, k, m) << endl;

    return 0;
}