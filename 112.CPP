#include <iostream>
using namespace std;
struct node
{
    int right = -1, left = -1; // 記錄sub node是否為null
    int node_number = 0;       // 記錄節點數
};

int N;
bool flag = 0;

void input(int sum, node *n)
{
    char c;
    int a;
    cin >> c; // 讀'('

    cin >> a;
    // 抓到')'，判斷是否為葉子
    if (!cin)
    {
        cin.clear();
        n->node_number++;
        if (n->node_number % 2)
            n->left = 0;
        else
            n->right = 0;
        if ((n->left == 0) && (n->right == 0))
            if (N == sum)
                flag = 1;
    }

    // 抓到數字
    else
    {
        sum += a;
        n->node_number++;
        if (n->node_number % 2)
            n->left = 1;
        else
            n->right = 1;
        node *w = new node;
        input(sum, w);
        input(sum, w);
    }

    // 讀')'
    cin >> c;
}

int main()
{

    while (cin >> N)
    {
        node *a = new node;
        flag = 0;
        input(0, a);
        if (flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}