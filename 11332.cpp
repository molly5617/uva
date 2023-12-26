#include <iostream>
using namespace std;
int main()
{
    int n;

    while (cin >> n)
    {
        int ans = n;
        int temp = 0;
        if (n == 0)
            break;
        else
        {
            while (ans / 10 != 0)
            {

                while (n != 0)
                {
                    temp += n % 10;
                    n = n / 10;
                    // cout << temp << endl;
                }
                ans = temp;
                n = temp;
                temp = 0;
            }
        }
        cout << ans << endl;
    }
}