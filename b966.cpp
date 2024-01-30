#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin(), v.end(), [](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });

    vector<vector<int>> ans;
    ans.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        if (ans.back()[1] >= v[i][0])
        {
            ans.back()[1] = max(ans.back()[1], v[i][1]);
        }
        else
            ans.push_back(v[i]);
    }
    int result = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        result += ans[i][1] - ans[i][0];
    }
    cout << result << endl;
}