/*
	Problem: 2009-17: Binary tree traversals
	subs: 469, ACs: 96, AcceptRate: 20.47, onsite: 33, access: 2709

	Link: https://gpe3.acm-icpc.tw/showproblemtab.php?probid=2009-17&cid=5
*/

#include <bits/stdc++.h>
using namespace std;

using namespace std;

struct node
{
    char data;
    node *left;
    node *right;
};
int preorderIndex;

node *newNode(char data)
{
    node *ptr = new node();
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

int searchInOrder(char data, vector<char> &inOrder)
{
    for (int i = 0; i < inOrder.size(); i++)
    {
        if (data == inOrder[i])
            return i;
    }
    return -1;
}

node *buildTree(int left, int right, vector<char> &preOrder, vector<char> &inOrder)
{
    if (left > right)
        return NULL;
    else
    {
        preorderIndex++;
        char data = preOrder[preorderIndex];

        if (left == right)
            return newNode(data);

        int index = searchInOrder(data, inOrder);
        node *root = newNode(data);
        root->left = buildTree(left, index - 1, preOrder, inOrder);
        root->right = buildTree(index + 1, right, preOrder, inOrder);
        return root;
    }
}

void postOrderTraversal(node *root, vector<char> &postOrder)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left, postOrder);
        postOrderTraversal(root->right, postOrder);
        postOrder.push_back(root->data);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int nodeNum;
        cin >> nodeNum;

        vector<char> preOrder;
        vector<char> inOrder;

        char input;
        for (int i = 0; i < nodeNum; i++)
        {
            cin >> input;
            preOrder.push_back(input);
        }

        for (int i = 0; i < nodeNum; i++)
        {
            cin >> input;
            inOrder.push_back(input);
        }

        preorderIndex = -1;
        node *root = buildTree(0, nodeNum - 1, preOrder, inOrder);

        vector<char> postOrder;
        postOrderTraversal(root, postOrder);
        for (int i = 0; i < nodeNum; i++)
        {
            cout << postOrder[i];
            if (i != nodeNum - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}