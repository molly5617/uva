#include <iostream>
#include <map>
using namespace std;
#include <string>
int main()
{
    string a, b;

    while (getline(cin, a))
    {

        getline(cin, b);
        map<char, int> haya, hayb;
        if (a == "" || b == "")
        {
            cout << endl;
            continue;
        }
        for (int i = 0; i < a.length(); i++)
        {
            haya[a[i]]++;
        }
        for (int i = 0; i < b.length(); i++)
        {
            hayb[b[i]]++;
        }
        for (char i = 'a'; i <= 'z'; i++)
        {
            while (haya[i] != 0 && hayb[i] != 0)
            {
                cout << i;
                haya[i]--;
                hayb[i]--;
            }
        }
        cout << endl;
    }
}