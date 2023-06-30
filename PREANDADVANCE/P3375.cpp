#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int nxt[maxn], pos, ans, slen, tlen;
string s, t;
void get_next(string t)
{
	int j = 0, k = -1;
	nxt[0] = -1;
	while (j < tlen)
	{
		if (k == -1 || t[k] == t[j]) nxt[++j] = ++k;
		else k = nxt[k];
	}
}
void kmp(string s, string t, int pos)
{
	int i = pos, j = 0;
	while (i < slen && j < tlen)
	{
		if (j == -1 || s[i] == t[j]) i++, j++;
		else j = nxt[j];
		if (j == tlen)
		{
			cout << i - tlen + 1 << endl;
			j = nxt[j];
		}
	}
}
int main()
{
	cin >> s >> t;
	slen = s.length(), tlen = t.length();
	get_next(t);
	kmp(s, t, 0);
	for (int i = 1; i <= tlen; i++)
		cout << nxt[i] << " ";
	return 0;
}