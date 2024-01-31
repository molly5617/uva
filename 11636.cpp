#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int n;
    int times = 0;
    while (cin >> n)
    {
        if (n < 0)
            break;
        ++times;
        cout << "Case " << times << ": ";
        double log2Result = log2(n);
        int roundedResult = static_cast<int>(std::ceil(log2Result));
        cout << roundedResult << endl;
    }
}