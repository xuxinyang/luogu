#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<string, ll> size = {
    {"byte", 1}, {"short", 2}, {"int", 4}, {"long", 8}
};
vector<tuple<ll, ll, string>> vars;
map<string, ll> address;
ll tail;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 2)
        {
            string t, s;
            cin >> t >> s;
            ll z = size[t];
            tail = (tail + z - 1) / z * z;
            address[s] = tail;
            vars.emplace_back(tail, tail + z, s);
            cout << tail << "\n";
            tail += z;
        }
        else if (op == 3)
        {
            string s;
            cin >> s;
            cout << address[s] << "\n";
        }
        else if (op == 4)
        {
            ll x;
            cin >> x;
            string answear = "ERR";
            for (auto v : vars)
            {
                if (get<0>(v) <= x && x < get<1>(v))
                    answear = get<2>(v);
            }
            cout << answear << "\n";
        }
    }
    return 0;
}