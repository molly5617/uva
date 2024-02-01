#include <iostream>
#include <vector>
using namespace std;

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
            string a;
            cin >> a;
            v.push_back(a);
        }

        int ans = k;
        for (int i = 1; i < w; i++)
        {
            int j = 0;
            bool flag = false;
            int position = 0;

            int s = 0;
            while (s < k - 1)
            {
                if (v[i - 1][s] == v[i][j])
                {
                    j++;
                    if (!flag)
                    {
                        position = s;
                    }
                    flag = true;
                }
                else
                {
                    s = position;
                    flag = false;
                    j = 0;
                }
                s++;
            }

            ans += k - j;
        }

        cout << ans << endl;
    }

    return 0;
}
