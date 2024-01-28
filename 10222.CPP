#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    string key = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    string line;
    while (getline(cin, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ' ')
                cout << " ";
            else
                for (int j = 0; j < key.length(); j++)
                {
                    if (key[j] == tolower(line[i]))
                    {
                        cout << key[j - 2];
                        break;
                    }
                }
        }
        cout << endl;
    }
}