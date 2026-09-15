#include <bits/stdc++.h>
using namespace std;

int main()
{
    double t1, v, t2;
    cin >> t1 >> v >> t2;
    if (t1 > 1000/v+t2) cout << "rabbit";
    else if (t1 < 1000/v+t2) cout << "turtle";
    else cout << "tie";
    printf("\n%.2lf", t2+1000/v);
    return 0;
}