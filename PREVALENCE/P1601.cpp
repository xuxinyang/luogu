#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2+5;
char c1[maxn], c2[maxn];
int a[maxn], b[maxn], c[maxn];
int main()
{
    cin >> c1 >> c2;
    // 1. 倒序并转成整数
    int l1 = strlen(c1);
    int l2 = strlen(c2);
    for (int i = 0; i < l1; i++) a[i] = c1[l1-i-1]-'0';
    for (int i = 0; i < l2; i++) b[i] = c2[l2-i-1]-'0';
    // 2. 模拟加法运算
    for (int i = 0; i < max(l1, l2); i++)
    {
        c[i] = a[i] + b[i] + c[i];
        c[i+1] = c[i] / 10;
        c[i] = c[i] % 10; 
    }
    // 3. 去除前导0，并输出
    int p = max(l1, l2);
    while (c[p] == 0 && p > 0)
    {
        p--;
    }
    while (p>=0) cout << c[p--];
    return 0;
}