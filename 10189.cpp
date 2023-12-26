#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    int field = 0;

    while (cin >> a >> b)
    {
        field++;

        if (a == 0 && b == 0)
            break;

        vector<vector<char>> map(a, vector<char>(b));

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                cin >> map[i][j];
            }
        }

        cout << "Field #" << field << ":" << endl;

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (map[i][j] == '*')
                {
                    cout << '*';
                }
                else
                {
                    int ans = 0;

                    // 檢查周圍8個方向的地雷
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        for (int dy = -1; dy <= 1; dy++)
                        {
                            int ni = i + dx;
                            int nj = j + dy;

                            if (ni >= 0 && ni < a && nj >= 0 && nj < b && map[ni][nj] == '*')
                            {
                                ans++;
                            }
                        }
                    }

                    cout << ans;
                }
            }
            cout << endl;
        }

        cout << endl;
    }

    return 0;
}
