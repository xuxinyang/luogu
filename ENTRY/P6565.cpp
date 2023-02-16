#include <bits/stdc++.h>
using namespace std;
int n, res;
string sign, name;
string best_name;
unordered_map<string, pair<string, int> > ump;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        cin >> name >> sign;
        if (sign.length() < 3)
        {
            ump[name] = make_pair(sign, tmp);
            continue;
        }
        for (int j = 0; j < sign.length()-2; j++)
            if (sign[j] == 's' && sign[j+1] == 'o' && sign[j+2] == 's') tmp++;
        ump[name] = make_pair(sign, tmp);
        if (tmp > res) res = tmp;
    }
    for (auto it = ump.begin(); it != ump.end(); it++)
    {
        if ((it -> second).second == res) cout << it -> first << " ";
    }
    cout << "\n" << res << endl;
    return 0;
}