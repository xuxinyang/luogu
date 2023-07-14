#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int maxm = 5e4+5;
int n, m, cnt, e, ans, head[maxn], match[maxn];
bool vis[maxn];
struct Edge
{
	int to, next;
}edges[maxm<<1];
void init()
{
	memset(head, -1, sizeof(head));
	memset(match, 0, sizeof(match));
}
void add(int u, int v)
{
	edges[cnt] = Edge{v, head[u]};
	head[u] = cnt++;
}
// 匈牙利算法
bool hungary(int u)
{
	for (int i = head[u]; ~i; i = edges[i].next)
	{
		int v = edges[i].to;
		if (!vis[v])
		{
			vis[v] = 1;
			if (!match[v] || hungary(match[v]))
			{
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int u, v;
	cin >> n >> m >> e;
	init();
	for (int i = 1; i <= e; i++)
	{
		cin >> u >> v;
		add(u, v + n);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		if (hungary(i)) ans++;
	}
	cout << ans;
	return 0;
}
