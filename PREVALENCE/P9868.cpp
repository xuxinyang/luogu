#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 5;
const int maxm = 3e3 + 5;
int n, m;
char s[maxn][maxm];
string low[maxn], high[maxn];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    if (m == 1)
        for (int i = 1; i <= n; i++) low[i] = high[i] = s[i];
    else
    {
        for (int i = 1; i <= n; i++)
        {
            // 找最小
            int idx = 0;
            char c = 'z' + 1;
            for (int j = 0; j < m; j++)
                if (c > s[i][j]) c = s[i][j], idx = j;
            if (idx == 0)
            {
                c = 'z' + 1, idx = 1;
                for (int j = 1; j < m; j++)
                    if (c > s[i][j]) c = s[i][j], idx = j;
                swap(s[i][1], s[i][idx]);
            }
            else swap(s[i][0], s[i][idx]);
            low[i] += s[i][0], low[i] += s[i][1];
            // 找最大
            idx = 0, c = 'a' - 1;
            for (int j = 0; j < m; j++)
                if (c < s[i][j]) c = s[i][j], idx = j;
            if (idx == 0)
            {
                c = 'a' - 1, idx = 1;
                for (int j = 1; j < m; j++)
                    if (c < s[i][j]) c = s[i][j], idx = j;
                swap(s[i][1], s[i][idx]);
            }
            else swap(s[i][0], s[i][idx]);
            high[i] += s[i][0], high[i] += s[i][1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        bool flag = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i != j && low[i] >= high[j])
            {
                flag = 1; break;
            }
        }
        if (flag) cout << 0;
        else cout << 1;
    }
    return 0;
}