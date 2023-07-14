#include <bits/stdc++.h>
using namespace std;
const string s = "0123456789ABCDEFGHIJKLMN";
int n, t;
bool isPalindrome(string str)
{
	int i = 0, j = str.length()-1;
	while (i < j)
	{
		if (str[i] != str[j]) return false;
		i++, j--;
	}
	return true;
}
string ten2b(int x, int b)
{
	string ans = "";
	while (x)
	{
		ans = s[x % b] + ans;
		x /= b;
	}
	return ans;
}
int main()
{
	cin >> n >> t;
	while (true)
	{
		t++;
		int cnt = 0, flag = 0;
		for (int i = 2; i <= 10; i++)
		{
			if (isPalindrome(ten2b(t, i))) cnt++;
			if (cnt >= 2)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			if (n-- == 0) return 0;
			cout << t << "\n";
		}
	}
	return 0;
}
