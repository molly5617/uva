#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> ans;
        ans.resize(n);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> ans[i];
        }
        int temp;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (ans[j] > ans[j + 1])
                {
                    int temp = ans[j + 1];
                    ans[j + 1] = ans[j];
                    ans[j] = temp;
                    count++;
                }
            }
        cout << "Minimum exchange operations : " << count << endl;
    }
}