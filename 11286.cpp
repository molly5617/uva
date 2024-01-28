#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;

        map<string, int> ans;
        vector<int> v(5);
        int maxCount = 0;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < 5; j++)
                cin >> v[j];

            sort(v.begin(), v.end());

            string temp;
            for (int j = 0; j < 5; j++)
                temp += to_string(v[j]);

            ans[temp]++;
            maxCount = max(maxCount, ans[temp]);
        }

        int total = 0;

        for (auto it = ans.begin(); it != ans.end(); ++it)
        {
            if (it->second == maxCount)
                total += it->second;
        }

        cout << total << endl;
    }

    return 0;
}
