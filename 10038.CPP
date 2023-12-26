#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        bool ans = true;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> dif(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            dif[i] = abs(v[i] - v[i + 1]);
        }
        sort(dif.begin(), dif.end());
        for (int i = 1; i <= n - 1; i++)
        {
            if (dif[i - 1] != i)
            {
                ans = false;
                break;
            }
        }
        if (ans)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
}