#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> set;
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        for (int i = a; i < b; i++)
        {
            set.insert(i);
        }
    }
    cout << set.size() << endl;
}