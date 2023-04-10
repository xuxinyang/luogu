#include <bits/stdc++.h>
using namespace std;
const int mod = 10000;
const int leap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int normal[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool is_leap(int x)
{
    if ((x % 400 == 0) || (x % 4 == 0 && x % 100 != 0))
    {
        return true;
    }
    return false;
}
int reverse(int x)
{
    int s = 0;
    while (x)
    {
        s = s * 10 + x % 10;
        x /= 10;
    }
    return s;
}

bool check(int year, int month, int day)
{
    if (is_leap(year))
    {
        if (month >= 1 && month <= 12 && day >= 1 && day <= leap[month])
        {
            return true;
        }
        return false;
    }
    else
    {
        if (month >= 1 && month <= 12 && day >= 1 && day <= normal[month])
        {
            return true;
        }
        return false;
    }
}
int main()
{
    int date1, date2, cnt = 0;
    cin >> date1 >> date2;
    for (int i = date1 / mod; i <= date2 / mod; i++)
    {
        int k = i * 10000 + reverse(i);
        if (k >= date1 && k <= date2 && check(i, reverse(i)/100, reverse(i) % 100))
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}