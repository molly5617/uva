#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    vector<int> team;
    while (n--)
    {

        int num;
        cin >> num;
        team.clear();
        while (num--)
        {
            int a;
            cin >> a;
            team.push_back(a);
        }
        sort(team.begin(), team.end());
         cout << "Case " << i++ << ": " << team[team.size() / 2] << endl;
    }

   
}