#include <iostream>
using namespace std;
#include <vector>
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int k, w;
        cin >> k;
        cin >> w;
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
            for (int s = 0; s < k; s++)
            {
                if (v[i - 1][s] == v[i][j])
                {
                    j++;
                }
            }
            ans += k - j;
        }
        cout << ans << endl;
    }
}