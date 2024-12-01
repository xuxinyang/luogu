#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int idx, col;
};
int t;
void solve()
{
    int n, m, q, opt, x, c, p = 0;
    int lopt = -1, lx = -1;
    cin >> n >> m >> q;
    vector<Node> row(n+1), col(m+1);
    while (q--)
    {
        cin >> opt >> x >> c;
        if (opt == 0) row[x] = {++p, c};
        else col[x] = {++p, c};
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (row[i].idx > col[j].idx) cout << row[i].col << " ";
            else cout << col[j].col << " ";
        }
        cout << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}