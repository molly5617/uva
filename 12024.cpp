#include <iostream>
using namespace std;
int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n - 1);
}
int derangement(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 0;
    }
    else
    {
        return (n - 1) * (derangement(n - 1) + derangement(n - 2));
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int hat;
        cin >> hat;
        cout << derangement(hat) << "/" << fact(hat) << endl;
    }
}