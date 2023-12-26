#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int i = 0;
    while (num--)
    {
        int a, b;
        cin >> a >> b;
        int head;
        if (a % 2 == 1)
            head = a;
        else
            head = a + 1;
        int ans = 0;
        for (int j = head; j <= b; j += 2)
        {
            ans += j;
        }
        cout << "Case " << ++i << ": " << ans << endl;
    }
}