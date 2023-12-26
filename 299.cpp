#include <iostream>
using namespace std;
#include <vector>
int main()
{
    int n;
    cin >> n;
    int ans;
    for (int k = 0; k < n; k++)
    {
        vector<int> v = {0};
        int num;
        cin >> num;
        ans = 0;
        for (int i = 0; i < num; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < num; i++)
            for (int j = 0; j < num - i - 1; j++)
            {
                if (v[j] > v[j + 1])
                {
                    int temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                    ans++;
                }
            }

       
        cout << "Optimal train swapping takes " << ans << " swaps." << endl;
    }
}