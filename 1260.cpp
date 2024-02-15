#include <iostream>
using namespace std;
#include <vector>
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;

        cin >> a;
        vector<int> v(a);
        for (int i = 0; i < a; i++)
        {
            cin >> v[i];
        }
        int ans = 0;
        for (int i = 1; i < a; i++)
        {

            for (int j = 0; j < i; j++)
            {
                if (v[i] >= v[j])
                    ans++;
            }
        }
        cout << ans << endl;
    }
}