#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxm = 105;
int n, m, cnt, ans, head[maxn], match[maxn];
bool vis[maxn];
struct Edge
{
	int v, next;
};
Edge edges[maxn*maxm<<1];
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
bool find(int u)
{
	for (int i = head[u]; ~i; i = edges[i].next)
	{
		int v = edges[i].v;
		if (!vis[v])
		{
			vis[v] = 1;
			if (!match[v] || find(match[v]))
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
	cin >> m >> n;
	init();
	while (cin >> u >> v && u != -1)
	{
		add(u, v);
		add(v, u);
	}
	for (int i = 1; i <= m; i++)
	{
		memset(vis, 0, sizeof(vis));
		if (find(i)) ans++;
	}
	cout << ans << "\n";
	for (int i = 1; i <= n; i++)
	{
		if (match[i]) cout << i << " " << match[i] << "\n";
	}
	return 0;
}
