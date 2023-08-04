#include <bits/stdc++.h>
using namespace std;
const int maxn = 8e4+5;
long long n, x, ans;
stack<int> st;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        while (!st.empty() && st.top() <= x) st.pop();
        ans += st.size();
        st.push(x);
    }
    cout << ans;
    return 0;
}