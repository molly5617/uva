#include <iostream>
#include <vector> // Add this line
using namespace std;

vector<int> block[30];
int n;

void goback(int p, int h)
{
    for (int i = h + 1; i < block[p].size(); i++)
    {
        int k = block[p][i];
        block[k].push_back(k);
    }
    block[p].resize(h + 1);
}

void moveall(int p, int h, int q)
{
    for (int i = h; i < block[p].size(); i++)
    {
        int k = block[p][i];
        block[q].push_back(k);
    }
    block[p].resize(h);
}

void init()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        block[i].push_back(i);
    }
}

void loc(int x, int &p, int &h)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < block[i].size(); j++)
        {
            if (block[i][j] == x)
            {
                p = i;
                h = j;
            }
        }
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        for (int j = 0; j < block[i].size(); j++)
            cout << " " << block[i][j];
        cout << endl;
    }
}

int main()
{
    int a, b;
    string s1, s2;

    while (cin >> n)
    {

        for (int i = 0; i < n; i++)
        {
            block[i].clear();
            block[i].push_back(i);
        }
        while (cin >> s1)
        {
            if (s1 == "quit")
            {
                print();
                break;
            }

            cin >> a >> s2 >> b;
            int ap = 0, ah = 0, bp = 0, bh = 0;
            loc(a, ap, ah);
            loc(b, bp, bh);
            if (ap == bp)
                continue;
            if (s1 == "move")
                goback(ap, ah);
            if (s2 == "onto")
                goback(bp, bh);
            moveall(ap, ah, bp);
        }
    }
    return 0;
}
