#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <climits>
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int person;
        cin >> person;
        vector<int> v(person + 1);
        for (int i = 0; i < person; i++)
        {
            cin >> v[i];
                }
        int pre = max(v[0], v[1]);
        int max = v[0] - v[1];
        for (int i = 2; i < person; i++)
        {
            int temp = pre - v[i];
            if (temp > max)
                max = temp;
            if (v[i] > pre)
                pre = v[i];
        }

        cout << max << endl;
    }
}
