#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        map<string, int> ans;
        string a;
        cin >> a;
        int maxCount = 0;

        for (int i = 0; i <= a.length() - n; i++)
        {
            string temp;
            for (int j = i; j < i + n; j++)
            {
                temp += a[j];
            }
            ans[temp]++;
            maxCount = max(maxCount, ans[temp]);
        }

        for (auto it = ans.begin(); it != ans.end(); ++it)
        {
            if (it->second == maxCount)
                cout << it->first << endl;
        }
    }

    return 0;
}
