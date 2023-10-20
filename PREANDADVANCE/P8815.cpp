#include <bits/stdc++.h>
using namespace std;
string s;
bool val;
int cntand, cntor, pass;
int main()
{
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (pass)
        {
            if (s[i] == '(')
            {
                int cnt = 1;
                while (cnt)
                {
                    i++;
                    if (s[i] == '(') cnt++;
                    if (s[i] == ')') cnt--;
                }
            }
            else if ((pass == 1 && s[i] == '|') || s[i] == ')') pass = 0;
            else if (pass == 1 && s[i] == '&') cntand++;
            else if (pass == 2 && s[i] == '|') cntor++;
        }
        else
        {
            if (s[i] == '1') val = 1;
            else if (s[i] == '0') val = 0;
            else if (s[i] == '&' && val == 0) pass = 1, cntand++;
            else if (s[i] == '|' && val == 1) pass = 2, cntor++;  
        }
    }
    cout << val << "\n";
    cout << cntand << " " << cntor;
    return 0;
}