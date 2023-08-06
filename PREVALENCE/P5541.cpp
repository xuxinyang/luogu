#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, a[maxn], x = 0;

int ansmin()
{
    if ((a[n - 1] - a[1] == n - 2 && a[n] - a[n - 1] > 2) || 
    (a[n] - a[2] == n - 2 && a[2] - a[1] > 2))
        return 2;
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        while (j < n && a[j + 1] - a[i] <= n-1)
            j++;
        x = max(x, j - i + 1);
    }
    return n - x;
}

int ansmax()
{
    return max(a[n - 1] - a[1], a[n] - a[2]) - n + 2;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    cout << ansmin() << "\n" << ansmax() << "\n";
    return 0;
}