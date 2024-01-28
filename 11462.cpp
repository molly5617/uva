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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
    }
}