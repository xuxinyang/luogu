#include <iostream>
using namespace std;
const int maxn = 5e5+5;
int n, m, op, a[maxn], c[maxn], s[maxn];
int lowbit(int i)
{
	return (-i) & i;
}
void add(int i, int z)
{
	for (; i <= n; i += lowbit(i))
	{
		c[i] += z;
	}
}
int sum(int i)
{
	int s = 0;
	for (; i > 0; i -= lowbit(i)) s += c[i];
	return s;
}
int calc(int x, int y)
{
	return sum(y) - sum(x-1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		add(i, a[i]);
	}
	int x, y, k;
	while (m--)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> x >> k;
			add(x, k);
		}
		else
		{
			cin >> x >> y;
			cout << calc(x, y) << "\n";
		}
	}
	return 0;
}