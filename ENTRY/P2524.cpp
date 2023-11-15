#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans, len, fac[15];
    string s;
    cin >> n >> s;
    fac[0] = 1;
    for (int i = 1; i < n; i++) fac[i] = fac[i-1] * i;
    for (int i = 0; i < n; i++)
    {
        int k = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] > s[j]) k++;
        }
        ans += k * fac[n-i-1];
    }
    cout << ans + 1;
    return 0;
}