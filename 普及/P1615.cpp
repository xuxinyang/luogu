#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll h1, m1, s1, h2, m2, s2, k;
    scanf("%lld:%lld:%lld", &h1, &m1, &s1);
    scanf("%lld:%lld:%lld", &h2, &m2, &s2);
    scanf("%lld", &k);
    cout << (h2*3600+m2*60+s2 - h1*3600-m1*60-s1) * k << endl; 
    return 0;
}