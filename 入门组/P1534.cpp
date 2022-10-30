#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a, b, sum, curr;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        curr = curr + a + b - 8;
        sum += curr;
    }
    cout << sum << endl;
    return 0;
}