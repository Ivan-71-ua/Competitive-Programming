#include <iostream>
using namespace std;
int main()
{
    int n;
    double x, a, p;
    cin >> n >> x >> p;
    while(n--)
    {
        cin >> a;
        p = p * x + a;
    }
    cout << p;
    return 0;
}