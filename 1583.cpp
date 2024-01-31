#include <iostream>
using namespace std;
#include <map>
int main()
{
    int n;
    cin >> n;
    int now = 0;
    map<int, int> mp;
    while (n--)
    {
        int t;
        cin >> t;

        int i;
        if (t < now)
        {
            for (int i = 0; i < mp.size(); i++)
            {
                if (mp[i] == t)
                {
                    cout << i << endl;
                    break;
                }
            }
            if (i == mp.size())
            {
                cout << "0" << endl;
            }
        }
        else
        {

            for (i = now; i <= t; i++)
            {
                mp[i] = i;
                int temp = i;
                while (temp)
                {
                    mp[i] += temp % 10;
                    temp /= 10;
                }
                if (mp[i] == t)
                {
                    cout << i << endl;
                    now = i;
                    break;
                }
            }
            if (i >= t)
            {
                cout << 0 << endl;
                now = i - 1;
            }
        }
    }
}