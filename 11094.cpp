#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int n, m, i, j, ans, sum;
char used[21][21], map[21][21], land;

void dfs(int x, int y)
{
    if (y < 0)
        y = m - 1;
    if (y >= m)
        y = 0;
    if (x < 0 || x >= n)
        return;
    if (used[x][y] != 0 || map[x][y] != land)
        return;
    used[x][y] = 1;
    sum++;
    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x - 1, y);
    dfs(x, y - 1);
}
int main()
{
    while (cin >> n >> m)
    {
        memset(used, 0, sizeof(used));
        for (int i = 0; i < n; i++)
            cin >> map[i];

        int a, b;
        land = map[a][b];
        dfs(a, b);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sum = 0;
                dfs(i, j);
                if (sum > ans)
                    ans = sum;
            }
        }
        cout << ans << endl;
    }
    return 0;
}