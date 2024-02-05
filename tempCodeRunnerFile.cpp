#include <iostream>
#include <string>
using namespace std;
#include <map>
int main()
{
    int a, b;
    while (cin >> a >> b && a)
    {
        string line;
        map<char, int> mp;
        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        for (int i = a; i <= b; i++)
        {
            line = to_string(i);
            for (int i = 0; i < line.length(); i++)
            {
                mp[line[i]]++;
            }
        }

        for (char c = '0'; c <= '9'; c++)
        {
            if (c != '0')
            {
                cout << " " << mp[c];
            }
            else
                cout << mp[c];
        }
        cout << endl;
    }
}