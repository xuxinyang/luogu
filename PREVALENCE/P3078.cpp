#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, a[maxn];
long long ans;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] - a[i-1] > 0) ans += a[i]-a[i-1];  // 当前牌比前面的多的话就可以顺便捎带着打了
	}
	cout << ans;
	return 0;
}