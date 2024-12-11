#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 146097;
const int mons[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll q, r, y[maxn], m[maxn], d[maxn], t;
bool is_leap(int year)
{
    return year%4==0 && year%100!=0 || year%400==0;
}
int main()
{
    m[0] = d[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        d[i] = d[i-1]+1, m[i] = m[i-1], y[i] = y[i-1];
        if (m[i] == 2)
        {
            if (is_leap(y[i]) && d[i] > 29) m[i]++, d[i] = 1;
            else if (!is_leap(y[i]) && d[i] > 28) m[i]++, d[i] = 1;
        }
        else {if (d[i] > mons[m[i]-1]) m[i]++, d[i] = 1;}
        if (m[i] > 12) y[i]++, m[i] = 1;
    }
    scanf("%lld", &q);
    while (q--)
    {
        scanf("%lld", &r);
        if (r > 2299160)    // 大于儒略历天数，在格里高历
        {
            r -= 2159351;   // 2159351（跳过的天数）=2159358（1200年1月1日儒略历）+3（补上1300、1400、1500三年闰年）-10（10天删除日期）
            t = r/maxn*400+1200;
            r %= maxn;
        }
        else
        {
            t = r / 1461*4-4712;
            r %= 1461;
        }
        if (t + y[r] > 0) printf("%lld %lld %lld\n", d[r], m[r], t+y[r]);
        else printf("%lld %lld %lld BC\n", d[r],m[r],1-t-y[r]);
    }
    return 0;
}