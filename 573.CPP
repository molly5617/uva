#include <iostream>
using namespace std;

int main()
{
    double h, u, d, f;
    while (cin >> h >> u >> d >> f)
    {
        if (h == 0 && u == 0 && d == 0 && f == 0)
            break;
        int day = 0;
        double climb = 0;
        while (true)
        {
            day++;
            climb += u;
            if (climb > h)
            {
                cout << "success on day " << day << endl;
                break;
            }

            climb -= d;
            if (climb < 0)
            {
                cout << "failure on day " << day << endl;
                break;
            }

            u = u * (100 - f) / 100;
            if (u < 0)
                u = 0;
        }
    }
    return 0;
}
