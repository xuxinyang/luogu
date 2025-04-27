#include <bits/stdc++.h>
using namespace std;
queue<string> q;
map<string, string> mp;
string s, t;
string A(string x)
{
    for (int i = 0; i < 4; i++) swap(x[i], x[i+4]);
    return x;
}
string B(string x)
{
	char x1 = x[3], x2 = x[7];
	for (int i = 3; i >= 1; i--) x[i] = x[i-1], x[i+4] = x[i+4-1];
	x[0] = x1, x[4] = x2;
	return x;
}
string C(string x)
{
    char x1 = x[1], x2 = x[2], x3 = x[5], x4 = x[6];
    x[1] = x3, x[2] = x1, x[5] = x4, x[6] = x2; 
    return x;
}
int main()
{
    for (int i = 0; i < 8; i++)
    {
        char c;
        cin >> c;
        t += c;
        getchar();
    }
    swap(t[4], t[7]); swap(t[5], t[6]);
    // cout << t;
    q.push({"12348765"});
    mp["12348765"] = "";
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        // cout << mp[cur] << " ";
        if (cur == t)
        {
            cout << mp[cur].size() << "\n" << mp[cur];
            return 0; 
        }
        if (!mp.count(A(cur))) {string r = A(cur); mp[r] = mp[cur]+'A'; q.push(r);};
        if (!mp.count(B(cur))) {string r = B(cur); mp[r] = mp[cur]+'B'; q.push(r);};
        if (!mp.count(C(cur))) {string r = C(cur); mp[r] = mp[cur]+'C'; q.push(r);};
    }
    return 0;
}