#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
char s[maxn];
int n, q, a[maxn], son[maxn][2], flag[maxn], c[maxn], k, ans;
stack<int> st;
int dfs(int u, int f)
{
    a[u] ^= f;
    if (u <= n) return a[u];
    int x = dfs(son[u][0], f^flag[son[u][0]]);
    int y = dfs(son[u][1], f^flag[son[u][1]]);
    if (a[u] == 2) 
    {
        if (x == 0) c[son[u][1]] = 1;
        if (y == 0) c[son[u][0]] = 1;
        return x & y;
    }
    else
    {
        if (x == 1) c[son[u][1]] = 1;
        if (y == 1) c[son[u][0]] = 1;
        return x | y;
    }
}
void dfs2(int u)
{
    if (u <= n) return;
    c[son[u][0]] |= c[u];
    c[son[u][1]] |= c[u];
    dfs2(son[u][0]);
    dfs2(son[u][1]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin.getline(s, sizeof(s));
    cin >> n;
    int x, y;
    k = n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; s[i]; i+=2)
    {
        if (s[i] == 'x')
        {
            x = 0;
            i++;
            while (s[i] != ' ') x = x * 10 + s[i] - '0', i++;
            i--;
            st.push(x);
        }
        else if (s[i] == '&')
        {
            x = st.top();
            st.pop();
            y = st.top();
            st.pop();
            st.push(++k);
            a[k] = 2;
            son[k][0] = x;
            son[k][1] = y;
        }
        else if (s[i] == '|')
        {
            x = st.top();
            st.pop();
            y = st.top();
            st.pop();
            st.push(++k);
            a[k] = 3;
            son[k][0] = x;
            son[k][1] = y;
        }
        else if (s[i] == '!') flag[st.top()] ^= 1;
    }
    ans = dfs(k, flag[k]);
    dfs2(k);
    cin >> q;
    while (q--)
    {
        cin >> x;
        cout << (c[x] ? ans : !ans) << "\n";
    }
    return 0;
}