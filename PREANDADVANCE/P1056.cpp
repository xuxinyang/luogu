#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int m, n, k, l, d, row[maxn], col[maxn];
int ansrow[maxn], anscol[maxn];
struct Room
{
	int id, val;
	bool operator < (const Room & x) const 
	{
		return val < x.val;
	}
};
Room roomRow[maxn], roomCol[maxn];
priority_queue<Room> pqrow, pqcol;
int main()
{
	cin >> m >> n >> k >> l >> d;
	int x, y, p, q;
	for (int i = 1; i <= d; i++)
	{
		cin >> x >> y >> p >> q;
		if (x == p) col[min(y, q)]++;
		if (y == q) row[min(x, p)]++;
	}
	for (int i = 1; i <= m; i++)
	{
		if (row[i] != 0)
		{
			pqrow.push(Room{i, row[i]});
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (col[i] != 0)
		{
			pqcol.push(Room{i, col[i]});
		}
	}
	int idx = 0, idy = 0;
	while (k-- && !pqrow.empty())
	{
		ansrow[++idx] = pqrow.top().id;
		pqrow.pop();
	}
	while (l-- && !pqcol.empty())
	{
		anscol[++idy] = pqcol.top().id;
		pqcol.pop();
	}
	sort(ansrow + 1, ansrow + idx + 1);
	sort(anscol + 1, anscol + idy + 1);
	for (int i = 1; i <= idx; i++) cout <<  ansrow[i] << " ";
	cout << endl;
	for (int i = 1; i <= idy; i++) cout <<  anscol[i] << " ";
	return 0;
}
