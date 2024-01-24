#include <stack>
using namespace std;
#include <iostream>
#include <string>
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        stack<char> st;
        string str;
        getline(cin, str);

        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == ')')
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else
                    st.push(str[j]);
            }
            else if (str[j] == ']')
            {
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                }
                else
                    st.push(str[j]);
            }
            else
                st.push(str[j]);
        }
        if (st.empty() || str.length() == 0)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
}