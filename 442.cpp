#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <map>
#include <math.h>
#include <stack>
struct matrix
{
    char c;
    int left;
    int right;
};
int main()
{
    map<char, matrix> mp;
    int n;
    cin >> n;
    while (n--)
    {
        char c;
        cin >> c;
        cin >> mp[c].left >> mp[c].right;
    }
    string str;
    int ans = 0;
    matrix ri, le;
    while (cin >> str)
    {
        stack<matrix> st;
        bool error = false;
        ans = 0;
        for (int i = 0; i < str.size() && !error; i++)
        {
            if (str[i] == ')' && !error)
            {
                while (st.top().c != '(')
                {
                    ri = st.top();
                    st.pop();
                    le = st.top();
                    st.pop();
                    if (ri.left != le.right)
                    {
                        error = true;
                        break;
                    }
                    else
                    {
                        ans += le.left * le.right * ri.right;
                    }
                    // cout << ans << endl;
                }
                // cout << ans << endl;
                st.pop();
                matrix ch;
                ch.c = 'n';
                ch.left = le.left;
                ch.right = ri.right;
                st.push(ch);
            }
            else
            {
                matrix ch;
                ch.c = str[i];
                ch.left = mp[str[i]].left;
                ch.right = mp[str[i]].right;
                st.push(ch);
            }
        }
        if (error)
        {
            cout << "error" << endl;
        }
        else if (ans)
        {
            cout << ans << endl;
        }
        else
        {
            cout << "0" << endl;
        }
        while (!st.empty())
        {
            st.pop();
        }
    }
}
