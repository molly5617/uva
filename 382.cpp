#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "PERFECTION OUTPUT" << endl;

    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            cout << "END OF OUTPUT" << endl;
            break;
        }

        int sum = 0;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
                sum += i;
        }

        if (sum == n)
        {
            cout << setw(5) << right << n << "  ";
            cout << "PERFECT" << endl;
        }
        else if (sum < n)
        {
            cout << setw(5) << right << n << "  ";
            cout << "DEFICIENT" << endl;
        }
        else
        {
            cout << setw(5) << right << n << "  ";
            cout << "ABUNDANT" << endl;
        }
    }

    return 0;
}
