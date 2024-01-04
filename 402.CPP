#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int people;
    int time = 0;
    while (cin >> people)
    {
        cout << "Selection #" << ++time << endl;
        // for (int h = 1; h <= people; h++)
        // cout << h << " ";
        // cout << endl;
        int lucky;
        cin >> lucky;
        int k[20];
        vector<int> killed(people, 0); // 初始化為0表示未被淘汰
        int survive = people;
        int now = 0;
        for (int i = 0; i < 20; i++)
            cin >> k[i];

        for (int i = 0; i < 20; i++)
        {
            if (survive == lucky)
                break;
            now = 0;

            for (int j = 0; j < people; j++)
            {
                if (survive == lucky)
                    break;

                if (killed[j] == 0)
                {
                    now++;
                    if (now == k[i])
                    {
                        now = 0;
                        killed[j] = 1;
                        survive--;
                    }
                }
            }

            // for (int z = 0; z < people; z++)
            // cout << killed[z] << " ";
            // cout << endl;
        }
        int flag = 0;
        for (int i = 0; i < people; i++)
        {
            if (killed[i] == 0)
            {
                if (flag == 0)
                {
                    cout << i + 1;
                    flag = 1;
                }
                else
                    cout << " " << i + 1;
            }
        }
        cout << endl
             << endl;
    }
    return 0;
}
