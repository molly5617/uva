#include <iostream>
using namespace std;
const int maxn = 100000 + 5;
int maxx[maxn], head[maxn];
int n, m, x, y, cnt;

using namespace std;
struct edge
{
    int to, next;

} e[maxn];

void add(int u, int v)
{
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs(int u, int v)
{
    if (maxx[v])
        return;
    maxx[v] = u;
}

int main()
{
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    memset(maxx, 0, sizeof(maxx));
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        add(y, x);
    }
    for (int i = n; i; i--)
        dfs(i, i);
}