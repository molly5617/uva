#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int times = 1; times <= n; ++times)
    {
        int a, b;
        cin >> a >> b;
        cin.ignore();

        vector<string> line(a);
        vector<string> line2(b);

        for (int i = 0; i < a; i++)
        {
            getline(cin, line[i]);
        }

        for (int i = 0; i < b; i++)
        {
            getline(cin, line2[i]);
        }

        set<string> ans;

        for (int i = 0; i < line.size(); i++)
            for (int j = 0; j < line2.size(); j++)
            {
                ans.insert(line[i] + line2[j]);
            }

        cout << "Case " << times << ": " << ans.size() << endl;
    }

    return 0;
}
