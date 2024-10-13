#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
struct Stu
{
    int a, b, c;
};
Stu stus[maxn];
int n, g[maxn], s[maxn], b[maxn];
bool cmp(int x, int y)
{
    return x > y;
}
int find(int f[], int x)
{
    int l = 1, r = n, ans = 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (f[mid] <= x) ans = mid, r = mid-1;
        else l = mid + 1; 
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> stus[i].a >> stus[i].b >> stus[i].c;
        g[i] = stus[i].a; 
        s[i] = stus[i].b;
        b[i] = stus[i].c;
    }
    sort(g + 1, g + n + 1, cmp);
    sort(s + 1, s + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        int gp = find(g, stus[i].a);
        int sp = find(s, stus[i].b);
        int bp = find(b, stus[i].c);
        cout << min(min(gp, sp), bp) << "\n";
    }
    return 0;
}