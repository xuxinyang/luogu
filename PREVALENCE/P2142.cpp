#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+100;
char c1[maxn], c2[maxn];
int a[maxn], b[maxn], c[maxn], l1, l2, maxl;
void sub(char s1[], char s2[])
{
    // 1.逆序转整数
    for (int i = 0; i < l1; i++) a[i] = s1[l1-i-1]-'0';
    for (int i = 0; i < l2; i++) b[i] = s2[l2-i-1]-'0';
    // 2.模拟减法
    for (int i = 0; i < maxl; i++)
    {   // 考虑借位
        if (a[i] - b[i] < 0)
        {
            a[i+1] -= 1;
            a[i] += 10;
        }
        c[i] = a[i] - b[i];
    }
    // 3.去除前导0
    int p = maxl;
    while (c[p] == 0 && p > 0) p--;
    for (int i = p; i >= 0; i--) cout << c[i]; 
}
int main()
{
    cin >> c1 >> c2;
    l1 = strlen(c1), l2 = strlen(c2);
    maxl = max(l1, l2);
    if (l1 < l2 || (l1 == l2 && strcmp(c1, c2)==-1))
    {
        cout << "-";
        swap(l1, l2);
        sub(c2, c1);
    }
    else sub(c1, c2);
    return 0;
}