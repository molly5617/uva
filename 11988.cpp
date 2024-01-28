#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main()
{
    string word;
    while (cin >> word)
    {
        deque<char> result;
        int ind = 0;
        for (char c : word)
        {
            if (c == '[')
            {
                ind = 0;
            }
            else if (c == ']')
            {
                ind = result.size();
            }
            else
            {
                result.insert(result.begin() + ind, c);
                ind++;
            }
        }
        cout << string(result.begin(), result.end()) << endl;
    }
    return 0;
}
