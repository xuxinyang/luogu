#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
ll n, dis[maxn], sum;
bool vis[maxn];
vector<pair<ll, ll>> ve[maxn];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
void dijkstra(int u)
{
	pq.push({0ll, u});
	dis[u] = 0;
	while (!pq.empty())
	{
		ll u = pq.top().second, w = pq.top().first;
		pq.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto cur : ve[u])
		{
			ll v = cur.second, d = cur.first;
//			cout << v << " " << d << " " << dis[v] << "\n";
			if (dis[v] > w + d)
			{
				dis[v] = w + d;
				pq.push({dis[v], v});
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		ve[u].push_back({w, v});
		ve[v].push_back({w, u});
		sum += w;
	}
	memset(dis, 0x3f, sizeof dis);
	dijkstra(1);
//	for (int i = 1; i <= n; i++) cout << dis[i] << " ";
	ll maxx = *max_element(dis+1, dis+n+1);
	cout << 2*sum - maxx;
	return 0;
}