#include <iostream>
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
    Node *FindMiddle(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    void Display()
    {
        Node *Middle = FindMiddle(head);
        cout << " Middle Value : " << Middle->val << " ";
    }
};

int main()
{

    LL lst;
    lst.Insert(10);
    lst.Insert(20);
    lst.Insert(30);
    lst.Insert(40);
    lst.Insert(50);
    lst.Display();
    return 0;
}