#include <iostream>
using namespace std;

int main()
{
    long long int k[1501];
    k[0] = 1;
    int t2 = 0, t3 = 0, t5 = 0;
    int i;

    for (i = 1; i < 1500; i++)
    {
        k[i] = min(k[t2] * 2, min(k[t3] * 3, k[t5] * 5));

        if (k[i] == k[t2] * 2)
            t2++;
        if (k[i] == k[t3] * 3)
            t3++;
        if (k[i] == k[t5] * 5)
            t5++;
    }
    cout << "The 1500'th ugly number is " << k[i - 1] << "." << endl;
}
