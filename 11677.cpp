#include <iostream>
using namespace std;
int main()
{
    int h1, m1, h2, m2;
    while (cin >> h1 >> m1 >> h2 >> m2)
    {
        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
            break;
        int now[2];
        now[0] = h1;
        now[1] = m1;
        int ans = 0;
        while (now[1] != m2)
        {
            ans++;
            now[1]++;
            if (now[1] == 60)
            {
                now[1] = 0;
                now[0]++;
            }
        }
        if (now[0] == 24)
        {
            now[0] = 0;
        }
        while (now[0] != h2)
        {

            ans += 60;
            now[0]++;
            if (now[0] == 24)
                now[0] = 0;
        }
        cout << ans << endl;
    }
}