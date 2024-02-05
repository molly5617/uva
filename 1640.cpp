#include <iostream>
#include <string>
using namespace std;
#include <map>
int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        string line;
        map<int, int> mp;
        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        while (a % 10 != 0)
        {
            mp[a % 10]++;
            a++;
        }
        while (b % 10 != 0)
        {
            mp[b % 10]++;
            b++;
        }

        

        for (int c = 0; c <=9; c++)
        {
            if (c != 0)
            {
                cout << " " << mp[c];
            }
            else
                cout << mp[c];
        }
        cout << endl;
    }
}