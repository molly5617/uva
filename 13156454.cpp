#include <cmath>
#include <iostream>
using namespace std;
#include <string>
class DigPow
{
public:
    static int digPow(int n, int p)
    {
        string result = to_string(n);
        int temp = 0;
        int n1 = n;
        for (int i = 0; i < result.length(); i++, p++)
        {
            temp += pow((result[i] - '0'), p);
        }

        cout << temp << endl;
        if (temp % n == 0)
            return temp / n;
        else
            return -1;
    }
};
int main()
{
    cout << DigPow::digPow(89, 1);
}