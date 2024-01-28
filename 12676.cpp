#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 55;
vector<long long> deep[maxn];
int main()
{
    int n, x;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            deep[i].clear();
            int maxd = 0;
            for (int i = 0; i < n; i++)
            {
                cin >> x;
                deep[x].push_back(0);
                maxd = max(maxd, x);
            }
            long long temp = 1;
            for (int i = maxd; i > 0; i--)
            {
                for (int j = 0; j < deep[i].size(); j++)
            }
        }
    }
    return 0;
}