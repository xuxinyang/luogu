#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
int n, cnt, ans = INT_MAX;
struct Cow
{
	int pos, kind;
};
unordered_map<int, int> ump;
Cow cows[maxn];
bool cmp(Cow x, Cow y)
{
	return x.pos < y.pos;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> cows[i].pos >> cows[i].kind;
		ump[cows[i].kind]++;
	}
	sort(cows + 1, cows + n + 1, cmp);
	cnt = ump.size();
	ump.clear();
	int p = 1, q = 1;
	while (p <= q && q <= n)
	{
		while (ump.size() < cnt)
		{
			ump[cows[q].kind]++;
			if (ump.size() == cnt) break;
			q++;
		}
		while (ump[cows[p].kind] > 1)
		{
			ump[cows[p].kind]--;
			p++;
		}
		ans = min(ans, cows[q].pos - cows[p].pos);
		ump[cows[++q].kind]++;
	}
	cout << ans;
	return 0;
}