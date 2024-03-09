#include <bits/stdc++.h>
using namespace std;
int n, m, f[10000005];
int main()
{
    
    cin >> m;
    f[1] = f[2] = 1;
    f[1] = f[1] % m;
    f[2] = f[2] % m;
    if (f[1] == 0 && f[2] == 1) // 特判
    {
        cout << 1 << endl;
        return 0;
    }
    else
    {
        for (int i = 3; ; i++)
        {
            f[i] = (f[i-1] + f[i-2]) % m;   // 模拟
            if (f[i-1] == 0 && f[i] == 1)   // 出现循环
            {
                cout << i-1 << endl;    // 输出位置
                return 0; 
            }
        }
    }
    return 0;
}