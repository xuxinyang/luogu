#include <bits/stdc++.h>
using namespace std;
int n, x, a[10], ans;
bool check(int x)
{
	while (x)
	{
		if (a[x%10] == 0) return false;
		x /= 10;
	}
	return true;
}
int main()
{
    cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		a[x] = 1;
	}
	for (int i = 111; i <= 999; i++)
	{
		for (int j = 11; j <= 99; j++)
		{
			int p = j / 10 * i;
			int q = j % 10 * i;
			int z = i * j;
			if (p >= 1000 || p < 100) continue;
			if (q >= 1000 || q < 100) continue;
			if (z >= 10000 || z < 1000) continue;
			if (check(i) && check(j) && check(p) && check(q) && check(z))
			{
				ans++;
			}
		}
	}
	cout << ans;
    return 0;
}
