#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    node *left = NULL;
    node *right = NULL;
};
void create_node(node *temp, node *root)
{
    if (root == NULL)
        root = temp;
    else if (root->data > temp->data)
    {

        if (root->left == NULL)
            root->left = temp;
        else
            create_node(temp, root->left);
    }
    else
    {
        if (root->right == NULL)
            root->right = temp;
        else
            create_node(temp, root->right);
    }
}
void show_in(node *root)
{
    if (root)
    {
        show_in(root->left);
        cout << root->data << " ";
        show_in(root->right);
    }
}
void show_pre(node *root)
{
    if (root)
    {
        cout << root->data << " ";
        show_pre(root->left);
        show_pre(root->right);
    }
}
void show_post(node *root)
{
    if (root)
    {
        show_post(root->left);
        show_post(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    node *root, *temp;
    int n;
    cout << "enter the no of nodes :";
    cin >> n;
    int a[n];
    cout << "enter key values of nodes :";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
        {

            root = new node;
            root->data = a[i];
        }
        else
        {
            temp = new node;
            temp->data = a[i];
            create_node(temp, root);
        }
    }
    cout << "inorder traversal :";
    show_in(root);
    cout << endl
         << "preorder traversal :";
    show_pre(root);
    cout << endl
         << "postorder traversal :";
    show_post(root);
}
