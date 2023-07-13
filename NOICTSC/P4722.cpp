#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+205;
const int maxm = 1e5+2e4+5;
const int inf = INT_MAX;
int n, m, s, t;
int cnt, head[maxn], pre[maxn], h[maxn], g[maxn];
struct Edge
{
	int v, next, cap, flow;
}edges[maxm<<1];
void init()
{
	memset(head, -1, sizeof(head));
	cnt = 0;
}
void add(int u, int v, int c)
{
	edges[cnt] = Edge{v, head[u], c, 0};
	head[u] = cnt++;
}
void set_h(int t, int n)
{
	queue<int> q;
	memset(h, -1, sizeof(h));
	memset(g, 0, sizeof(g));
	h[t] = 0;
	q.push(t);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		++g[h[u]];
		for (int i = head[u]; ~i; i = edges[i].next)
		{
			int v = edges[i].v;
			if (h[v] == -1)
			{
				h[v] = h[u] + 1;
				q.push(v);
			}
		}
	}
}
int ISAP(int s, int t, int n)
{
	set_h(t, n);
	int ans = 0, u = s, d;
	while (h[s] < n)
	{
		int i = head[u];
		if (u == s) d = inf;
		for (; ~i; i = edges[i].next)
		{
			int v = edges[i].v;
			if (edges[i].cap > edges[i].flow && h[u] == h[v] + 1)
			{
				u = v;
				pre[v] = i;
				d = min(d, edges[i].cap - edges[i].flow);
				if (u == t)
				{
					while (u != s)
					{
						int j = pre[u];
						edges[j].flow += d;
						edges[j^1].flow -= d;
						u = edges[j^1].v;
					}
					ans += d;
					d = inf;
					d = inf;
				}
				break;
			}
		}
		if (i == -1)
		{
			if (--g[h[u]] == 0) break;
			int hmin = n - 1;
			for (int j = head[u]; ~j; j = edges[j].next)
			{
				if (edges[j].cap > edges[j].flow)
					hmin = min(hmin, h[edges[j].v]);
			}
			h[u] = hmin + 1;
			++g[h[u]];
			if (u != s) u = edges[pre[u]^1].v;
		}
	}
	return ans;
}
int main()
{
	int u, v, c;
	cin >> n >> m >> s >> t;
	init();
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> c;
		add(u, v, c);
		add(v, u, 0);
	}
	cout << ISAP(s, t, n);
	return 0;
}
