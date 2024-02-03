#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <map>
int main()
{
    char c;
    map<char, int> mp;
    string str;
    for (c = '0'; c <= '9'; c++)
    {
        mp[c] = c - '0';
    }
    for (c = 'A'; c <= 'Z'; c++)
    {
        mp[c] = c - 'A' + 10;
    }
    for (c = 'a'; c <= 'z'; c++)
    {
        mp[c] = c - 'a' + 36;
    }

    while (cin >> str)
    {
        int ans = mp[str[0]];
        for (char z : str)
        {
            if (mp[z] > ans)
            {
                ans = mp[z];
            }
        }

        int i;
        if (ans == 'z')
        {
            cout << "such number is impossible!" << endl;
            continue;
        }
        else
        {
            i = max(ans + 1, 2);
            for (; i <= 62; i++)
            {
                long long int temp = 0;
                for (char z : str)
                {
                    temp = (temp * i + mp[z]);
                    temp = temp % (i - 1);
                }

                if (temp == 0)
                {
                    cout << i << endl;
                    break;
                }
            }

            if (i > 62)
            {
                cout << "such number is impossible!" << endl;
            }
        }
    }
}