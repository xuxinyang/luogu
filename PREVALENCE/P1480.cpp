#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s1, s2;
ll b, sum;
int main()
{
    cin >> s1 >> b;
    for (int i = 0; i < s1.length(); i++) s1[i] -= 48;
    for (int i = 0; i < s1.length(); i++)
    {
        s2.push_back((sum*10+s1[i])/b + 48);
        sum = (sum * 10 + s1[i]) % b;
    } 
    for (int i = 0; s2[0]==48; i++)
        s2.erase(s2.begin(), s2.begin()+1);
    if (s2 == "") cout << 0;
    else cout << s2;
    return 0;
}