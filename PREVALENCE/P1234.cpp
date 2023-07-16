#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int n, m, ans;
char a[maxn][maxn];
int main()
{
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j <= m-3)
			{
				if (a[i][j]=='h' && a[i][j+1]=='e' && a[i][j+2]=='h' && a[i][j+3]=='e') ans++;
				if (a[i][j]=='e' && a[i][j+1]=='h' && a[i][j+2]=='e' && a[i][j+3]=='h') ans++;
			}
			if (i <= n-3)
			{
				if (a[i][j]=='h' && a[i+1][j]=='e' && a[i+2][j]=='h' && a[i+3][j]=='e') ans++;
				if (a[i][j]=='e' && a[i+1][j]=='h' && a[i+2][j]=='e' && a[i+3][j]=='h') ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
