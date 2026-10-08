#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
int dep;
bool flag;
i128 st[15], ans[15];
i128 gcd(i128 a, i128 b)
{
    while (b)
    {
        i128 t = a % b;
        a = b;
        b = t;
    }
    return a;
}
void print(i128 x)
{
    if (x >= 10) print(x / 10);
    cout << int(x % 10);
}
// a / b 始终为最简正分数
// 当前准备填写第 x 个分母
void dfs(i128 a, i128 b, int x)
{
    int left = dep - x + 1;
    // 最后一项：直接判断能否结束
    if (left == 1)
    {
        if (a != 1 || b <= st[x - 1]) return;
        if (flag && b >= ans[dep]) return;
        st[x] = b;
        for (int i = 1; i <= dep; i++) ans[i] = st[i];
        flag = true;
        return;
    }
    i128 l = max(b / a + 1, st[x - 1] + 1);
    /*
      剩余 left 项，第一项分母为 i。
      后续分母严格增大，所以：
          a / b < left / i
      即：
          a * i < left * b
    */
    i128 r = (left * b - 1) / a;
    if (flag) r = min(r, ans[dep] - left);
    for (i128 i = l; i <= r; i++)
    {
        /*
          搜索中可能找到更好的答案，
          因此每轮重新检查这个界限。
        */
        if (flag && i + left - 1 >= ans[dep]) break;
        /*
          后续 left 个分母至少为：
              i, i+1, ..., i+left-1
          用一个容易计算的上界：
              1/i + (left-1)/(i+1)
          如果这个上界仍小于 a/b，就不可能凑够。
          i 越大，上界越小，因此可以直接 break。
        */
        if (a * i * (i + 1) > b * (left * i + 1)) break;
        st[x] = i;
        i128 g = gcd(b, i);
        i128 na = a * (i / g) - b / g;
        i128 nb = b * (i / g);
        i128 c = gcd(na, nb);
        dfs(na / c, nb / c, x + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll aa, bb;
    cin >> aa >> bb;
    i128 a = aa, b = bb;
    i128 g = gcd(a, b);
    a /= g, b /= g;
    st[0] = 1;
    for (dep = 1; dep <= 10; dep++)
    {
        flag = false;
        dfs(a, b, 1);
        if (flag)
        {
            for (int i = 1; i <= dep; i++)
            {
                if (i > 1)cout << ' ';
                print(ans[i]);
            }
            cout << '\n';
            break;
        }
    }
    return 0;
}