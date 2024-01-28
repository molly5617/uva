#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    vector<int> ans;
    scanf("%d", &n);
    ans.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ans[i]);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
}