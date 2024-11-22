#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull n, k;
string s;
int main()
{
    cin >> n >> k;
    k ^= k>>1;
    while (n--)
    {
        cout << ((k>>n)&1);
    }
    return 0;
}