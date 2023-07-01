#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
string s, s1, s2;
int a[maxn], b[maxn], c[maxn];
int prime[maxn], p;
bool is_prime[maxn];
void ai_prime()
{
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= 100000; i++)
    {
        if (is_prime[i])
        {
            for (int j = i + i; j <= 100000; j += i)
                is_prime[j] = 0;
        }
    }
    for (int i = 1; i <= 100000; i++)
    {
        if (is_prime[i]) prime[++p] = i;
    }
}
int main()
{
    cin >> s;
    ai_prime();
    int pos = s.find('+');
    s1 = s.substr(0, pos);
    s2 = s.substr(pos + 1, s.length());
    int l1 = s1.length(), l2 = s2.length();
    int sum = 0, x = 0, y = 0;
    for (int i = 0; i <= l1; i++)
    {
        if (i == l1 || s1[i] == ',')
        {
            a[++x] = sum;
            sum = 0;
            continue;
        }
        sum = sum * 10 + s1[i] - '0';
    }
    reverse(a + 1, a + x + 1);
    sum = 0;
    for (int i = 0; i <= l2; i++)
    {
        if (i == l2 || s2[i] == ',')
        {
            b[++y] = sum;
            sum = 0;
            continue;
        }
        sum = sum * 10 + s2[i] - '0';
    }
    reverse(b + 1, b + y + 1);
    int maxl = max(x, y);
    for (int i = 1; i <= maxl; i++)
    {
        c[i] += a[i] + b[i];
        c[i+1] += c[i] / prime[i];
        c[i] %= prime[i];
    }
    int p = c[maxl+1] > 0 ? maxl + 1: maxl;
    while (c[p] == 0 && p > 0) p--;
    cout << c[p];
    for (int i = p-1; i > 0; i--)
        cout << "," << c[i];
    return 0;
}