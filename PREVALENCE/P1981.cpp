#include <bits/stdc++.h>
using namespace std;
#define mod 10000
stack<int> st;
long long num, res;
char c;
int main()
{
    cin >> num;
    num %= mod;
    st.push(num);
    // 成对输入运算符和数字
    while (cin >> c >> num)
    {
        // 先计算乘法
        if (c == '*')
        {
            int top = st.top();
            st.pop();
            st.push(num * top % mod);
        }
        else
        {
            st.push(num % mod);
        }
    }
    // 处理加法
    while (!st.empty())
    {
        res += st.top();
        res %= mod;
        st.pop(); 
    }
    cout << res << "\n";
    return 0;
}