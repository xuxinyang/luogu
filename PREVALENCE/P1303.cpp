#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+5;
char c1[maxn], c2[maxn];
int a[maxn], b[maxn], c[maxn*2];
int main()
{
    cin >> c1 >> c2;
    int l1 = strlen(c1), l2 = strlen(c2);
    int maxl =  l1 + l2;
    for (int i = 0; i < l1; i++) a[i] = c1[l1-i-1]-'0';
    for (int i = 0; i < l2; i++) b[i] = c2[l2-i-1]-'0';
    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < l2; j++)
        {
            c[i+j] += a[i] * b[j];
        }
    }
    for (int i = 0; i < maxl; i++)
    {
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }
    int p = maxl;
    while (c[p] == 0 && p > 0) p--;
    for (int i = p; i >= 0; i--) cout << c[i];
    return 0;
}