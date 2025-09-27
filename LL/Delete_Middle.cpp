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
    void Delete_Middle(Node *head)
    {
        Node *slow = head;
        Node *fast = head;
        Node *prev = nullptr;

        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
    }

    void Display()
    {

        while (head != nullptr)
        {
            cout << head->val << " -->";
            head = head->next;
        }
        cout << "Null \n";
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
    lst.Delete_Middle(lst.head);
    lst.Display();
    return 0;
}