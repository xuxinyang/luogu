#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int leap_months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int norm_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int max_index[8] = {9, 9, 9, 9, 1, 9, 3, 9};
int t, ans, tot;
int prime[maxn], flag[maxn];
string s;
void initPrime()
{
    flag[1] = 1;
    for (int i = 2; i < 10005; i++)
    {
        if (!flag[i]) prime[++tot] = i;
        for (int j = 1; j <= tot; j++)
        {
            if (i * prime[j] >= 10005) break;
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    } 
}
bool isPrime(int x)
{
    if (x < 2) return false;
    for (int i = 1; i <= tot; i++)
    {
        if (x % prime[i] == 0) return x == prime[i];
    }
    return true;
}
bool isLeap(int y)
{
    return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
}
bool isValid(int day)
{
    int y = day / 10000;
    int m = day / 100 % 100;
    int d = day % 100;
    if (y == 0) return false;
    if (!isPrime(day)) return false;
    if (isLeap(y) && d > leap_months[m-1]) return false;
    if (!isLeap(y) && d > norm_months[m-1]) return false;
    return true;
}
void dfs(int index, int num)
{
    if (num % 100  > 31) return;
    if (num % 10000 > 1231) return;
    if (index == 5 && !isPrime(num)) return;
    if (index == 3 && !isPrime(num)) return;
    if (index == 3)
    {
        int m = num / 100 % 100;
        int d = num % 100;
        if (m < 1 || m > 12) return;
        if (d < 1 || d > 31) return;
    }
    if (index == -1)
    {
        if (isPrime(num) && isValid(num))
        {
            // cout << num << " ";
            ans++;
        }
        return;
    }
    if (s[index] == '-')
    {
        for (int i = 0; i <= max_index[index]; i++)
        {
            dfs(index-1, i*pow(10,7-index)+num);
        }
    }
    else dfs(index-1, (s[index]-'0')*pow(10,7-index)+num);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    initPrime();
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> s;
        dfs(7, 0);
        cout << ans << "\n";
    }
    return 0;
}