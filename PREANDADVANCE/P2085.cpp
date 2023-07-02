#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
priority_queue<int, vector<int>, less<int>> pq;
int n, m, a, b, c, ans[maxn];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        for (int j = 1; j <= m; j++)
        {
            int y = a * j * j + b * j + c;
            if (i == 1) pq.push(y);
            else
            {
                if (y < pq.top()) pq.push(y), pq.pop();
                else break;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        ans[i] = pq.top();
        pq.pop();
    }
    for (int i = m; i >= 1; i--) cout << ans[i] << " ";
    return 0;
}