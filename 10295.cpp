#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    map<string, int> hay;
    string s;
    while (m--)
    {
        int p;
        cin >> s >> p;
        hay[s] = p;
    }
    while (n--)
    {
        int ans = 0;
        while (cin >> s && s != ".")
        {
            ans += hay[s];
        }
        cout << ans << endl;
    }
}