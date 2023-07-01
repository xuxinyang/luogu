#include <bits/stdc++.h>
using namespace std;
char s[45];
int a[45], n, len, tot, num, g[45][45], flag;
void generate()	// 把i-j的数字都生成一遍，后面就不用再转成数字了
{
	for (int i = 1; i <= len; i++)
		for (int j = i; j <= len; j++)
			for (int k = i; k <= j; k++)
				g[i][j] = g[i][j] * 10 + s[k] - '0';
}
bool check()
{
	int ans = 0, cnt = 1;
	for (int i = 1; i <= tot; i++)
	{
		ans += g[cnt][a[i]];
		cnt = a[i] + 1;
	}
	ans += g[cnt][len];
	return ans == n;
}
void dfs(int step)
{
	if (flag) return;
	if (step > tot)
	{
		if (check()) 
		{
			flag = 1;
			cout << tot << endl;	
		}
		return;
	}
	for (int i = a[step-1] + 1; i <= (len-tot+step-1); i++)
	{
		a[step] = i;
		dfs(step + 1);
	}
}
int main()
{
	cin >> (s + 1);
	cin >> n;
	len = strlen(s + 1);
	generate();
	if (g[1][len] == n)
	{
		cout << "0\n";
		return 0;
	}
	for (int i = 1; i <= len-1; i++)
	{
		tot = i;
		dfs(1);
	}
	if (!flag) cout << "-1\n";
	return 0;
}