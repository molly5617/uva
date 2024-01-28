#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int p;
        cin >> p;
        vector<int> v(p);
        for (int i = 0; i < p; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        int sum = 0;
        if (p % 3 == 0)
        {
            for (int i = 0; i < p; i += 3)
            {
                sum += v[i];
            }
        }
        else if (p % 3 == 1)
        {
            for (int i = 1; i < p; i += 3)
            {
                sum += v[i];
            }
        }
        else
        {
            for (int i = 2; i < p; i += 3)
            {
                sum += v[i];
            }
        }
        cout << sum << endl;
    }
}
