#include <bits/stdc++.h>
using namespace std;
int n, k;
char c[55];
int ne[55];
int main()
{
    cin >> n >> k;
    cin >> (c+1);
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (c[j+1]!=c[i] && j) j = ne[j];
        if (c[j+1] == c[i]) j++;
        ne[i] = j;
    }
    for (int i = 1; i <= n; i++) cout << c[i];
    int ans = k-1;
    while (ans--) cout << c + ne[n] + 1;
    return 0;
}