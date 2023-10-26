#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, a[maxn], ans;
struct Num
{
    int val, id;
};
Num nums[maxn];
void update(int x)
{
    while (x <= n)
    {
        a[x]++;
        x += x&-x;
    }
}
int query(int x)
{
    int res = 0;
    while (x)
    {
        res += a[x];
        x -= x&-x;
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i].val;
        nums[i].id = i;
    }
    sort(nums + 1, nums + n + 1, [](Num x, Num y){
        return x.val == y.val ? x.id < y.id : x.val < y.val;
    });
    ans = 1;
    for (int i = 1; i <= n; i++)
    {
        update(nums[i].id);
        ans = max(ans, i-query(i));
    }
    cout << ans;
    return 0;
}