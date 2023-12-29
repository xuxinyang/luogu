#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
int dig[15], pos;
ll dp[15][10][15], ans[2][10];
ll dfs(int pos, int val, int cnt, bool lead, bool limit)
{
	if (pos == 0) return cnt;
	if (!limit && !lead && dp[pos][val][cnt] != -1) return dp[pos][val][cnt];
	int len = limit ? dig[pos]:9, t = 0;
	ll ans = 0;
	for (int i = 0; i <= len; i++)
	{
		if (val != i) t = cnt;
		else
		{
			if (lead && val == 0) t = 0;
			else t = cnt+1;
		}
		ans += dfs(pos-1, val, t, lead&&i==0, limit&&i==len);
	}
	if (!limit && !lead) dp[pos][val][cnt] = ans;
	return ans;
}
void solve(ll x, int idx)
{
	if (x == 0) return;
	int pos = 0;
	while (x)
	{
		dig[++pos] = x % 10;
		x /= 10;
	}
	for (int i = 0; i < 10; i++)
		ans[idx][i] = dfs(pos, i, 0, 1, 1);
}
int main()
{
	memset(dp, -1, sizeof(dp));
	ll a, b;
	cin >> a >> b;
	solve(a-1, 0), solve(b, 1);
	for (int i = 0; i < 10; i++)
		cout << ans[1][i] - ans[0][i] << " ";
	return 0;
}