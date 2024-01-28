#include <iostream>
using namespace std;

string pre, in;
int first, len;

struct treenode
{
    char val;
    treenode *left;
    treenode *right;
    treenode(char x, treenode *l, treenode *r) : val(x), left(l), right(r) {}
};
treenode *buildtree(int left, int right)
{
    int i, mid = left;
    treenode *curr;
    curr = new treenode(pre[first++], NULL, NULL);
    if (left < right)
    {
        for (i = left; i <= right; i++)
        {
            if (in[i] == curr->val)
            {
                mid = i;
                break;
            }
        }
        if (left <= mid - 1)
        {
            curr->left = buildtree(left, mid - 1);
        }
        if (mid + 1 <= right)
        {
            curr->right = buildtree(mid + 1, right);
        }
    }
    return curr;
}
void postorder(treenode *p)
{
    if (p->left != NULL)
        postorder(p->left);
    if (p->right != NULL)
        postorder(p->right);
    cout << p->val;
}

int main()
{
    while (cin >> pre >> in)
    {
        first = 0;
        len = (int)pre.length();
        treenode *root;
        root = buildtree(0, len - 1);
        postorder(root);
        cout << endl;
    }
    return 0;
}