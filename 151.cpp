#include <iostream>
using namespace std;
bool find(int n, int m)
{
    int crisis[100], last, cnt, i, k;
    for (int i = 0; i < 100; i++)
    {
        crisis[i] = 0;
    }
    for (i = 1, k = m, cnt = 0; cnt < n;)
    {
        if (!crisis[i] && i <= n)
        {
            if (k == m)
            {
                last = i;
                cnt++;
                k = 1;
                crisis[i] = 1;
                // cout << k << " ";
            }
            else
            {
                i++;
                k++;
                        }
        }

        else
        {
            i++;
            if (i > n)
                i = 1;
        }
    }
    if (last == 13)
        return true;
    return false;
}
int main()
{
    int n, m;
    while (cin >> n && n != 0)
    {
        for (m = 1;; m++)
            if (find(n, m))
            {
                cout << m << endl;
                break;
            }
    }
    return 0;
}