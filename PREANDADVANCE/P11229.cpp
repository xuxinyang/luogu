#include <bits/stdc++.h>
using namespace std;
const int nums[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int cal[25] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888};
int t, n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		if (n <= 21) cout << cal[n] << "\n";
		else
		{
			int k = n/7-2;
			int p = n%7+14;
			cout << cal[p];
			for (int i = 1; i <= k; i++) cout << 8;
			cout << "\n";
		}
	}
	return 0;
}