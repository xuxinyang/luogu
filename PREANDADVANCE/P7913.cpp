#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = 1e5+5;
int n, m1, m2, ans, res1[maxn], res2[maxn];
struct Airport
{
    int s, t;
};
typedef pair<int, int> pii;
Airport gn[maxm], gw[maxm];
bool cmp(Airport A, Airport B)
{
    return A.s < B.s;
}
void calc(Airport a[], int m, int res[])
{
    priority_queue<pii, vector<pii>, greater<pii>> away;
    priority_queue<int, vector<int>, greater<int>> free;
    for (int i = 1; i <= n; i++) free.push(i);
    for (int i = 1; i <= m; i++)
    {
        while (!away.empty() && a[i].s >= away.top().first)
            free.push(away.top().second), away.pop();   // 将空闲的港口编号存入堆中
        if (free.empty()) continue;  // 没有空的廊桥，跳过即可
        int dest = free.top();  // 获取空的廊桥编号
        free.pop();
        res[dest]++;    // 当前廊桥存储的飞机数量+1
        away.push(make_pair(a[i].t, dest)); // 存入离港堆中
    }
    for (int i = 1; i <= n; i++) res[i] += res[i-1];    // 前缀和求出使用i个廊桥时最大停靠量
}
int main()
{
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= m1; i++) cin >> gn[i].s >> gn[i].t;
    for (int i = 1; i <= m2; i++) cin >> gw[i].s >> gw[i].t;
    sort(gn+1, gn+m1+1, cmp);
    sort(gw+1, gw+m2+1, cmp); 
    calc(gn, m1, res1);
    calc(gw, m2, res2);
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, res1[i]+res2[n-i]);
    }
    cout << ans;
    return 0;
}