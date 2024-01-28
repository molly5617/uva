#include <iostream>
#include <iomanip>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<char, double> atomic_weights = {
        {'C', 12.01},
        {'H', 1.008},
        {'O', 16.00},
        {'N', 14.01}};

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        double sum = 0.0;
        int j = 0;

        while (j < str.length())
        {
            char element = str[j];
            int count = 0;

            // 檢查下一個字符是否為數字
            j++;

            while (j < str.length() && isdigit(str[j]))
            {
                count = count * 10 + (str[j] - '0');
                j++;
            }

            if (count == 0)
            {
                count = 1;
            }

            sum += atomic_weights[element] * count;
        }

        cout << fixed << setprecision(3) << sum << endl;
    }

    return 0;
}
