#include <iostream>
using namespace std;
int main()
{
    long long int n;
    while (cin >> n)
    {
        int ans = 1, rd = 1;
        while (rd % n)
        {
            ans++;
            rd = (rd * 10 + 1) % n;
        }
        cout << ans << endl;
    }
}