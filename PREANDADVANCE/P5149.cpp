#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
const int maxz = 26 << 1;
ll ans;
int trie[maxn<<3][maxz], cnt[maxn<<3], n, tot = 1;
int res[maxn], tmp[maxn];
char s[10];
void merge_sort(int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (res[i] <= res[j]) tmp[k++] = res[i++];
        else tmp[k++] = res[j++], ans += mid - i + 1;
    }
    while (i <= mid) tmp[k++] = res[i++];
    while (j <= r) tmp[k++] = res[j++];
    for (int t = l; t <= r; t++) res[t] = tmp[t];
}
void insert(char s[], int idx)
{
    int p = 1, len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        int ch = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] - 'A' : s[i] - 'a' + 26;
        if (!trie[p][ch]) trie[p][ch] = ++tot;
        p = trie[p][ch];
    }
    cnt[p] = idx;
}
void query(char s[], int idx)
{
    int p = 1, len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        int ch = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] - 'A' : s[i] - 'a' + 26;
        p = trie[p][ch];
    }
    res[idx] = cnt[p];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        insert(s, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        query(s, i);
    }
    merge_sort(1, n);
    cout << ans << endl;
    return 0;
}