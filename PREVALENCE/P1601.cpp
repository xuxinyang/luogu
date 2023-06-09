#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2+5;
char s1[maxn], s2[maxn];
int a1[maxn], a2[maxn], b[maxn];
int main()
{
    cin >> s1 >> s2;
    // 1. 倒叙存数转整数
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    for (int i = 0; i < l1; i++) a1[i] = s1[l1-i-1] - '0';
    for (int i = 0; i < l2; i++) a2[i] = s2[l2-i-1] - '0';
    // 2. 模拟加法运算
    for (int i = 0; i < max(l1, l2); i++)
    {
        b[i] = a1[i] + a2[i] + b[i];
        b[i+1] = b[i] / 10;
        b[i] = b[i] % 10;
    }
    // 3. 去除前导0
    int p = max(l1, l2);
    while (b[p] == 0 && p > 0) p--;
    for (int i = p; i >= 0; i--) cout << b[i];
    return 0;
}