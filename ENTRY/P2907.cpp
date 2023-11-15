#include <bits/stdc++.h>
using namespace std;
int n, k;
int dfs(int n)
{
    if (n <= k+1) return 1;
    else if (n == k+2) return 2;
    else
    {
        if ((n-k)/2+(n-k)/2+k == n) return dfs((n-k)/2) + dfs((n-k)/2+k);
        else return 1;
    }
}
int main()
{
    cin >> n >> k;
    cout << dfs(n);
    return 0;
}