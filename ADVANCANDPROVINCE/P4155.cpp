#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n, m, ans[maxn];
struct Sold
{
    int idx, l, r;
};
Sold soldiers[maxn<<1];
int st[maxn<<1][20];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> soldiers[i].l >> soldiers[i].r;
        if (soldiers[i].l > soldiers[i].r)
            soldiers[i].r += m;
        soldiers[i].idx = i;
    }
    sort(soldiers + 1, soldiers + n + 1, [](Sold x, Sold y){
        return x.l < y.l;
    });
    for (int i = 1; i <= n; i++)
    {
        soldiers[i+n] = soldiers[i];
        soldiers[i+n].l = soldiers[i].l + m;
        soldiers[i+n].r = soldiers[i].r + m;
    }
    int k = 1;
    for (int i = 1; i <= (n<<1); i++)
    {
        while (k <= (n<<1) && soldiers[k].l <= soldiers[i].r) k++;
        st[i][0] = k-1;
    }
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= (n<<1); j++)
        {
            st[j][i] = st[st[j][i-1]][i-1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int k = i;
        int s = soldiers[k].l + m, sum = 1, p = k;
        for (int j = 19; j >= 0; j--)
        {
            if (st[k][j] != 0 && soldiers[st[k][j]].r < s)
            {
                sum += (1 << j);
                k = st[k][j];
            }
        }
        ans[soldiers[p].idx] = sum + 1;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}