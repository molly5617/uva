#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int temp;
    vector<int> ans;

    while (cin >> temp)
    {
        ans.push_back(temp);

        
        int j = ans.size() - 1;
        while (j > 0 && ans[j - 1] > ans[j])
        {
            swap(ans[j - 1], ans[j]);
            j--;
        }

        if (ans.size() % 2 == 1)
        {
            cout << ans[ans.size() / 2] << endl;
        }
        else
        {
            cout << (ans[ans.size() / 2 - 1] + ans[ans.size() / 2]) / 2 << endl;
        }
    }

    return 0;
}
