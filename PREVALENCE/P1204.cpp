#include <bits/stdc++.h>
using namespace std;
int n;
struct Node
{
    int begin, end;
};
Node nodes[5005];
bool cmp(Node x, Node y)
{
    return x.begin < y.begin;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> nodes[i].begin >> nodes[i].end;
    sort(m+1, m+1+n, cmp);
    int begin = nodes[1].begin;
    int end = nodes[1].end;
    int ans1 = 0, ans2 = 0;
    for (int i = 2; i <= n; i++)
    {
        if (nodes[i].begin <= end)
        {
            end = max(end, nodes[i].end);
        }
        else
        {
            ans1 = max(ans1, end - begin);
            ans2 = max(ans2, nodes[i].begin - end);
            begin = nodes[i].begin;
            end = nodes[i].end;
        }
    }
    ans1 = max(ans1, end - begin);
    cout << ans1 << " " << ans2 << endl;
    return 0;
}