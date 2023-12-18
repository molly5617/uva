#include <iostream>
using namespace std;
long long int findGCD(long long int a, long long int b)
{

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    long long int n, m;
    while (cin >> n >> m)
    {
        long long ans = 1;
        long long int up = 1, down = 1;
        long long int save = 1;
        if (n == 0 && m == 0)
        {
            break;
        }
        for (int i = n, j = m; j > 0; i--, j--)
        {
            ans *= i;
            down *= j;
            long long int gcd = findGCD(ans, down);
            ans = ans / gcd;
            // cout << "ans: " << ans << endl;
            down /= gcd;

            // cout << i << " " << j << endl;
        }

        cout << n << " things taken " << m << " at a time is " << ans << " exactly." << endl;
    }
}