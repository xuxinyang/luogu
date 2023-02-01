#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m - n%m; i++) cout << n / m << " ";
    for (int i = 1; i <= n%m; i++) cout << n / m + 1 << " ";
    return 0;
}