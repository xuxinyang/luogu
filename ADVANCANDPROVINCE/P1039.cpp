#include <bits/stdc++.h>
using namespace std;
map<string, int> per;
string name[25];
map<string, int> day;
struct Sta
{
    int u;
    bool to;
    bool is;
    Sta(int u, bool to, bool is)
    {
        this -> u = u;
        this -> to = to;
        this -> is = is;
    }
    Sta(){}
};
vector<Sta> v[25];
char unuse[1005];
int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        per[s] = i, name[i] = s;
    }
    per["Today"] = n+1;
    day["Monday."] = 1, day["Tuesday."] = 2;
    day["Wednesday."] = 3, day["Thursday."] = 4;
    day["Friday."] = 5, day["Saturday."] = 6;
    day["Sunday."] = 7;
    for (int i = 1; i <= p; i++)
    {
        cin >> s;
        s = s.substr(0, s.size()-1);
        int t = per[s];
        cin >> s;
        int u = per[s];
        if (u <= n)
        {
            cin >> s;
            if ((u&&s!="is") || (!u&&s!="am"))
            {
                gets(unuse);
                continue;
            }
            if (!u) u = t;
            cin >> s;
            if (s == "not")
            {
                cin >> s;
                if (s == "guilty.") v[t].push_back(Sta(u, 0, 0));
            }
            else if (s == "guilty.") v[t].push_back(Sta(u, 0, 1));
        }
        else if (u == n+1)
        {
            cin >> s;
            if (s != "is") continue;
            cin >> s;
            if (day[s]) v[t].push_back(Sta(day[s], 1, 1));
        }
        else gets(unuse);
    }
    string ans = "";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            int flag = 0, cnt = n, ran = 0;
            for (int k = 1; !flag&&k<=n; k++)
            {
                vector<Sta>::iterator it = v[k].begin();
                if (!v[k].size())
                {
                    ++ran;
                    continue;
                }
                Sta tmp = *it;
                bool rea;
                if (tmp.to) rea = (tmp.u == j);
                else rea = ((tmp.u==i)^(!tmp.is));
                ++it;
                for (; !flag && it != v[k].end(); ++it)
                {
                    if (it -> to)
                    {
                        if (rea != (it->u==j)) flag = 1;
                    }
                    else
                    {
                        if (rea == ((it->u==i)^it->is)) flag = 1;
                    }
                }
                cnt -= rea;
            }
            if (!flag && cnt >= m && cnt-ran <= m)
            {
                if (ans == "") ans=name[i];
                else if (ans != name[i])
                {
                    cout << "Cannot Determine" << endl;
                    return 0;
                }
            }
        }
    }
    if (ans == "") cout << "Impossible" << endl;
    else cout << ans << endl;
    return 0;
}