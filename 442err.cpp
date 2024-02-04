#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <map>
#include <math.h>
#include <stack>
struct matrix
{
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
    char ri, le;
    while (cin >> str)
    {
        stack<char> st;
        bool error = false;
        ans = 0;
        for (int i = 0; i < str.size() && !error; i++)
        {
            if (str[i] == ')' && !error)
            {
                while (st.top() != '(')
                {
                    ri = st.top();
                    st.pop();
                    le = st.top();
                    st.pop();
                    if (mp[ri].left != mp[le].right)
                    {
                        error = true;
                        break;
                    }
                    else
                    {
                        ans += mp[le].left * mp[le].right * mp[ri].right;
                    }
                    cout << ans << endl;
                }
                // cout << ans << endl;
                st.pop();
                char ch = 'n';
                mp[ch].left = mp[le].left;
                mp[ch].right = mp[ri].right;
                st.push(ch);
            }
            else
                st.push(str[i]);
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
