/**
 * 十进制转十六进制
 */
#include <cmath>
#include <iostream>
using namespace std;
// 任意进制转十进制
int x2ten(string s, int x)
{
    int sum = 0, p = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        int k = 0; // 初始化
        if (s[i] >= 'A')
            k = s[i] - 'A' + 10; // 如果当前这一位的值是大写字母，就转成实际代表的整数
        else
            k = s[i] - '0';   // 否则转成对应数字
        sum += k * pow(x, p); // 计算当前这一位实际代表的值累计到sum里面
        p++;
    }
    return sum;
}
int main()
{
    int x;
    string s;
    cin >> x >> s;
    cout << x2ten(s, x);
    return 0;
}
