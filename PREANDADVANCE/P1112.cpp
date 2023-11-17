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
        int len = s.length();
        if (len > 2 && s[len-1] != s[len-3] || s[len-1] == s[len-2]) return s;
    }
    return s;
}
bool isWave(string s)
{
    if (s.length() == 1) return true;
    if (s.length() == 2 && s[0] != s[1]) return true;
    if (s.length() == 2 && s[0] == s[1]) return false;
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