#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 205;
const int maxm = 2005;
const ll inf = LLONG_MAX;
ll n, m, x, cnt, head[maxn], d[maxn];
bool flag;
struct Edge
{
	ll v, next, cap, flow;
};
Edge edges[maxm << 1];
void init()
{
	memset(head, -1, sizeof(head));
}
void add(int u, int v, int w)
{
	edges[cnt] = Edge{v, head[u], w, 0};
	head[u] = cnt++;
}
// BFS用来分层
bool bfs(int s, int t)
{
	memset(d, 0, sizeof(d));
	queue<int> q;
	d[s] = 1;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (ll i = head[u]; ~i; i = edges[i].next)
		{
			ll v = edges[i].v;
			if (!d[v] && edges[i].cap > edges[i].flow)
			{
				d[v] = d[u] + 1;
				q.push(v);
				if (v == t) return 1;
			}
		}
	}
	return 0;
}
// 在分层基础上进行dfs加快速度
ll dfs(ll u, ll flow, ll t)
{
	if (u == t) return flow;
	ll rest = flow;
	for (int i = head[u]; ~i && rest; i = edges[i].next)
	{
		ll v = edges[i].v;
		if (d[v] == d[u] + 1 && edges[i].cap > edges[i].flow)
		{
			ll k = dfs(v, min(rest, edges[i].cap - edges[i].flow), t);
			if (!k) d[v] = 0;
			edges[i].flow += k;
			edges[i^1].flow -= k;
			rest -= k;
		}
	}
	return flow - rest;
}
ll Dinic(int s, int t)
{
	ll maxFlow = 0;
	while (bfs(s, t))
	{
		flag = 1;
		maxFlow += dfs(s, inf, t);
	}
	return maxFlow;
}
int main()
{
	ll u, v, w;
	cin >> n >> m >> x;
	init();
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, 0);
	}
	ll res = Dinic(1, n);
	if (!flag) cout << "Orz Ni Jinan Saint Cow!";
	else cout << res << " " << (long long)(ceil(1.0*x/res));
	return 0;
}
