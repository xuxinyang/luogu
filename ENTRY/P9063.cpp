#include <bits/stdc++.h>
using namespace std;
long long n, x;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x == 1){
            cout << "No\n";
            continue;
        }
        if (x&1)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}