#include <bits/stdc++.h>
using namespace std;
int a[6][15], b[6][15], ans, f[10];
int main()
{
	for (int i = 1; i <= 5; i++) f[i] = 1; 
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cin >> a[i][j];
			b[i][j] = a[i][j] - a[i][j-1];
		}
	}
	for (int i = 1; i <= 20; i++)
	{
		int minx = INT_MAX, tmp = 0;
		for (int j = 1; j <= 5; j++)
		{
			if (b[j][f[j]+1] < minx && f[j]+1 <= 10)
			{
				minx = b[j][f[j]+1];
				tmp = j;
			}
		}
		f[tmp]++;
	}
	for (int i = 1; i <= 5; i++)
	{
		ans += a[i][f[i]];
	}
	cout << ans << endl;
	for (int i = 1; i <= 5; i++) cout << f[i] << " ";
	
	return 0;
}
