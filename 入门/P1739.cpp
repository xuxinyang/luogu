#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> st;
int main()
{
    getline(cin, s, '@');
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') st.push(s[i]);
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    if (st.empty()) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}