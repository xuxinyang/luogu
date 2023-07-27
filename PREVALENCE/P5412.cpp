#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
struct Student
{
    int gender;
    double height;
};
int t, n, girls;
Student stus[maxn]; 
bool cmp(Student x, Student y)
{
    return x.gender < y.gender;
}
bool cmp1(Student x, Student y)
{
    return x.height < y.height;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> stus[i].gender;
            if (stus[i].gender == 0) girls++;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> stus[i].height;
        }
        sort(stus + 1, stus + n + 1, cmp);
        sort(stus + 1, stus + girls + 1, cmp1);
        sort(stus + girls + 1, stus + n + 1, cmp1);
        for (int i = 1; i <= girls; i++) cout << stus[i].height << " ";
        cout << "\n";
        for (int i = girls + 1; i <= n; i++) cout << stus[i].height << " ";
        cout << "\n";
    }
    return 0;
}