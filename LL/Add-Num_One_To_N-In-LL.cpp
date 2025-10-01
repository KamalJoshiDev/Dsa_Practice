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

    Node *Reverse()
    {
        Node *Curr = head;
        Node *Prev = NULL;

        while (Curr != nullptr)
        {
            Node *Temp = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = Temp;
        }
        return Prev;
    }

    void Add_Number_In_List(int Num)

    {
        head = Reverse();
        Node *temp = head;

        int Carry = Num;

        while (temp != nullptr)
        {
            int Sum = temp->val + Carry;
            temp->val = Sum % 10;
            Carry = Sum / 10;

            if (Carry == 0)
                break;

            if (temp->next == nullptr && Carry)
            {
                temp->next = new Node(Carry);
                Carry = 0;
            }
            temp = temp->next;
        }
        head = Reverse();
    }

    void Display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main()
{
    LL lst;
    lst.Insert(3);
    lst.Insert(2);
    lst.Insert(9); // Number is 9->2->3 (or 923)

    cout << "Original Number: ";
    lst.Display();

    lst.Add_Number_In_List(3);

    cout << "After Adding 1: ";
    lst.Display();
    return 0;
}