#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
    int n, q;
    int time = 1;
    while (cin >> n >> q)
    {
        if (n == 0 && q == 0)
            break;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        cout << "CASE# " << time << ":" << endl;
        sort(v.begin(), v.end());
        int k;
        for (int i = 0; i < q; i++)
        {
            cin >> k;
            int j;

            for (j = 0; j < v.size(); j++)
            {
                if (v[j] == k)
                {

                    cout << k << " found at " << (j + 1) << endl;
                    break;
                }
            }
            if (j == v.size())
            {
                cout << k << " not found " << endl;
            }
        }
        time++;
    }
}