#include <bits/stdc++.h>
using namespace std;
const int maxl = 1e5+5;
const int mod = 1e4+7;
char s[maxl];
int n;
struct Node
{
    int rootl, rootr;
};
stack<char> op;
stack<Node> num;
map<char, int> mp{{'+', 1}, {'*', 2}};
void eval()
{
    char c = op.top(); op.pop();
    Node a = num.top(); num.pop();
    Node b = num.top(); num.pop();
    switch(c)
    {
        case '+':
            num.push({a.rootl*b.rootl%mod, (b.rootl*a.rootr+b.rootr*a.rootl+b.rootr*a.rootr)%mod});
            break;
        case '*':
            num.push({(b.rootl*a.rootl+b.rootl*a.rootr+b.rootr*a.rootl)%mod, (b.rootr*a.rootr)%mod});
            break;
    }
}
int main()
{
    cin >> n >> s;
    num.push({1, 1});
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];
        if (c == '(') op.push(c);
        else if (c == ')')
        {
            while (op.size() > 0 && op.top() != '(') eval();
            op.pop();
        }
        else
        {
            while (op.size() > 0 && op.top() != '(' && mp[op.top()] >= mp[c]) eval();
            op.push(c);
            num.push({1, 1});
        }
    }
    while (op.size()) eval();
    cout << num.top().rootl << endl;
    return 0;
}