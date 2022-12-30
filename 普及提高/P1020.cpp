#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn], f[maxn], g[maxn];
stringstream ss;
string s;
int x, id;
int main()
{
    getline(cin, s);
    ss.clear();
    ss.str(s);
    while (ss >> x) a[++id] = x;
    // 最长不上升子序列就是从后往前看就是最长不下降子序列
    reverse(a + 1, a + id + 1);
    f[1] = a[1];
    int len = 1;
    for (int i = 2; i <= id; i++)
    {
        if (a[i] >= f[len]) f[++len] = a[i];
        else *upper_bound(f+1, f+len+1, a[i]) = a[i];
    }
    cout << len << "\n";
    reverse(a + 1, a + id + 1);
    g[1] = a[1], len = 1;
    for (int i = 2; i <= id; i++)
    {
        if (a[i] == g[len]) continue;
        if (a[i] > g[len]) g[++len] = a[i];
        else *lower_bound(g+1, g+len+1, a[i]) = a[i];
    }
    cout << len << "\n";
    return 0;
}