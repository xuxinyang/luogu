#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, a[105];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		if (x == 1) a[x+1] += a[x] - y;
		else if (x == n) a[x-1] += y-1;
		else
		{
			a[x-1] += y-1;
			a[x+1] += a[x] - y;
		}
		a[x] = 0;
	}
	for (int i = 1; i <= n; i++) cout << a[i] << "\n";
	return 0;
}
