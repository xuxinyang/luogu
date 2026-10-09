#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Node {
    ll w, h;
};
bool operator < (Node A, Node B)
{
    if (A.w != B.w) return A.w > B.w;
    return A.h > B.h;
}
priority_queue<Node> q;

int main()
{
    int n, k;
    ll ans = 0, wi;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> wi;
        q.push({wi, 1});
    }
    if ((n-1)%(k-1) != 0)
        for (int i = 1; i <= k-1-(n-1)%(k-1); i++)
            q.push(Node{0, 1});
    while (q.size() != 1)
    {
        Node tmp;
        ll sum = 0, maxh = 0;
        for (int i = 1; i <= k; i++) 
        {
            tmp = q.top();
            sum += tmp.w;   // 新结点加上子节点权重
            maxh = max(maxh, tmp.h);
            q.pop();
        }
        ans += sum;
        q.push(Node{sum, maxh+1});
    }
    cout << ans << "\n" << q.top().h - 1;
    return 0;
}