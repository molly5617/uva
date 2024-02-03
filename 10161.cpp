#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <map>
#include <math.h>
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        double ha = sqrt(n);

        int m;
        int now;
        m = floor(ha);
        /*int now = m * m;
        int x = m, y = m;
        m = m + 1;*/
        int x, y;
        bool flag = false;
        if (floor(ha) == ceil(ha) && n == ceil(ha) * ceil(ha))
        {
            flag = true;
            int temp = ha;
            if (temp % 2 == 0)
            {
                cout << temp << " " << 1 << endl;
            }
            else
            {
                cout << 1 << " " << temp << endl;
            }
        }

        if (m % 2 == 0)
        {
            m = m - 1;
            now = m * m;
            x = 1, y = m;
            m = m + 1;
        }
        else
        {
            now = m * m;
            x = 1, y = m;
            m = m + 1;
        }
       // cout << now << " " << m << " " << x << " " << y << endl;
        while (!flag)
        {
            while (y != m) // 上
            {
                if (now == n && !flag)
                {
                    cout << x << " " << y << endl;
                    flag = true;
                    break;
                }
                y++;
                now++;
            }
            while (x != m) // 右
            {
                if (now == n && !flag)
                {
                    cout << x << " " << y << endl;
                    flag = true;
                    break;
                }
                x++;
                now++;
            }
            while (y != 1) // 下
            {
                if (now == n && !flag)
                {
                    cout << x << " " << y << endl;
                    flag = true;
                    break;
                }
                y--;
                now++;
            }
            m++;
            while (x != m) // 右
            {
                if (now == n && !flag)
                {
                    cout << x << " " << y << endl;
                    flag = true;
                    break;
                }
                x++;
                now++;
            }
            while (y != m) // 上
            {
                if (now == n && !flag)
                {
                    cout << x << " " << y << endl;
                    flag = true;
                    break;
                }
                y++;
                now++;
            }
            while (x != 1) // 下
            {
                if (now == n && !flag)
                {
                    cout << x << " " << y << endl;
                    flag = true;
                    break;
                }
                x--;
                now++;
            }

            m++;
        }
    }
}