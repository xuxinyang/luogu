#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1e5+5;
int n, m, q, p[maxn];
bool a[maxn], vis[maxn];
vector<int> ve[maxn];
void dfs(int u)
{
	vis[u] = 1;
	a[u] = a[u]^(p[u]&1);
	for (int i = 0; i < (int)ve[u].size(); i++)
	{
		int v = ve[u][i];
		if (!vis[v])
		{
			p[v] += p[u];
			dfs(v);
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		ve[x].push_back(i);
	}
	char c;
	for (int i = 1; i <= n; i++)
	{
		cin >> c;
		a[i] = c - '0'; 
	}
	cin >> q;
	while (q--)
	{
		int x;
		cin >> x;
		p[x]++;
	}
	dfs(1);
	for (int i = 1; i <= n; i++) cout << a[i];
	return 0;
}