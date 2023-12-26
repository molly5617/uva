#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> line(3);
        for (int j = 0; j < 3; j++)
        {
            cin >> line[j];
        }
        sort(line.begin(), line.end());
        cout << "Case " << i + 1 << ": " << line[1] << endl;
    }
}