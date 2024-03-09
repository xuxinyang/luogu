#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
string s[maxn], t[maxn], s1;
long long n, m, cnt;
int main()
{
    ios::sync_with_stdio(false);    // 关闭输入输出同步
    cin.tie(0);
    while (getline(cin, s1) && s1 != "EOF") // 读取计算机的内容
    {
        n++;    // 计数
        for (char c : s1)
            if (c == '<')   // 遍历，出现退格
            { 
                if (!s[n].empty()) s[n].pop_back(); // 非空的话弹出当前元素
            }
            else s[n].push_back(c); // 正常存储
    }
    while (getline(cin, s1) && s1 != "EOF")
    {
        if (++m > n) break; // 多输入的跳过
        for (char c: s1)
            if (c == '<')
            {
                if (!t[m].empty()) t[m].pop_back();
            }
            else t[m].push_back(c);
        for (int i = 0; i < (int)min(t[m].size(), s[m].size()); i++) 
            cnt += (s[m][i] == t[m][i]);   // 如果相等，证明有效
        
    }
    cin >> m;
    cout << (long long)(cnt * 60.0/m + 0.5);    // 算出速度
    return 0;
}