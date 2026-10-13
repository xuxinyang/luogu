#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6+5;
int b[N], len1, len2;
string s1, s2;
int main()
{
    cin >> s1 >> s2;
    len1 = s1.size(), len2 = s2.size();
    int j = 0;
    for (int i = 1; i < len2; i++)
    {
        while (j > 0 && s2[i] != s2[j]) // 失配
            j = b[j-1];
        if (s2[j] == s2[i]) j++;    // 匹配上了
        b[i] = j;
    }
    j = 0;
    for (int i = 0; i < len1; i++)
    {
        while (j > 0 && s1[i] != s2[j]) // 失配
            j = b[j-1];
        if (s2[j] == s1[i]) j++;
        if (j == len2) // 模式串都已经匹配完成
        {
            cout << (i+1) - len2 + 1 << "\n";
            j = b[j-1];
        }
    }
    for (int i = 0; i < len2; i++) cout << b[i] << " ";
    return 0;
}