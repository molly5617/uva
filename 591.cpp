#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int times = 0;
    while (cin >> n)
    {
        times++;
        if (n == 0)
            break;
        vector<int> v;
        v.resize(n);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }
        sum = sum / n;
        int ans = 0;
        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++)
        {
            if (v[i] == sum)
                break;
            else
            {
                ans += sum - v[i];
            }
        }
        cout << "Set #" << times << endl;
        cout << "The minimum number of moves is " << ans << "." << endl;
    }
}