#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)
#define mid ((l+r)>>1)
const int maxn = 1e5+5;
int n, tot, s[maxn<<1], ed[maxn<<1];
// s[x]:左端点在[x-lowbit(x)+1, x]内的区间数
void change(int x, int k)
{
    while (x <= maxn) s[x] += k, x += lowbit(x);
}
int query(int x)
{
    int t = 0;
    while (x) t += s[x], x -= lowbit(x);
    return t;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        if (c == 'A')
        {
            int L, R, cnt = 0;
            cin >> L >> R;
            while (1)
            {
                int l = -1, r = R + 1;
                while (l + 1 < r)
                    query(mid)>=query(R)?r=mid:l=mid;
                if (ed[r] >= L) change(r, -1), cnt++, tot--;
                else break;
            }
            cout << cnt << "\n";
            change(L, 1);
            ed[L] = R;
            tot++;
        }
        else cout << tot << "\n";
    }
    return 0;
}