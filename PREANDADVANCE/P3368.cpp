#include <iostream>
using namespace std;
const int maxn = 5e5+5;
int n, m, op, a[maxn], c[maxn], s[maxn];
int lowbit(int i)
{
	return i & (-i);
}
void add(int i, int z)
{
	for (; i <= n; i += lowbit(i))
		c[i] += z;
}
int sum(int i)
{
	int s = 0;
	for (; i > 0; i -= lowbit(i))
		s += c[i];
	return s;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, y, k;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		add(i, a[i]-a[i-1]);
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> x >> y >> k;
			add(x, k);
			add(y+1, -k);
		}
		else
		{
			cin >> x;
			cout << sum(x) << "\n";
		}
	}
	return 0;
}