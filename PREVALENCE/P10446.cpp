#include <bits/stdc++.h>
using namespace std;
#define ll __int128
ll a, b, p;
void read(ll &x)
{
    ll res = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        res = (res << 1) + (res << 3) + (c ^ 48);
        c = getchar();
    }
    x = res*f;
}
void write(ll x)
{
    if (x < 0) putchar('-'), x *= -1;
    if (x > 9) write(x/10);
    putchar(x%10 + '0');
}
int main()
{
    read(a), read(b), read(p);
    write(((a%p)*(b%p))%p);
    return 0;
}