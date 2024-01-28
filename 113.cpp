#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b;

    while (cin >> a >> b)
    {
        int ans = round(pow(b, 1.0 / a));
        cout << ans << endl;
    }

    return 0;
}
