#include <bits/stdc++.h>
using namespace std;
int n;
string s1, s2;
string s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string add(string s1, string s2)
{
    string ans;
    int len1 = s1.length(), len2 = s2.length();
    int len = max(len1, len2);
    int carry = 0;
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum = carry;
        if (i < len1)
        {
            if (s1[len1-i-1] >= 'A' && s1[len1-i-1] <= 'Z')
                sum += s1[len1-i-1]-'A'+10;
            else
                sum += s1[len1-i-1]-'0';
        }
        if (i < len2)
        {
            if (s2[len2-i-1] >= 'A' && s2[len2-i-1] <= 'Z')
                sum += s2[len2-i-1]-'A'+10;
            else
                sum += s2[len2-i-1]-'0';
        }
        ans = s[sum%n] + ans;
        carry = sum / n;
    }
    if (carry) ans = s[carry] + ans;
    return ans;
}
int main()
{
    cin >> n;
    cin >> s1 >> s2;
    cout << add(s1, s2) << endl;
    return 0;
}