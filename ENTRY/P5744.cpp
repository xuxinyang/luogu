#include <bits/stdc++.h>
using namespace std;
int n;
struct Stu
{
    string name;
    int age, score;
};
Stu stus[10];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> stus[i].name >> stus[i].age >> stus[i].score;
        stus[i].age += 1;
        if (stus[i].score * 1.2 > 600) stus[i].score = 600;
        else stus[i].score *= 1.2; 
    }
    for (int i = 1; i <= n; i++)
    {
        cout << stus[i].name << " " << stus[i].age << " " << stus[i].score << "\n";
    }
    return 0;
}