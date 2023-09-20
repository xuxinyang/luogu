#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n, st, cnt;
struct Node
{
    int start, end, val;
};
bool a[maxn], used[maxn];
queue<Node> q, tmp;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    a[n+1] = !a[n];
    st = 1;
    for (int i = 2; i <= n+1; i++)
    {
        if (a[i] != a[i-1])
        {
            q.push(Node{st, i-1, a[i-1]});
            st = i;
        }
    }
    cnt = n;
    while (cnt)
    {
        while (!q.empty())
        {
            Node cur = q.front();
            q.pop();
            while (used[cur.start] && cur.start <= cur.end) cur.start++;
            if (cur.start > cur.end) continue;
            printf("%d ", cur.start);
            cnt--;
            used[cur.start] = 1;
            if (cur.start == cur.end) continue;
            cur.start++;
            tmp.push(cur);
        }
        printf("\n");
        while (tmp.size())
        {
            Node cur = tmp.front();
            tmp.pop();
            while (!tmp.empty())
            {
                if (tmp.front().val == cur.val)
                {
                    cur.end = tmp.front().end;
                    tmp.pop();
                }
                else break;
            }
            q.push(cur);
        }
    }
    return 0;
}