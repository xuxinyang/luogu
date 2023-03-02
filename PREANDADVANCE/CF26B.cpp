#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> st;
int ans;
int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
                ans += 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}