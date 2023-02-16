#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> ump;
char c, a[100];
string s, name;
int ans = 0;
int main()
{
    while (c = getchar() && c != EOF)
    {
        memset(a, '\0', sizeof(a));
        if (c == '+') s = gets(a), ump[s] = 1;
        else if (c == '-') s = gets(a), ump.erase(s);
        else
        {
            while (c = getchar() && c != ':');
            getchar();
            s = gets(a);
            ans += s.length() * ump.size();
            cout << s << endl;
        }
    }
    cout << ans << endl;
    return 0;
}