#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int B[1001], N, cnt;

    while (cin >> N && N)
    {
        while (cin >> B[0] && B[0])
        {
            for (int i = 1; i < N; ++i)
                cin >> B[i];

            cnt = 0;
            vector<int> station;

            for (int i = 1; i <= N; ++i)
            {
                station.push_back(i);

                while (!station.empty() && station.back() == B[cnt])
                {
                    ++cnt;
                    station.pop_back();
                }
            }

            cout << ((station.empty()) ? "Yes" : "No") << endl;
        }

        // Print an additional newline after each set of test cases
        cout << endl;
    }

    return 0;
}
