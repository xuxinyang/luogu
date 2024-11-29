#include <bits/stdc++.h>
using namespace std;
const int maxn = 15e4+5;
struct Node
{
    int t1, t2;
    Node(){}
    Node(int t1, int t2):t1(t1),t2(t2){}
    bool operator < (const Node &A) const {
        return t2 < A.t2;
    }
};
priority_queue<int> pq;
int n, ans;
Node nodes[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nodes[i].t1 >> nodes[i].t2;
    }
    sort(nodes+1, nodes+n+1);
    long long t = 0;
    for (int i = 1; i <= n; i++)
    {
        t += nodes[i].t1;
        pq.push(nodes[i].t1);
        if (t <= nodes[i].t2) ans++;
        else t -= pq.top(), pq.pop();
    }
    cout << ans;
    return 0;
}