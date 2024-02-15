#include <iostream>
using namespace std;

int sumfactor(int x)
{
    int ans = 0;
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
            ans += i;
    }
    return ans;
}

int main()
{
    int times = 0;
    int n;

    while (cin >> n && n)
    {
        times++;
        bool flag = false;

        if (n == 1)
            cout << "Case " << times << ": " << 1 << endl;
        else if (n == 2)
            cout << "Case " << times << ": " << -1 << endl;
        else
        {
            int i;
            int max = -1;
            for (i = 1; i < n; i++)
            {
                if (sumfactor(i) == n)
                {
                    if (i > max)
                        max = i;

                    flag = true;
                }
            }
            if (!flag)
            {
                cout << "Case " << times << ": " << -1 << endl;
            }
            else
            {
                cout << "Case " << times << ": " << max << endl;
            }
        }
    }

    return 0;
}
