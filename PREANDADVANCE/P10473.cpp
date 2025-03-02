#include <bits/stdc++.h>
using namespace std;
map<char, int> mp = {
    {'+', 1}, {'-', 1},
    {'*', 2}, {'/', 2},
    {'^', 3}, 
};
string s;
stack<char> st;
string suf[35];
stack<int> res;
int pos;
bool isdigit(char c)
{
    return c >= '0' && c <= '9';
}
void calc(char c)
{
    int a = res.top();
    res.pop();
    int b = res.top();
    res.pop();
    if (c == '+') res.push(b+a);
    else if (c == '-') res.push(b-a);
    else if (c == '*') res.push(b*a);
    else if (c == '/') res.push(b/a);
    else if (c == '^') res.push(pow(b, a));
}
int main()
{
    getline(cin, s);
    s = '(' + s + ')';
    for(int i = 0; i < s.length(); i++)
    {
        string t = "";
        if (s[i] == '-')
        {
            if (i==1 || i>1 && s[i-1] == '(' && isdigit(s[i+1]))
            {
                i++;
                t = "-";
                while (isdigit(s[i]) && i < s.length())
                {
                    t = t + s[i];
                    i++;
                }
                suf[++pos] = t;
            }
        }
        if (isdigit(s[i]))
        {
            while (isdigit(s[i]) && i < s.length())
            {
                t += s[i], i++;
            }
            suf[++pos] = t;
        }
        if (i >= s.length()) break;
        char c = s[i];
        if (c == '(') st.push(c);
        else if (c == ')')
        {
            if (!st.empty() && st.top() != '(')
            {
                suf[++pos] = st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (st.empty() || st.top() == '(') st.push(c);
            else
            {
                while (!st.empty() && mp[st.top()] >= mp[c] && st.top() != '(')
                {
                    suf[++pos] = st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') st.pop();
                st.push(c);
            }
        }
        if (!st.empty())cout << st.top() << " ";
    }
    cout << "\n";
    while (!st.empty() && st.top() != '(') suf[++pos] = st.top(), st.pop();
    for (int i = 1; i <= pos; i++) cout << suf[i] << " ";
    for (int i = 1; i <= pos; i++)
    {
        if (suf[i].length() == 1 && !isdigit(suf[i][0]))
        {
            char c = suf[i][0];
            calc(c);
        }
        else
        {
            int num = atoi(suf[i].c_str());
            res.push(num);
        }
    }
    cout << res.top();
    return 0;
}
// -3-2+5*(10-8)
// (-3-2+5*(10-8))
// -3 2 - 5 10 8 - * +