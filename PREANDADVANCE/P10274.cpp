#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
string s[maxn];
int n, q, cnt, a[maxn], b[maxn], c[maxn];
bool bp[maxn], bs[maxn], ap[maxn], as[maxn], aa[maxn];
void init()
{
	s[0] = "or";
	for (int i = 1; i <= n; i+=2)
	{
		if (s[i-1] == "or") 
		{
			b[i] = ++cnt;
			c[cnt] = i;
			bp[i] = 1; 
			a[cnt] = (s[i]=="true");
			ap[i] = ap[c[b[i]-1]]|a[cnt-1];
		}
		else
		{
			b[i] = cnt;
			bp[i] = a[cnt];
			a[cnt] &= (s[i]=="true");
			ap[i] = ap[c[b[i]-1]]|a[cnt-1];
		}
	}
	s[n+1] = "or";
	cnt = 0;
	for (int i = n; i >= 1; i -= 2)
	{
		if (s[i+1] == "or")
		{
			bs[i] = 1;
			aa[++cnt] = (s[i]=="true");
			as[i] = as[c[b[i]+1]]|aa[cnt-1];
		}
		else
		{
			bs[i] = aa[cnt];
			aa[cnt] &= (s[i]=="true");
			as[i] = as[c[b[i]+1]]|aa[cnt-1];
		}
	}
}
bool query(int l, int r, string x)
{
	if (ap[l] || as[r]) return 1;
	if (bp[l]==0 || bs[r] == 0) return 0;
	return x=="true";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> s[i];
	init();
	while (q--)
	{
		int l, r;
		string x;
		cin >> l >> r >> x;
		if (query(l, r, x) == (x=="true")) cout << "Y";
		else cout << "N";
	}
	return 0;
}
