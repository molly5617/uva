#include <iostream>
#include <string>
using namespace std;
int main()
{
    char s;
    int head = 0;
    while (cin.get(s))
    {
        
        if(s!='"')cout<<s;
        else if(head%2==0)
        {
            cout<<"``";
            head++;

        }
        else
        {
            cout<<"''";
            head++;
        }
        
    }
}