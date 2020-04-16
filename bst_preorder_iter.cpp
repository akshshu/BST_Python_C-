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

int main()
{
    node *root, *temp;
    int n;
    cout << "enter the no of nodes :";
    cin >> n;
    int data;
    cout << "enter key values of nodes :";

    for (int i = 0; i < n; i++)
    {
        cin >> data;
        if (i == 0)
        {

            root = new node;
            root->data = data;
        }
        else
        {
            temp = new node;
            temp->data = data;
            create_node(temp, root);
        }
    }
    vector<node *> order;
    if (root->right)
        order.push_back(root->right);
    if (root->left)
        order.push_back(root->left);
    cout << "preorder traversal of the provided binary search tree :" << endl;
    cout << root->data << " ";
    while (!order.empty())
    {
        node *root;
        cout << (order.back())->data << " ";
        root = order.back();

        order.erase(order.end() - 1);
        if (root->right)
            order.push_back(root->right);
        if (root->left)
            order.push_back(root->left);
    }
    if (root->left)
        order.push_back(root->left);
    if (root->right)
        order.push_back(root->right);
    cout << endl
         << "postorder traversal of the provided binary search tree :" << endl;
    vector<node *> order2;
    order2.push_back(root);
    while (!order.empty())
    {
        node *root;
        order2.push_back(order.back());
        root = order.back();
        order.erase(order.end() - 1);
        if (root->left)
            order.push_back(root->left);
        if (root->right)
            order.push_back(root->right);
    }
    for (int i = order2.size() - 1; i >= 0; i--)
        cout << (order2.at(i))->data << ' ';
}
