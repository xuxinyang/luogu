#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
struct City
{
	int pers;
	int kms;
	string city_name;
};
City citys[155];
int per, km, ans_fee = INT_MAX;
string city, ans_city;
bool cmp(City x, City y)
{
	return x.kms < y.kms;
}
int main()
{
	int i = 1;
	while (cin >> per >> km >> city)
	{
		citys[i].pers = per; 
		citys[i].kms = km;
		citys[i].city_name = city;
		if (km == 0) break;
		i++;
	}
	sort(citys + 1, citys + i + 1, cmp);
	for (int j = 1; j <= i; j++)
	{
		int tmp_fee = 0;
		string tmp_name = citys[j].city_name;
		for (int k = 1; k <= i; k++)
		{
			if (j != k)
			{
				tmp_fee += abs((citys[k].kms - citys[j].kms) * citys[k].pers);
			}
		}
		if (ans_fee > tmp_fee)
		{
			ans_fee = tmp_fee;
			ans_city = tmp_name;
		}
	}
	cout << ans_city << " " << ans_fee;
	return 0;
}
