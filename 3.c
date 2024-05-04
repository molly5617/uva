#include <stdio.h>

long long count_possible_plans(int n, int k, int q, int temperatures[])
{
    long long count = 0;            // 初始化计数器
    long long consecutive_days = 0; // 连续天数计数器

    // 遍历天数
    for (int i = 0; i < n; i++)
    {
        // 如果当天温度符合要求，连续天数加1
        if (temperatures[i] <= q)
        {
            consecutive_days++;
        }
        else
        {
            consecutive_days = 0; // 温度不符合要求，重置连续天数
        }

        // 如果连续天数大于等于k，计数器加上连续天数-k+1
        if (consecutive_days >= k)
        {
            count += consecutive_days - k + 1;
        }
    }

    return count;
}

int main()
{
    int t;
    scanf("%d", &t); // 输入测试用例数量

    // 处理每个测试用例
    for (int i = 0; i < t; i++)
    {
        int n, k, q;
        scanf("%d %d %d", &n, &k, &q); // 输入假期天数n，至少连续滑雪天数k，最高温度q

        int temperatures[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &temperatures[j]); // 输入每天的温度
        }

        // 调用函数计算方法数并输出
        printf("%lld\n", count_possible_plans(n, k, q, temperatures));
    }

    return 0;
}
