#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
    vector<int> n(3);
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> n[0] >> n[1] >> n[2];
        sort(n.begin(), n.end());
        if ((n[1] + n[0]) <= n[2])
        {
            cout << "Wrong!!" << endl;
        }
        else if ((n[2] - n[1]) >= n[0])
        {
            cout << "Wrong!!" << endl;
        }
        else
            cout << "OK" << endl;
    }
}