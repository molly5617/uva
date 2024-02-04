#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <map>
int main()
{
    long long int low, high;
    while (cin >> low >> high && low)
    {
        cout << high / 5 - low / 5 + 1 << endl;
    }
}