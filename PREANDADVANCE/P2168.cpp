#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node
{
    ll w, h;
    Node(){w = 0, h = 0;}
    Node(ll w, ll h):w(w), h(h){}
    bool operator < (const Node &a) const {return a.w == w? h>a.h:w>a.w;}
};
ll ans;
priority_queue<Node> q;
int main()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        ll w;
        cin >> w;
        q.push(Node{w, 1});
    }
    while ((q.size()-1)%(k-1)!= 0) q.push(Node{0,1});
    while (q.size() >= k)
    {
        ll h = -1, w = 0;
        for (int i = 1; i <= k; i++)
        {
            Node t = q.top(); q.pop();
            h = max(h, t.h);
            w += t.w;
        }
        ans += w;
        q.push(Node{w, h+1});
    }
    cout << ans << "\n" << q.top().h-1;
    return 0;
}