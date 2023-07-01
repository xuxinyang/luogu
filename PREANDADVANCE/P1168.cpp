#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, x;
vector<int> a;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		a.insert(upper_bound(a.begin(), a.end(), x), x);
		if (i % 2 == 1) cout << a[(i-1)/2] << "\n";
	}
	return 0;
}