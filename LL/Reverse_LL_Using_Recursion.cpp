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
        Node *newnode = new Node(val);
        newnode->next = head;
        head = newnode;
    }

    Node *Reverse(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        Node *Prev = Reverse(head->next);

        head->next->next = head;
        head->next = nullptr;
        return Prev;
    }

    void Display()
    {
        // Node *ReverseHead = head;
        Node *ReverseHead = Reverse(head);
        while (ReverseHead != nullptr)
        {
            cout << ReverseHead->val << " -->";
            ReverseHead = ReverseHead->next;
        }
        cout << "Null \n";
    }
};

int main()
{

    LL list;
    list.Insert(10);
    list.Insert(20);
    list.Insert(30);
    list.Insert(40);
    list.Insert(50);
    list.Display();

    return 0;
}