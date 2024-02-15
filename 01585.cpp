#include <iostream>
using namespace std;
#include <string>
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        string s;
        cin >> s;
        int ans = 0;
        int temp = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'O')
            {
                temp++;
            }
            else if (s[i] == 'X')
            {
                temp = 0;
            }
            ans += temp;
        }
        cout << ans << endl;
    }
}
