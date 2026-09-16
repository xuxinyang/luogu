#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e4+5;
int n, a[N], v[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= 9; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cout << v[a[i]] << " ";
    return 0;
}