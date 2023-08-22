#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int siz, heap[maxn], n, op, x;
void push_up(int &id, int x)
{
    while (id > 1 && x < heap[id/2])
    {
        heap[id] = heap[id/2];
        id /= 2;
    }
}
void push_down(int &id, int x)
{
    int ch = id * 2;
    while (ch <= siz)
    {
        if (ch < siz && heap[ch+1] < heap[ch]) ch++;
        if (x <= heap[ch]) break;
        heap[id] = heap[ch];
        id = ch;
        ch += ch;
    }
}
void insert(int x)
{
    int id = ++siz;
    push_up(id, x);
    heap[id] = x;
}
void delete_val()
{
    int id = 1, x = heap[siz--];
    push_down(id, x);
    heap[id] = x;
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
            insert(x);
        }
        else if (op == 2) cout << heap[1] << "\n";
        else delete_val();
    }   
    return 0;
}