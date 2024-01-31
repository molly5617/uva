#include <iostream>
using namespace std;
#include <string>
struct listnode
{
    int val;
    listnode *next;
    listnode(int x) : val(x), next(nullptr) {}
};
listnode* reverse (listnode *head)
{
    listnode *pre = nullptr;
    listnode *cur = head;
    listnode *temp;

    while (cur)
    {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }

    return pre;
}

int main()
{
    int n, m;
    listnode *head = new listnode(1);
    cin >> n >> m;
    listnode *cur = head;
    for (int i = 2; i <= n; i++)
    {
        cur->next = new listnode(i);
        cur = cur->next;
    }
    cur->next = head;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            listnode *slow = head;
            listnode *fast = head;
            while (slow->next->val != b)
            {
                slow = slow->next;
            }
            while (fast->next->val != c)
            {
                fast = fast->next;
            }
            listnode *tempb, *tempc;
            tempb = new listnode(b);
            slow->next = slow->next->next;
            tempb->next = fast->next;
            fast->next = tempb;
        }
        else if (a == 2)
        {
        }
        else if (a == 3)
        {
        }
        else
        {
            head=reverse(head);
        }
    }
}