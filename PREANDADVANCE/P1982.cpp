#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
using namespace std;
#define ll __int128
const int maxn = 1e6+5;
ll n, a[maxn], p, ans, dp[maxn], score[maxn], q, res, s[maxn];
inline ll max(ll x, ll y)
{
	return x > y ? x : y;
}
inline void read(ll &n)
{
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x<<1) + (x<<3) + (ch^48);
		ch = getchar();
	}
	n = x * f;
}
inline void print(ll n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n)
	{
		print(n/10);
		putchar(n % 10 + '0');
	}
}
int main()
{
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	read(n), read(p);
	for (int i = 1; i <= n; i++) read(a[i]);
	// 处理特征值
	q = dp[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		if (a[i] >= a[i] + q) q = a[i];
		else q = a[i] + q;
		dp[i] = max(dp[i-1], q);
	}
	// 处理分数
//	for (int i = 1; i <= n; i++) cout << dp[i] << " ";
	score[1] = dp[1];
	res = dp[1];
	s[1] = score[1] + dp[1];
	for (int i = 2; i <= n; i++)
	{
		// 维护分值+特征值的最大值
		score[i] = s[i-1];
		s[i] = max(s[i-1], score[i] + dp[i]);
		res = max(res, score[i]);
	}
	if (res >= 0) res = res % p;
	else res = -((-res) % p);
	if (res == 0)
	{
		printf("0");
	}
	else print(res % p);
    return 0;
}
