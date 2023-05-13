#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, fa[N], ans = INT_MAX;
int find(int x, int &cnt)
{
    cnt++;
    if (fa[x] == x) return x;
    else return find(fa[x], cnt);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0, f;
        scanf("%d", &f);
        if (find(f, cnt) == i) ans = min(ans, cnt);
        else fa[i] = f;
    }
    printf("%d", ans);
    return 0;
}