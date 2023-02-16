#include <bits/stdc++.h>
using namespace std;

int main()
{
    int flow = 0, now = 0;
    string s;
    while (getline(cin, s))
    {
        if (s[0] == '+') now++;
        else if (s[0] == '-') now--;
        else
        { 
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ':')
                {                                     // 找到啦！
                    flow += (s.size() - i - 1) * now; // 将流量数加上消息的字节数×目前聊天中的人数
                    break;                            // 并退出循环
                }
            }
        }
    }

    cout << flow;
    return 0;
}