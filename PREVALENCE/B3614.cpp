#include <bits/stdc++.h>
using namespace std;
#define MAXN    1000000
#define ull unsigned long long
const int maxn = 1e6+5;
ull t, n, top, st[maxn], x;
string op;
void init()
{
    top = 0;
}
void push(ull x)
{
    st[++top] = x;
}
void pop()
{
    if (top == 0)
    {
        cout << "Empty\n";
        return;
    }
    top--;
}
ull size()
{
    return top;
}
bool isEmpty()
{
    return top == 0;
}
void getTop()
{
    if (top == 0) cout << "Anguei!\n";
    else cout << st[top] << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        init();
        cin >> n;
        while (n--)
        {
            cin >> op;
            if (op == "push")
            {
                cin >> x;
                push(x);
            }
            else if (op == "query") getTop();
            else if (op == "size") cout << size() << "\n";
            else pop();
        }
    }
    return 0;
}