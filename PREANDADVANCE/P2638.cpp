#include <bits/stdc++.h>
using namespace std;
#define int128 __int128
inline int128 read()
{
    int128 x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '0') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void write(int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int128 C(int128 r, int128 n)
{
    int128 ans = 1;
    for (int128 i = 1; i <= r; i++)
    {
        ans *= n - i + 1;
        ans /= i;
    }
    return ans;
}
int main()
{
    int128 n, a, b;
    n = read(), a = read(), b = read();
    write(C(n, a + n) * C(n, b + n));
    return 0;
}