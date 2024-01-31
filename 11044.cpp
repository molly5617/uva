#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        a = a - 2;
        b = b - 2;
        ans += a / 3;
        if (a % 3 != 0)
            ans++;
        int temp = 0;
        temp += b / 3;
        if (b % 3 != 0)
            temp++;
        cout << ans * temp << endl;
    }
}