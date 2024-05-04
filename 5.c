#include <stdio.h>
#include <string.h>

// 定義星期幾
enum Weekday
{
    SUN,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
};

// 定義月份名稱
const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

// 計算某年是不是閏年
int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

// 根據月份和年份計算該月有多少天
int daysInMonth(int month, int year)
{
    if (month == 2)
    {
        if (isLeapYear(year))
            return 29;
        else
            return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

// 根據星期名稱返回對應的枚舉值
enum Weekday getWeekdayEnum(const char *day)
{
    if (strcmp(day, "Sun") == 0)
        return SUN;
    else if (strcmp(day, "Mon") == 0)
        return MON;
    else if (strcmp(day, "Tue") == 0)
        return TUE;
    else if (strcmp(day, "Wed") == 0)
        return WED;
    else if (strcmp(day, "Thu") == 0)
        return THU;
    else if (strcmp(day, "Fri") == 0)
        return FRI;
    else
        return SAT;
}

// 根據星期枚舉值返回對應的星期名稱
const char *getWeekdayName(enum Weekday day)
{
    switch (day)
    {
    case SUN:
        return "Sun";
    case MON:
        return "Mon";
    case TUE:
        return "Tue";
    case WED:
        return "Wed";
    case THU:
        return "Thu";
    case FRI:
        return "Fri";
    case SAT:
        return "Sat";
    default:
        return "";
    }
}

// 根據基準日期和星期計算指定年份的日曆
void printCalendar(int year, int month, int date, enum Weekday weekday)
{
    int days, i, j, k;

    // 計算基準日期是一年中的第幾天
    days = date;
    for (i = 1; i < month; ++i)
        days += daysInMonth(i, year);

    // 計算該年的第一天是星期幾
    enum Weekday firstDay = (enum Weekday)((days + 1) % 7);

    // 計算該年是否是閏年
    int leapYear = isLeapYear(year);

    // 輸出日曆標題
    printf("%d\n", year);

    // 遍歷每個月份
    for (i = 0; i < 12; ++i)
    {
        // 輸出月份名稱
        printf("%s\n", months[i]);

        // 輸出星期標題
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat");

        // 輸出第一周的空白
        for (j = 0; j < firstDay; ++j)
            printf("\t");

        // 輸出該月的日期
        for (k = 1; k <= daysInMonth(i + 1, year); ++k)
        {
            printf("%d", k);

            // 換行處理
            if ((firstDay + k - 1) % 7 == 6 || k == daysInMonth(i + 1, year))
                printf("\n");
            else
                printf("\t");
        }

        // 更新第一周的空白和第一天的星期
        firstDay = (enum Weekday)((firstDay + daysInMonth(i + 1, year)) % 7);
    }
}

int main()
{
    int baseYear, baseMonth, baseDate, q;
    char baseDay[4];

    // 讀取基準日期和星期
    scanf("%d/%d/%d (%3s)", &baseYear, &baseMonth, &baseDate, baseDay);

    // 讀取詢問數量
    scanf("%d", &q);

    // 根據星期名稱獲取對應的枚舉值
    enum Weekday baseWeekday = getWeekdayEnum(baseDay);

    // 計算基準星期和輸入星期之間的差距
    int diff = baseWeekday - TUE;
    if (diff < 0)
        diff += 7;

    // 逐個處理詢問
    while (q--)
    {
        int year;
        scanf("%d", &year);
        // 將基準星期向後調整到星期二
        enum Weekday adjustedWeekday = (enum Weekday)((baseWeekday + diff) % 7);
        printCalendar(year, baseMonth, baseDate, adjustedWeekday);
    }

    return 0;
}
