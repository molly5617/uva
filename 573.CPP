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
        f = u * f / 100;
        while (true)
        {

            // cout << climb << " ";
            day++;
            climb += u;
            if (climb > h)
            {
                cout << "success on day " << day << endl;
                break;
            }
            // cout << u << " " << climb << " ";
            climb -= d;
            // cout << climb << " " << endl;
            if (climb < 0)
            {
                cout << "failure on day " << day << endl;
                break;
            }

            if (u > f)
                u -= f;
            else
                u = 0;
        }
    }
    return 0;
}
