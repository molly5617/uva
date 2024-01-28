#include <iostream>
#include <string>
using namespace std;
int main()
{
    string line = "";
    while (cin >> line)
    {
        if (line == "0")
            break;
        else
        {
            int even = 0, odd = 0;
            for (int i = 0; i < line.length(); i++)
            {
                if (i % 2 == 0)
                    even += line[i] - '0';
                else
                    odd += line[i] - '0';
            }
            if ((even - odd) % 11 == 0)
            {
                cout << line << " "
                     << "is a multiple of 11." << endl;
            }
            else
                cout << line << " "
                     << "is not a multiple of 11." << endl;
        }
    }
}