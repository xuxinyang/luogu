#include <bits/stdc++.h>
using namespace std;
string s, ans;
int hex2oct(string num)
{
    int sum = 0;
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] >= 'A') sum += ((num[i]-'A')+10) * pow(16, num.length()-i-1);
        else sum += (num[i]-'0') * pow(16, num.length()-i-1);
    }
    return sum;
}
string oct2hex(int num)
{
    if (num == 0) return "00";
    string res = "";
    while (num)
    {
        int k = num % 16;
        if (k >= 10) res = char('A'+k-10) + res;
        else res = char('0' + k) + res;
        num /= 16;
    }
    if (res.length() == 1) return "0" + res;
    return res;
}
int main()
{
    cin >> s;
    ans = "#";
    ans += oct2hex(255-hex2oct(s.substr(1, 2)));
    ans += oct2hex(255-hex2oct(s.substr(3, 2)));
    ans += oct2hex(255-hex2oct(s.substr(5, 2)));
    cout << ans;
    return 0;
}