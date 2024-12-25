#include <bits/stdc++.h>
using namespace std;
#define ll long long
deque<ll> dq;
int main()
{
    ll n, k;
    string s;
    cin >> n >> k >> s;
    while (k) dq.push_front(k%2), k /= 2;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'U' && dq.size()>1) dq.pop_back();
        else if (s[i] == 'L') dq.push_back(0);
        else if (s[i] == 'R') dq.push_back(1);
    }
    while (!dq.empty())
    {
        k = k*2+dq.front();
        dq.pop_front();
    }
    cout << k;
    return 0;
}