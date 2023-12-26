#include <iostream>
#include <string>
using namespace std;
int main()
{
    string key = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
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
                    if (key[j] == line[i])
                    {
                        cout << key[j - 1];
                        break;
                    }
                }
        }
        cout << endl;
    }
}