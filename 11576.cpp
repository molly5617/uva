#include <iostream>
#include <string>
using namespace std;
#include <vector>
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int k, w;
        cin >> k >> w;
        vector<string> v;
        for (int i = 0; i < w; i++)
        {
            string str;
            cin >> str;
            v.push_back(str);
        }
        int ans = k;
        bool flag = false;
        for (int i = 1; i < w; i++)
        {
            flag = false;

            for (int j = 0; j < k && !flag; j++)
            {
                string first = v[i - 1].substr(j);
                string second = v[i].substr(0, k - j);
                if (first == second)
                {
                    ans += j;
                    flag = true;
                }
            }
            if (!flag)
                ans += k;
        }
        cout << ans << endl;
    }
}