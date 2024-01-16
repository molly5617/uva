#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int i;
        vector<int> v1(n), v2(n);
        for (i = 0; i < n; i++)
        {
            cin >> v1[i] >> v2[i];
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        for (i = 0; i < n; i++)
        {
            if (v1[i] != v2[i])
                break;
        }
        if (i == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
