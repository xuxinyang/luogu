#include <bits/stdc++.h>
using namespace std;
long long k, n, ans;
stack<int> s;
int main()
{
    cin >> k >> n;
    while (n) s.push(n&1), n >>= 1;
    while (!s.empty()) ans += s.top() * pow(k, s.size()-1), s.pop();
    cout << ans << endl;
    return 0;
}