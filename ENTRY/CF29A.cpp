#include <bits/stdc++.h>
using namespace std;
int n;
struct Node
{
    int x, d;
};
Node nodes[105];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nodes[i].x >> nodes[i].d;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (nodes[i].x + nodes[i].d == nodes[j].x && nodes[j].x + nodes[j].d == nodes[i].x)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}