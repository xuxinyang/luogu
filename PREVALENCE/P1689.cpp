#include <bits/stdc++.h>
using namespace std;
int i, x, a[10], b[10];
string t, s;
int main()
{
    while (cin >> t)
        s += t;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == '?')
            b[++x] = 1;
        if (s[i] < '0' || s[i] > '9')
            continue;
        for (x++; s[i] >= '0' && s[i] <= '9'; i++)
            a[x] = a[x] * 10 + s[i] - 48;
    }
    if (s.find('+') < s.size())
        x = 1;
    else
        x = 0;
    if (x && b[1])
        printf("%d\n", a[3] - a[2]);
    else if (x && b[2])
        printf("%d\n", a[3] - a[1]);
    else if (x && b[3])
        printf("%d\n", a[1] + a[2]);
    else if (!x && b[1])
        printf("%d\n", a[2] + a[3]);
    else if (!x && b[2])
        printf("%d\n", a[1] - a[3]);
    else
        printf("%d\n", a[1] - a[2]);
    return 0;
}