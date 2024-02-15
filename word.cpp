#include <iostream>
using namespace std;
<<<<<<< HEAD
#include <string>
int main()
{
    string name = "0123456789";
    cout << name.substr(2, 3);
}
=======
#include <vector>
#include <set>
#include <map>
map<long long int, long long int> dp;
#define LLONG_MAX 9223372036854775807i64

int main()
{
    long long int low, high, pre = 600;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 0;
    dp[4] = 0;
    dp[5] = 1;
    for (long long int i = 6; i <= 600; i++)
    {
        long long int num = 0;
        long long int now = i;
        if (now % 5 == 0)
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
            dp[i] = dp[i - 1];
    }

    while (cin >> low >> high && low)
    {

        set<long long int> ans;
        if (low > pre)
        {
            for (long long int i = pre + 1; i <= high; i++)
            {
                long long int num = 0;
                long long int now = i;
                if (now % 5 == 0)
                {
                    dp[i] = dp[i - 1] + 1;
                }
                else
                    dp[i] = dp[i - 1];
            }
            pre = high;
        }

        long long int temp = 0;
        ans.insert(temp);
        for (long long int i = low; i <= high; i++)
        {
            if (dp[i] != 0)
                ans.insert(dp[i]);
            else
            {
                long long int now = i;

                if (now % 5 == 0)
                {
                    dp[i] = dp[i - 1] + 1;
                }
                else
                    dp[i] = dp[i - 1];
                ans.insert(dp[i]);
            }
        }

        cout << ans.size() << endl;
    }
}
>>>>>>> e791acea9dedabead4a5de7be7bd47c3c81f797f
