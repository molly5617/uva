#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        bool leap = false;
        if (n % 4 == 0 && n % 100 != 0)
            leap = true;
        if (n % 4 == 0 && n % 400 == 0)
            leap = true;
        bool ordinary = false;
        if (leap)
        {
            cout << "This is leap year." << endl;
            ordinary = true;
        }
        if (n % 15 == 0)
        {
            cout << "This is huluculu festival year." << endl;
            ordinary = true;
        }
        if (leap && n % 55 == 0)
        {
            cout << "This is Bulukulu festival year." << endl;
            ordinary = true;
        }
        if (!ordinary)
        {
            cout << "This is an ordinary year." << endl;
        }
    }
}