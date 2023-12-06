#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> ve[maxn];
stack<int> st;
int n, m, u, v, s, cntin, cntout, del[maxn];
int flag, in[maxn], out[maxn];
void dfs(int u)
{
    for (int i = del[u]; i < ve[u].size(); i = del[u])
    {
        del[u] = i + 1;
        dfs(ve[u][i]);
    }
    st.push(u);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        in[v]++, out[u]++;
    }
    for (int i = 1; i <= n; i++) sort(ve[i].begin(), ve[i].end());
    s = 1, flag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] != out[i])
        {
            flag = 0;
            if (out[i] - in[i] == 1) cntout++, s = i;
            else if (in[i] - out[i] == 1) cntin++;
            else
            {
                cout << "No";
                return 0;
            }
        }
    }
    if (!flag && !(cntin == cntout && cntin == 1))
    {
        cout << "No";
        return 0;
    }
    dfs(s);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}