#include <bits/stdc++.h>
using namespace std;
// 数组实现，小根堆
const int maxn = 1e6+5;
int n, op, x, heap[maxn], cnt;
void up(int u)
{
    if (heap[u] < heap[u/2] && u/2)
    {
        swap(heap[u], heap[u/2]);
        up(u/2);
    }
}
void push(int x)
{
    heap[++cnt] = x;
    up(cnt);
}
int top()
{
    return heap[1];
}
void down(int u)
{
    int v = u;
    if (u*2 <= cnt && heap[u*2]<heap[u]) v = u*2;
    if (u*2+1 <= cnt && heap[u*2+1]<heap[v]) v = u*2+1;
    if (u != v) swap(heap[u], heap[v]), down(v);
}
void pop()
{
    heap[1] = heap[cnt--];
    down(1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            push(x);
        }
        else if (op == 2) cout << top() << "\n";
        else pop();
    }
    return 0;
}