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

    void CreateCycle(int Position)
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        Node *CycleNode = nullptr;

        int Count = 0;
        while (temp->next != nullptr)
        {
            if (Count == Position)
            {
                CycleNode = temp;
            }
            temp = temp->next;
            Count++;
        }
        temp->next = CycleNode;
        cout << " Cycle At : " << CycleNode->val << " \n";
        // delete temp;
    }
    void DectedCycle(Node *head)
    {
        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            /* code */
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                cout << "Find Cycle At Node Data -->  : " << slow->val;
                return;
            }
        }
        cout << "No Cycle detected" << endl;
    }
};
int main()
{
    LL lst;
    lst.Insert(0);
    lst.Insert(1);
    lst.Insert(2);
    lst.Insert(4);
    lst.Insert(5);
    lst.Insert(6);
    lst.Insert(7);
    lst.Insert(8);
    lst.CreateCycle(4);
    lst.DectedCycle(lst.head);
    return 0;
}