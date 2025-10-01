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

    Node *Odd_Even()
    {
        if (!head || !head->next)
            return head;

        Node *Odd = head;
        Node *Even = head->next;
        Node *EvenStart = Even; // store Even start

        while (Even && Even->next)
        {
            Odd->next = Even->next;
            Odd = Odd->next;

            Even->next = Odd->next;
            Even = Even->next;
        }

        Odd->next = EvenStart; // attach Even list at end
        return head;
    }

    void Display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << " --> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    LL lst;
    lst.Insert(5);
    lst.Insert(4);
    lst.Insert(3);
    lst.Insert(2);
    lst.Insert(1);

    cout << "Before: ";
    lst.Display();

    lst.head = lst.Odd_Even();

    cout << "After:  ";
    lst.Display();

    return 0;
}
