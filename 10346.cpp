#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        int ans = 0;
        int bottom = n;
        ans = n;
        while (bottom >= k)
        {
            ans += bottom / k;
            bottom = bottom % k + bottom / k;
        }
        cout << ans << endl;
    }
}