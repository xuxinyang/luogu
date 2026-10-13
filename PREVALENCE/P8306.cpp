#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5+5;
int trie[N][26];
int word[N];
string str;
int n, tot, ans;
void insert()
{
    int u = 0;
    int len = str.length();
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        int a = str[i] - 'a';
        if (trie[u][a] == 0)    // 如果没有这个结点
            trie[u][a] = ++tot;
        u = trie[u][a]; // 跳到这个结点
        res += word[u];
    }
    word[u]++;
    if (res + 1 > ans) ans = res + 1;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> str;
        insert();
    }
    cout << ans;
    return 0;
}