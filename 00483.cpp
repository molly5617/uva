#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<char> line;

    string ans;
    while (getline(cin, ans))
    {
        int i;
        for (i = 0; i < ans.size(); i++)
        {
            if (ans[i] == ' ')
            {
                for (int i = line.size() - 1; i >= 0; i--)
                    cout << line[i];
                cout << ' ';
                line.clear();
            }

            else
            {
                line.push_back(ans[i]);
                // for (int j = 0; j < line.size(); j++)
                // cout << line[j];
                // cout << endl;
            }
        }
        if (i == ans.size())
        {
            for (int i = line.size() - 1; i >= 0; i--)
                cout << line[i];
            line.clear();
            cout << endl;
        }
    }
}