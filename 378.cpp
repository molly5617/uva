#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int n;
    while (n--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        double a1, a2;
        double b1, b2;
        a1 = (y2 - y1) / (x2 - x1);
        a2 = (y4 - y3) / (x4 - x3);
        b1 = y1 - a1 * x1;
        b2 = y3 - a2 * x3;
        if (a1 / a2 == b1 / b2)
        {
            cout << "LINE " << endl;
        }
    }
    cout << "END OF OUTPUT";
}