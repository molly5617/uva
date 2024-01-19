#include <iostream>
using namespace std;
#include <string>
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string team, judge;
        getline(cin, team);
        getline(cin, judge);
        if (team == judge)
        {
            cout << "Case " << i + 1 << ": "
                 << "Yes" << endl;
        }
        else
        {
            string team1, judge1;
            for (int j = 0; j < team.length(); j++)
            {
                if (team[j] != ' ')
                {
                    team1 += team[j];
                }
            }
            for (int j = 0; j < judge.length(); j++)
            {
                if (judge[j] != ' ')
                {
                    judge1 += judge[j];
                }
            }
            if (judge1 == team1)
            {
                cout << "Case " << i + 1 << ": "
                     << "Output Format Error" << endl;
            }
            else
            {
                cout << "Case " << i + 1 << ": "
                     << "Wrong Answer" << endl;
            }
        }
    }
}