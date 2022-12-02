#include <bits/stdc++.h>
using namespace std;
bool ul[1005];
string key, encode, decode;
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
    cin >> key >> encode;
    while (key.size() < encode.size()) key += key;
    for (int i = 0; i < encode.size(); i++)
    {
        if (isupper(encode[i])) ul[i] = 1;
    }
    for (int i = 0; i < encode.size(); i++)
    {
        decode += alpha[(toupper(encode[i])-'A'+26 - (toupper(key[i])-'A'))%26];
    }
    for (int i = 0; i < decode.size(); i++)
    {
        if (ul[i] == 1) cout << decode[i];
        else cout << char(decode[i]+32);
    }
    return 0;
}