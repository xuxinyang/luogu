#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
string words[maxn];
int ans = 0;
int main()
{
    int p = 0;
    while (cin >> words[++p]);
    sort(words + 1, words + p + 1);
    ans += words[1].length();
    for (int i = 2; i <= p; i++)
    {
        int j = 0;
        while (words[i][j] == words[i-1][j] && j < words[i-1].length()) j++;
        ans += words[i].length() - j;
    }
    cout << ans + 1;
    return 0;
}