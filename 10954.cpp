#include <iostream>
using namespace std;
#include <vector>
#include <queue>
priority_queue<int, vector<int>, greater<int>> q;
int main()
{
    long long int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        while (!q.empty())
            q.pop();
        for (long long int i = 0; i < n; i++)
        {
            long long int k;
            cin >> k;
            q.push(k);
        }
        long long int ans = 0, a, b;
        while (q.size() != 1)
        {
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();
            q.push(a + b);
            ans += a + b;
        }
        cout << ans << endl;
    }
    return 0;
}