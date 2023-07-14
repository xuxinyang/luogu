#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int inf = INT_MAX;
int s, t, k, n, m, cnt, f[maxn], head[maxn], d[maxn];
struct Edge
{
	int to, next, w;
}edges[maxn*maxn];
void add(int u, int v, int w)
{
	edges[cnt] = Edge{v, head[u], w};
	head[u] = cnt++;
}
void init()
{
	memset(head, -1, sizeof(head));
}
bool bfs()
{
	queue<int> q;
	q.push(s);
	memset(d, 0, sizeof(d));
	d[s] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; ~i; i = edges[i].next)
		{
			int v = edges[i].to;
			if (!d[v] && edges[i].w > 0)
			{
				q.push(v);
				d[v] = d[u] + 1;
			}
		}
	}
	return d[t];
}
int dfs(int u, int w)
{
	if (u == t || !w) return w;
	int sum = 0;
	for (int i = head[u]; ~i; i = edges[i].next)
	{
		int v = edges[i].to;
		if (d[v] == d[u]+1 && edges[i].w > 0)
		{
			int fw = dfs(v, min(w, edges[i].w));
			if (fw > 0)
			{
				edges[i].w -= fw;
				edges[i^1].w += fw;
				sum += fw;
				w -= fw;
				if (!w) return sum;
			}
		}
	}
	return sum;
}
int dinic()
{
	int ans = 0;
	while (bfs()) ans += dfs(s, inf);
	return ans;
}
int main()
{
    init();
	cin >> k >> n;
	t = n + k + 1;
	for (int i = 1; i <= k; i++)
	{
		cin >> f[i];
		m += f[i];
		add(i, s, 0);
		add(s, i, f[i]);
	}
	for (int i = 1, p; i <= n; i++)
	{
		cin >> p;
		for (int j = 1, r; j <= p; j++)
		{
			cin >> r;
			add(i+k, r, 0);
			add(r, i+k, 1);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		add(t, i+k, 0);
		add(i+k, t, 1);
	}
	if (dinic() == m)
	{
		for (int i = 1; i <= k; i++)
		{
			cout << i << ": ";
			for (int j = head[i]; ~j; j = edges[j].next)
			{
				if (edges[j].to > 0 && !edges[j].w)
				{
					cout << edges[j].to - k << " ";
				}
			}
			cout << "\n";
		}
	}
	else cout << "No solution!\n";
    return 0;
}
