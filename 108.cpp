#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        int arr[200][200];
        int array[200][200] = {0};

        // Input
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> arr[i][j];
                array[i][j] = array[i - 1][j] + arr[i][j];
            }
        }

                int max = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                int sum = 0;
                for (int k = 1; k <= n; k++)
                {
                    sum += array[j][k] - array[i - 1][k];
                    if (sum > max)
                        max = sum;
                    if (sum < 0)
                        sum = 0;
                }
            }
        }

        cout << max << endl;
    }

    return 0;
}
