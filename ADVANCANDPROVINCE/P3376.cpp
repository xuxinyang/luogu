#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = LLONG_MAX;
const int maxn = 205;
const int maxm = 5e3+5;
ll n, m, cnt, head[maxn], pre[maxn], s, t;
bool vis[maxn];
struct Edge
{
	ll v, next, cap, flow;
};
Edge edges[maxm<<1];
void init()
{
	memset(head, -1, sizeof(head));
	cnt = 0;
}
void add(ll u, ll v, ll c)
{
	edges[cnt] = Edge{v, head[u], c, 0};
	head[u] = cnt++;
}
bool bfs(ll s, ll t)
{
	memset(pre, -1, sizeof(pre));
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	vis[s] = 1;
	q.push(s);
	while (!q.empty())
	{
		ll u = q.front();
		q.pop();
		for (ll i = head[u]; ~i; i = edges[i].next)
		{
			ll v = edges[i].v;
			if (!vis[v] && edges[i].cap > edges[i].flow)
			{
				vis[v] = 1;
				pre[v] = i;
				q.push(v);
				if (v == t) return 1;
			}
		}
	}
	return 0;
}
ll EK(ll s, ll t)
{
	ll maxFlow = 0;
	while (bfs(s, t))
	{
		ll v = t, d = inf;
		while (v != s)
		{
			ll i = pre[v];
			d = min(d, edges[i].cap-edges[i].flow);
			v = edges[i^1].v;
		}
		maxFlow += d;
		v = t;
		while (v != s)
		{
			ll i = pre[v];
			edges[i].flow += d;
			edges[i^1].flow -= d;
			v = edges[i^1].v;
		}
	}
	return maxFlow;
}
int main()
{
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	ll u, v, c;
	cin >> n >> m >> s >> t;
	init();
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> c;
		add(u, v, c);
		add(v, u, 0);
	}
	cout << EK(s, t);
	return 0;
}
