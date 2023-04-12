#include <iostream>
using namespace std;
int main()
{
    int a[15], x, cnt = 0;
    for (int i = 1; i <= 10; i++) cin >> a[i];
    cin >> x;
    x += 30;
    for (int i = 1; i <= 10; i++)
    {
        if (x >= a[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}