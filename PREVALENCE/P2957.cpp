#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int ans1, ans2;
int main()
{
    cin >> s1 >> s2;
    for (int j = 0; j < s2.length(); j++)
    {
        int i = 0, tmp = 0;
        while (s1[i] == s2[j] && j < s2.length() && i < s1.length())
        {
            i++;
            j++;
            tmp++;
        }
        if (j == s2.length()) ans1 = max(ans1, tmp);
    }
    for (int j = 0; j < s1.length(); j++)
    {
        int i = 0, tmp = 0;
        while (s2[i] == s1[j] && i < s2.length() && j < s1.length())
        {
            i++;
            j++;
            tmp++;
        }
        if (j == s1.length()) ans2 = max(ans2, tmp);
    }
    cout << max(ans1, ans2);
    return 0;
}