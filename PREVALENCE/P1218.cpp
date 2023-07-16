#include <iostream>
using namespace std;
int n;
bool isPrime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0) return false;
	}
	return true;
}
void dfs(int x, int cnt)
{
	if (cnt == n && isPrime(x))
	{
		cout << x << "\n";
		return ;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (isPrime(x))
			dfs(x*10 + i, cnt+1);
	}
}
int main()
{
	cin >> n;
	for (int i = 2; i <= 9; i++)
		dfs(i, 1);
	return 0;
}
