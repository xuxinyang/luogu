#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll x) {
    if (x == 0) return 0;
    vector<int> bits;
    while (x) {
        bits.push_back(x & 1);
        x >>= 1;
    }
    reverse(bits.begin(), bits.end());
    int n = bits.size();

    ll dp[35][2][2] = {};   // 数字和
    ll cnt[35][2][2] = {};  // 数量

    cnt[0][0][1] = 1; // 初始：0位，奇偶0，tight=1

    for (int pos = 0; pos < n; ++pos) {
        for (int mod = 0; mod < 2; ++mod) {
            for (int tight = 0; tight < 2; ++tight) {
                if (cnt[pos][mod][tight] == 0) continue;

                int limit = tight ? bits[pos] : 1;

                for (int d = 0; d <= limit; ++d) {
                    int nextMod = mod ^ d;
                    int nextTight = (tight && d == limit) ? 1 : 0;

                    cnt[pos + 1][nextMod][nextTight] += cnt[pos][mod][tight];
                    dp[pos + 1][nextMod][nextTight] += dp[pos][mod][tight] + d * (1LL << (n - pos - 1)) * cnt[pos][mod][tight];
                }
            }
        }
    }

    return dp[n][1][0] + dp[n][1][1]; // 奇数个1的数字和
}

int main() {
    ll l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << "\n";
}
