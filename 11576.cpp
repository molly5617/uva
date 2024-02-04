#include <iostream>
<<<<<<< HEAD
#include <string>
using namespace std;
#include <vector>
=======
#include <vector>
using namespace std;

>>>>>>> a23b378df511b6c5fc71427095a2181a2d83e2d9
int main()
{
    int n;
    cin >> n;
<<<<<<< HEAD
=======

>>>>>>> a23b378df511b6c5fc71427095a2181a2d83e2d9
    while (n--)
    {
        int k, w;
        cin >> k >> w;
<<<<<<< HEAD
        vector<string> v;
        for (int i = 0; i < w; i++)
        {
            string str;
            cin >> str;
            v.push_back(str);
        }
        int ans = k;
        bool flag = false;
        for (int i = 1; i < w; i++)
        {
            flag = false;

            for (int j = 0; j < k && !flag; j++)
            {
                string first = v[i - 1].substr(j);
                string second = v[i].substr(0, k - j);
                if (first == second)
                {
                    ans += j;
                    flag = true;
                }
            }
            if (!flag)
                ans += k;
        }
        cout << ans << endl;
    }
}
=======

        vector<string> v;
        for (int i = 0; i < w; i++)
        {
            string a;
            cin >> a;
            v.push_back(a);
        }

        int ans = k;
        for (int i = 1; i < w; i++)
        {
            int j = 0;
            bool flag = false;
            int position = 0;

            int s = 0;
            while (s < k - 1)
            {
                if (v[i - 1][s] == v[i][j])
                {
                    j++;
                    if (!flag)
                    {
                        position = s;
                    }
                    flag = true;
                }
                else
                {
                    s = position;
                    flag = false;
                    j = 0;
                }
                s++;
            }

            ans += k - j;
        }

        cout << ans << endl;
    }

    return 0;
}
>>>>>>> a23b378df511b6c5fc71427095a2181a2d83e2d9
