#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int n, l, r, cnt, flag;
bool f[maxn];
string s, alpha = "abcdefghijklmnopqrstuvwxyz";
int main()
{
    cin >> n >> l >> r;
    cin >> s;
    l = n - l, r = n - r;
    for (int i = 0; i < n; i++)
    {
        if (flag == l) break;
        if (s[i] != 'a') 
        {
            s[i] = 'a';
            flag++;
        } 
        else f[i] = 1;
    }
    if (flag < r)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (f[i]) s[i] = 'b', flag++;
            if (flag == r) break;
        }
    }
    cout << s;
    return 0;
}