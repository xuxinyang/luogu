#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, ans, s[maxn];
struct Num
{
	int id, val;
};
Num nums[maxn];
bool cmp(Num x, Num y)
{
	return x.val < y.val;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i].val;
		nums[i].id = i;
	}
	sort(nums + 1, nums + n + 1, cmp);
	for (int i = 1; i <= n; i++) s[nums[i].id] = i;
	for (int i = 1; i <= n; i++)
	{
		while (s[i] != i)
		{
			swap(s[s[i]], s[i]);
			ans++;
		}
	}
	cout << ans;
	return 0;
}
