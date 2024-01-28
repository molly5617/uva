#include <iostream>
using namespace std;
#include <string>
#include <cctype>
int main()
{
    string line;
    while (getline(cin, line))
    {
        bool found = false;
        int ans = 0;
        for (int i = 0; i < line.length(); i++)
        {
            if (!isalpha(line[i]) && isalpha(line[i - 1]))
            {
                ans++;
            }
        }
        if (isalpha(line[line.length() - 1]))
        {
            ans++;
        }

        cout << ans << endl;
    }
}