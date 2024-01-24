#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        deque<int> remain;
        deque<int> discarded;

        for (int i = 1; i <= n; i++)
        {
            remain.push_back(i);
        }

        while (remain.size() > 1)
        {

            discarded.push_back(remain.front());
            remain.pop_front();

            remain.push_back(remain.front());
            remain.pop_front();
        }

        cout << "Discarded cards:";
        for (int i = 0; i < discarded.size(); i++)
        {
            cout << " " << discarded[i];
            if (i < discarded.size() - 1)
            {
                cout << ",";
            }
        }
        cout << endl;

        if (!remain.empty())
        {
            cout << "Remaining card: " << remain.front() << endl;
        }
    }

    return 0;
}
