#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
vector<int> v[maxn];
int n;
void pre_order(int root)
{
    if (root == 0) return;
    cout << root << " ";
    pre_order(v[root][0]);
    pre_order(v[root][1]);
}

void mid_order(int root)
{
    if (root == 0) return;
    mid_order(v[root][0]);
    cout << root << " ";
    mid_order(v[root][1]);
}

void aft_order(int root)
{
    if (root == 0) return;
    aft_order(v[root][0]);
    aft_order(v[root][1]);
    cout << root << " ";
}

int main()
{
    cin >> n;
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        v[i].push_back(x);
        v[i].push_back(y);
    }
    // pre_order
    pre_order(1);
    cout << "\n";
    // mid_order
    mid_order(1);
    cout << "\n";
    // aft_order
    aft_order(1);
    return 0;
}