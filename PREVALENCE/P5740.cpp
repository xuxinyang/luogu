#include <bits/stdc++.h>
using namespace std;
struct Stu
{
    string name;
    int chinese, math, english, sum;
    int id;
};
int n;
Stu stus[1005];
bool cmp(Stu x, Stu y)
{
    if (x.sum == y.sum) return x.id < y.id;
    else return x.sum > y.sum;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> stus[i].name >> stus[i].chinese >> stus[i].math >> stus[i].english;
        stus[i].sum = stus[i].chinese + stus[i].math + stus[i].english;
        stus[i].id = i;
    }   
    sort(stus + 1, stus + n + 1, cmp);
    cout << stus[1].name << " " << stus[1].chinese << " "
         << stus[1].math << " " << stus[1].english;
    return 0;
}