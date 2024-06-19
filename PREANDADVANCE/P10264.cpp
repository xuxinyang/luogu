#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn], b[maxn], pos[maxn];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        cin >> n;
        memset(b, 0, n*4);
        memset(pos, 0, n*4);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            b[pos[a[i]]] = i;
            pos[a[i]] = i;
        }
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int l, r, ans = 0;
            scanf("%d %d", &l, &r);
            if (l > r) swap(l, r);
            for (int i = l; i <= r; i++)
            {
                if (b[i] != 0 && b[i] <= r) i = b[i];
                else ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}