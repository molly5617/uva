#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        map<int, int> ans;
        for (int i = 0; i < n + m; i++)
        {
            int temp;
            cin >> temp;
            ans[temp]++;
        }
        int total = 0;
        for (auto it = ans.begin(); it != ans.end(); ++it)
        {
            if (it->second == 2)
            {
                total++;
            }
        }
        cout << total << endl;
    }
}