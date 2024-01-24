#include <iostream>
#include <sstream>
using namespace std;
const int maxn = 10000 + 5;
int inorder[maxn], postorder[maxn], lch[maxn], rch[maxn];
int n, minv, minsum;

int createtree(int l1, int l2, int m)
{
    if (m <= 0)
        return 0;
    int root = postorder[l2 + m - 1];
    int len = 0;
    while (inorder[l1 + len] != root)
        len++;
    lch[root] = createtree(l1, l2, len);
    rch[root] = createtree(l1 + len + 1, l2 + len, m - len - 1);
    return root;
}

bool readline(int *a)
{
    string line;
    if (!getline(cin, line))
        return false;
    stringstream s(line);
    n = 0;
    int x;
    while (s >> x)
        a[n++] = x;
    return n > 0;
}

void findmin(int v, int sum)
{
    sum += v;
    if (!lch[v] && !rch[v])
        if (sum < minsum || (sum == minsum && v < minv))
        {
            minv = v;
            minsum = sum;
        }
    if (lch[v])
        findmin(lch[v], sum);
    if (rch[v])
        findmin(rch[v], sum);
}
int main()
{
    while (readline(inorder))
    {
        readline(postorder);
        createtree(0, 0, n);
        minsum = 0x7fffffff;
        findmin(postorder[n - 1], 0);
        cout << minv << endl;
    }
    return 0;
}