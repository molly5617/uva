#include <iostream>
using namespace std;
#include <math.h>
#include <vector>
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int target;
        cin >> target;
        int p;
        cin >> p;
        vector<int> dp(target + 1, 0);
        vector<int> nums(p);
        for (int i = 0; i < p; i++)
        {
            cin >> nums[i];
        }
        for (int i = 0; i < p; i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target)
        {
            cout << "YES" << endl;
        }
        else
        {

            cout << "NO" << endl;
        }
    }
}