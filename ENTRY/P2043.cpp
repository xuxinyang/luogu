#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
int n, a[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 2; i <= n; i++)
    {
        int k = 0;
        if (a[i] == 1) continue;
        for (int j = i; j <= n; j += i)
        {
            while (a[j] % i == 0)
            {
                a[j] /= i;
                k++;
            }
        }
        cout << i << " " << k << "\n";
    }
    return 0;
}