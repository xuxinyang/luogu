#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int n, m;
vector<int> edges[maxn];
int degree[maxn], a[maxn];
stack<int> st;
bool vis[maxn];
int flag;
bool topo(int r)
{
    int sz = 0;
    bool finished = true;
    int t[maxn];
    for (int i = 0; i < n; i++)
    {
        t[i] = degree[i];
        if (!degree[i]) st.push(i), vis[i] = true;
    }
    while (!st.empty())
    {
        if (st.size() > 1) finished = false;
        int k = st.top();
        a[sz++] = k;
        st.pop();
        for (int i = 0; i < edges[k].size(); i++) t[edges[k][i]]--;
        for (int i = 0; i < n; i++) if (!t[i] && !vis[i]) st.push(i), vis[i] = true;
    }
    if (sz < n) return false;
    if (finished && !flag) flag = r;
    return true; 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        string c;
        cin >> c;
        int x = c[0] - 'A', y = c[2] - 'A';
        edges[x].push_back(y);
        degree[y]++;
        if (!topo(i))
        {
            cout << "Inconsistency found after " << i << " relations.";
            return 0;
        }
        memset(vis, false, sizeof(vis));
    }
    if (flag)
    {
        cout << "Sorted sequence determined after " << flag << " relations: ";
        for (int i = 0; i < n; i++) cout << char(a[i] + 'A');
        cout << ".";
    }
    else cout << "Sorted sequence cannot be determined.";
    return 0;
}