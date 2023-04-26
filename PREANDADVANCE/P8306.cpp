#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6+5;
const int maxz = 65;
int trie[maxn][maxz];
int t, n, q, tot, cnt[maxn];
char c[maxn];
void init()
{
    // cout << tot << " ";
    for (int i = 1; i <= tot; i++)
        for (int j = 0; j <= 65; j++)
            trie[i][j] = 0;
    for (int i = 1; i <= tot; i++) cnt[i] = 0;
    tot = 1;
}
int get_index(char x)
{
    int ch = 0;
    if (x >= 'A' && x <= 'Z') ch = x - 'A';
    else if (x >= 'a' && x <= 'z') ch = x - 'a'+ 26;
    else ch = x - '0' + 52;
    return ch;
}
void insert(char s[])
{
    int len = strlen(s), p = 1;
    for (int i = 0; i < len; i++)
    {
        int ch = get_index(s[i]);
        if (!trie[p][ch]) trie[p][ch] = ++tot;
        p = trie[p][ch];
        cnt[p]++;
    }
}
int query(char s[])
{
    int len = strlen(s), p = 1;
    for (int i = 0; i < len; i++)
    {
        int ch = get_index(s[i]);
        p = trie[p][ch];
        if (!p) return 0;
    }
    return cnt[p];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        init();
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> c;
            insert(c);
        }
        for (int i = 1; i <= q; i++)
        {
            cin >> c;
            cout << query(c) << "\n";
        }
    }
    return 0;
}