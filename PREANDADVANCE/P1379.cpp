#include <bits/stdc++.h>
using namespace std;
string target = "123804765", s;
const int gx[9] = {1, 0, 0, 0, 1, 2, 2, 2, 1};
const int gy[9] = {1, 0, 1, 2, 2, 2, 1, 0, 0};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
unordered_map<string, int> ump;
priority_queue<pair<int, string>, vector<pair<int, string>> , greater<pair<int, string>> > pq;
int f(string s)
{
    int res = 0;
    for (int i = 0; i < 9; i++)
    {
        int t = s[i] - '0';
        if (t) res += abs(i/3-gx[t]) + abs(i%3-gy[t]);
    }
    return res;
}
int ans;
int Astar(string start)
{
    pq.push({f(start), start});
    ump[start] = 0;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        string str = cur.second;
        if (str == target) return ump[str];
        int p = str.find('0');
        int x = p / 3, y = p % 3;
        for (int i = 0; i < 4; i++)
        {
            int fx = x + dx[i], fy = y + dy[i];
            if (fx >= 0 && fx < 3 && fy >= 0 && fy < 3)
            {
                string t = str;
                swap(t[p], t[fx*3+fy]);
                if (!ump.count(t))
                {
                    ump[t] = ump[str] + 1;
                    pq.push({ump[t] + f(t), t});
                }
            }
        }
    }
    return -1;
}
int main()
{
    cin >> s;
    ans = Astar(s);
    cout << ans;
    return 0;
}