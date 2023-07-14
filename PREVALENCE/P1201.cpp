#include <bits/stdc++.h>
using namespace std;
int n, m, g;
unordered_map<string, pair<int, int> >ump;
string names[15];
string name;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> name;
		names[i] = name;
        ump[name] = make_pair(0, 0);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> name;
        cin >> m >> g;
		if (g == 0) continue;
        ump[name].first = m / g * g;
        for (int j = 1; j <= g; j++)
        {
            cin >> name;
            ump[name].second += m / g;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << names[i] << " " << ump[names[i]].second - ump[names[i]].first << "\n";
    }
    return 0;
}
