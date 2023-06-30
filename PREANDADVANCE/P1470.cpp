#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int dp[maxn], m, ans;
string t, str = " ";
set<string> s[25];
int main()
{
	while (cin >> t)
	{
		if (t == ".") break;
		s[t.size()].insert(t);
		m = max(m, int(t.size()));
	}
	dp[0] = 1;
	while (cin >> t) str += t;
	for (int i = 1; i < (int)str.size(); i++)
	{
		for (int j = min(i, m); j >= 1; j--)
		{
			string tt = str.substr(i-j+1, j);
			if (s[tt.size()].count(tt) == 1 && dp[i-j] == 1)
			{
				ans = i;
				dp[i] = 1;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}