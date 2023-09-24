#include <bits/stdc++.h>
using namespace std;
const int maxf = 1e5+5;
int n, a[105], s, ans;
bool f[maxf];
int main()
{
    cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	f[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = s; j >= a[i]; j--)
		{
			if (f[j - a[i]] && f[j] != 1) f[j] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= s - a[i]; j++)
		{
			if (f[j + a[i]] && f[j] != 1) f[j] = 1;
		}
	}
	for (int i = 1; i <= s; i++)
		if (f[i]) ans++;
	cout << ans;
    return 0;
}
