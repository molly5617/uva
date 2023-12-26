#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    char c;
    string line;
    map<char, int> num;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        for (int j = 0; j < line.length(); j++)
        {
            if (line[j] != ' ')
            {
                num[toupper(line[j])]++;
                len++;
            }
        }
    }
    while (--len)
    {
        for (c = 'A'; c <= 'Z'; c++)
        {
            if (num[c] == len)
            {
                cout << c << " " << num[c] << endl;
            }
        }
    }
}