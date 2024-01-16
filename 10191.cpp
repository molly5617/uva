#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    int time = 0;
    while (cin >> n)
    {
        cin.ignore(); // 消耗掉前一行的換行符號

        vector<int> hour1(n + 2), hour2(n + 2), minute1(n + 2), minute2(n + 2);
        string line;
        int i;
        hour2[0] = 10;
        minute2[0] = 0;
        for (i = 1; i <= n; i++)
        {
            getline(cin, line);
            hour1[i] = (line[0] - '0') * 10 + (line[1] - '0');
            minute1[i] = (line[3] - '0') * 10 + (line[4] - '0');
            hour2[i] = (line[6] - '0') * 10 + (line[7] - '0');
            minute2[i] = (line[9] - '0') * 10 + (line[10] - '0');
        }

        hour1[n + 1] = 18;
        minute1[n + 1] = 0;

        int max = 0;
        int start;
        int minute;

        for (int i = 0; i < n + 1; i++)
        {
            if (hour2[i] * 60 + minute2[i] < hour1[i + 1] * 60 + minute1[i + 1])
            {
                minute = (hour1[i + 1] * 60 + minute1[i + 1]) - (hour2[i] * 60 + minute2[i]);

                if (minute > max)
                {
                    max = minute;
                    start = hour2[i] * 60 + minute2[i];
                }
            }
        }

        if (max >= 60)
        {
            printf("Day #%d: the longest nap starts at %.2d:%.2d and will last for ", ++time, start / 60, start % 60);
            printf("%d hours and %d minutes.\n", (max / 60), max % 60);
        }
        else
        {
            printf("Day #%d: the longest nap starts at %.2d:%.2d and will last for ", ++time, start / 60, start % 60);
            printf("%d minutes.\n", max);
        }
    }

    return 0;
}
