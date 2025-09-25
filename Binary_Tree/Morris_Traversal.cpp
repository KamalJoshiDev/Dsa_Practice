#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

vector<int> Morris_Traversal(Node *root)
{
    if (root == nullptr)
        return {};

    vector<int> res;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == nullptr)
        {
            res.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *leftNode = curr->left;
            while (leftNode->right != nullptr)
            {
                leftNode = leftNode->right;
            }
            leftNode->right = curr;
            Node *Temp = curr;
            curr = curr->left; // ? Move Current To One Node Further
            Temp->left = NULL; //?  Break The Connection
        }
    }
    return res;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    vector<int> res = Morris_Traversal(root);

    for(int &it : res){
        cout << it << " ";
    }
    return 0;
}