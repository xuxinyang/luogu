#include <bits/stdc++.h>
using namespace std;
const int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n, a[10], day;
bool isLeap(int year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}
int main()
{
	cin >> n;
	day = 13;
	for (int i = 1900; i <= 1900+n-1; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			a[day % 7]++;
			if (isLeap(i) && j == 1) day += 1;
			day += mon[j];
		}
	}
	cout << a[6] << " " << a[0] << " ";
	for (int i = 1; i <= 5; i++) cout << a[i] << " ";
	return 0;
}
