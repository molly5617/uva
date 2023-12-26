#include <iostream>
#include <string>
using namespace std;
int main()
{

    while (true)
    {
        string line = "";
        cin >> line;
        if (line == ".")
            break;
        else
        {
            for (int i = 1; i <= line.length(); i++)
            {
                if (line.length() % i != 0)
                    continue;
                int flag = 1;
                for (int j = i; flag == 1 && j < line.length(); j = j + i)
                {
                    for (int k = 0; flag == 1 && k < i; k++)
                    {
                        if (line[k] != line[k + j])
                        {
                            flag = 0;
                            break;
                        }
                    }
                }
                if (flag)
                {
                    cout << line.length() / i << endl;
                    break;
                }
            }
        }
    }
}