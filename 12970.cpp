#include <iostream>
using namespace std;

long long int GCD(long long int num1, long long int num2)
{
    if (num2 == 0)
    {
        return num1;
    }

    return GCD(num2, num1 % num2);
}

long long int LCM(long long int num1, long long int num2)
{
    return ((num1 * num2) / GCD(num1, num2));
}

int main()
{
    long long int v1, d1, v2, d2;
    long long int times = 0;

    while (cin >> v1 >> d1 >> v2 >> d2)
    {
        if (!v1 && !d1 && !v2 && !d2)
            break;

        times++;
        cout << "Case #" << times << ": ";
        double beer = (double)d1 / v1;
        double nobeer = (double)d2 / v2;

        if (beer > nobeer)
        {
            cout << "No beer for the captain." << endl;
        }
        else
        {
            cout << "You owe me a beer!" << endl;
        }

        cout << "Avg. arrival time: ";

        long long int gcd = GCD(d1, v1);
        d1 = d1 / gcd;
        v1 = v1 / gcd;
        gcd = GCD(d2, v2);
        d2 = d2 / gcd;
        v2 = v2 / gcd;
        long long int lcm = LCM(v1, v2);

        long long int up = d1 * (lcm / v1) + d2 * (lcm / v2);
        long long int down = lcm * 2;

        gcd = GCD(up, down);
        up /= gcd;
        down /= gcd;

        if (down == 1)
        {
            cout << up << endl;
        }
        else
        {
            cout << up << "/" << down << endl;
        }
    }

    return 0;
}
