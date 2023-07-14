#include <bits/stdc++.h>
using namespace std;
const string s = "0123456789ABCDEFGHIJKLMN";
int b;
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
string ten2b(int x)
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
	cin >> b;
	for (int i = 1; i <= 300; i++)
	{
		int p = i * i;
		string pz = ten2b(p);
		if (isPalindrome(pz)) 
			cout << ten2b(p) << " " << pz << "\n";
	}
	return 0;
}
