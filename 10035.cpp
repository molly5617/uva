#include <iostream>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;
        int carry = 0;
        int ans = 0;
        while (a > 0 && b > 0)
        {
            int c = a % 10;
            int d = b % 10;
            ans += (c + d + carry) / 10;
            carry = (c + d + carry) / 10;
            a = a / 10;
            b = b / 10;
        }
        while (a != 0)
        {
            int c = a % 10;
            ans += (c + carry) / 10;
            carry = (c + carry) / 10;
            a = a / 10;
        }
        while (b != 0)
        {
            int c = b % 10;
            ans += (c + carry) / 10;
            carry = (c + carry) / 10;
            b = b / 10;
        }
        if (!ans)
            cout << "No carry operation." << endl;
        else if (ans == 1)
            cout << "1 carry operation." << endl;
        else
            cout << ans << " carry operations." << endl;
    }
}