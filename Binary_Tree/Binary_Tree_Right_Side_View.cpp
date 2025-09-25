#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int Val)
    {
        val = Val;
        left = right = nullptr;
    }
};

vector<int> Right_View(Node *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        Node *Temp = nullptr;

        while (n--)
        {
            Temp = q.front();
            q.pop();
            if (Temp->left != NULL)
            {
                q.push(Temp->left);
            }
            if (Temp->right != NULL)
            {
                q.push(Temp->right);
            }
           
        }
        res.push_back(Temp->val);
    }
    return res;
}

int main()

{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);
    root->right->right = new Node(4);

    vector<int> res = Right_View(root);
    for (auto &it : res)
    {
        cout << it << " ";
    }
    return 0;
}