#include <bits/stdc++.h>
using namespace std;
int l, r, L, R, k;
string ten2x(int num, int p)
{
    string s = "";
    while (num)
    {
        if (num % p >= 10)
            s = char(num % p - 10 + 'A') + s;
        else
            s = char(num % p + '0') + s;
        num /= p;
    }
    return s;
}
bool isWave(string s)
{
    for (int i = 0; i < s.length() - 2; i++)
    {
        if (s[i] != s[i + 2] || s[i] == s[i+1])
            return false;
    }
    return true;
}
int main()
{
    scanf("%d %d %d %d %d", &l, &r, &L, &R, &k);
    for (int i = L; i <= R; i++)
    {
        int p = 0;
        for (int j = l; j <= r; j++)
        {
            if (isWave(ten2x(i, j)))
                p++;
        }
        if (p == k)
            printf("%d\n", i);
    }
    return 0;
}