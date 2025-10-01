#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int value)
    {
        val = value;
        next = nullptr;
    }
};

class LL
{
public:
    Node *head;
    LL()
    {
        head = nullptr;
    }

    void Insert(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    bool isPalindrome(Node *head)
    {

        stack<int> st;
        vector<int> res;

        if (head == nullptr)
            return true;

        Node *temp = head;
        // Node *temp2 = head;
        while (temp != nullptr)
        {
            st.push(temp->val);
            res.push_back(temp->val);
            temp = temp->next;
        }
        int i = 0;
        temp = head;
        while (temp != nullptr)
        {
            if (st.top() != res[i])
            {

                return false;
            }
            st.pop();
            i++;
            temp = temp->next;
        }
        return true;
    }
};

int main()
{
    LL lst;
    lst.Insert(1);
    lst.Insert(2);
    lst.Insert(3);
    lst.Insert(6);
    lst.Insert(1);
    cout << lst.isPalindrome(lst.head);
    return 0;
}