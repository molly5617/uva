#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int j, r;
    while (cin >> j >> r)
    {
        if (j == 0 && r == 0)
            break;
        vector<vector<int>> v(r, vector<int>(j, 0));
        int ans = 0;
        int score = 0;
        for (int i = 0; i < r; i++)
        {
            for (int k = 0; k < j; k++)
            {
                cin >> v[i][k];
            }
        }
        cout << ans << endl;
    }
}