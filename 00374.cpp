#include <iostream>
using namespace std;
int main()
{
    int b, p, m;
    while (cin >> b >> p >> m)
    {
        int ans = b % m;
        for (int i = 1; i < p; i++)
        {
            ans = (ans * (b % m)) % m;
        }
        cout << ans << endl;
    }
}