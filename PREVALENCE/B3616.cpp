#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int n, x, op;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            q.push(x);
        }
        else if (op == 2)
        {
            if (q.empty())
            {
                cout << "ERR_CANNOT_POP\n";
            }
            else q.pop();
        }
        else if (op == 3)
        {
            if (q.empty())
            {
                cout << "ERR_CANNOT_QUERY\n";
            }
            else cout << q.front() << "\n";
        }
        else cout << q.size() << "\n";
    }
    return 0;
}