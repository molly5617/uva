#include <iostream>
using namespace std;
int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        int a;
        int b;
        a = m - 1 + (n - 1) * m;
        b = n - 1 + n * (m - 1);
        int ans = min(a, b);
        cout << ans << endl;
    }
}