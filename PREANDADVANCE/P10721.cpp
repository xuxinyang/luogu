#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
struct Node
{
    int id, score;
};
Node nodes[25];
int a[100005], p, ans, dp[100005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nodes[i].score;
        nodes[i].id = i;
    }
    sort(nodes+1, nodes+n+1, [](Node x, Node y){
        return x.score > y.score;
    });
    cin >> m >> s;
    int i = 0;
    while (i <= m-3)
    {
        if (s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')
        {
            if (i>=3 && s[i-1]=='c'&&s[i-2]=='b'&&s[i-3]=='a') a[p]++;
            else a[++p] = 1;
            i += 3;
        }
        else i++;
    }
    for (int i = 1; i <= p; i++)
    {
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= n; j++)
        {
            for (int k = nodes[j].id; k <= a[i]; k++)
            {
                dp[k] = max(dp[k], dp[k-nodes[j].id] + nodes[j].score);
            }
        }
        ans += dp[a[i]];
    }
    cout << ans;
    return 0;
}