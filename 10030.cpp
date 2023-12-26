#include <iostream>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long int num;
        cin >> num;
        long long int sum = 0;
        for (int j = 0; j < num; j++)
        {
            long long int a, b, c;
            cin >> a >> b >> c;
            sum += a * c;
        }
        cout << sum << endl;
    }
}