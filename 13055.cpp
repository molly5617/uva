#include <stack>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<string> s;
    for (int i = 0; i < n; i++)
    {
        string stage;
        cin >> stage;
        string name;
        if (stage == "Sleep")
        {
            cin >> name;
            s.push(name);
        }
        else if (stage == "Test")
        {
            if (!s.empty())
            {
                cout << s.top() << endl;
            }
            else
                cout << "Not in a dream" << endl;
        }
        else if (stage == "Kick")
        {
            if (!s.empty())
            {
                s.pop();
            }
        }
    }
}