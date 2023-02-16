#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m, ans, s, st[maxn], topo[maxn][maxn], de[maxn], tt[maxn], top;
bool is[maxn], bo[maxn];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        memset(is, 0, sizeof(is));
        cin >> s;
        for (int j = 1; j <= s; j++)
        {
            cin >> st[j];
            is[st[j]] = 1;
        }
        for (int j = st[1]; j <= st[s]; j++)
        {
            if (!is[j]) 
                for (int k = 1; k <= s; k++)
                    if (!topo[j][st[k]])
                        topo[j][st[k]] = 1, de[st[k]]++;
        }
    }
    do {
        top = 0;
        for (int i = 1; i <= n; i++)
        {
            if (de[i] == 0 && !bo[i])
            {
                tt[++top] = i, bo[i] = 1;
            }
        }
        for (int i = 1; i <= top; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (topo[tt[i]][j]) topo[tt[i]][j] = 0, de[j]--;
            }
        } 
        ans++;
    } while (top);
    cout << ans - 1 << endl;
    return 0;
}