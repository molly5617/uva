#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        int len = a.length();
        int pos = 0;
        for (int i = 0; i < b.length(); i++)
        {
            if (a[pos] == b[i])
            {
                len--;
                pos++;
            }
        }
        if (len == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}