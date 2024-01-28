#include <iostream>
#include <algorithm>
using namespace std;
struct bottle
{
    string name = "";
    int num;
};
int main()
{
    int glass[3][3];
    while (cin >> glass[0][0] >> glass[0][1] >> glass[0][2] >> glass[1][0] >> glass[1][1] >> glass[1][2] >> glass[2][0] >> glass[2][1] >> glass[2][2])
    {

        bottle a[6];
        a[0].name = "BGC";
        a[0].num = glass[1][0] + glass[2][0] + glass[0][1] + glass[2][1] + glass[0][2] + glass[1][2];
        a[1].name = "BCG";
        a[1].num = glass[1][0] + glass[2][0] + glass[0][2] + glass[2][2] + glass[0][1] + glass[1][1];
        a[2].name = "GBC";
        a[2].num = glass[1][1] + glass[2][1] + glass[0][0] + glass[2][0] + glass[0][2] + glass[1][2];
        a[3].name = "GCB";
        a[3].num = glass[1][1] + glass[2][1] + glass[0][2] + glass[2][2] + glass[0][0] + glass[1][0];
        a[4].name = "CBG";
        a[4].num = glass[1][2] + glass[2][2] + glass[0][0] + glass[2][0] + glass[0][1] + glass[1][1];
        a[5].name = "CGB";
        a[5].num = glass[1][2] + glass[2][2] + glass[0][1] + glass[2][1] + glass[0][0] + glass[1][0];

        sort(a, a + 6, [](const bottle &x, const bottle &y)
             {
                 if (x.num == y.num)
                 {
                     return x.name < y.name;
                 }
                 return x.num < y.num; });

        cout << a[0].name << " " << a[0].num << endl;
    }
}
