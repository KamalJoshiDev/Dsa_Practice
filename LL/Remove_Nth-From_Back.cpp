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

    int GetLength()
    {
        Node *temp = head;
        int Count = 0;

        while (temp != nullptr)
        {
            Count++;
            temp = temp->next;
        }
        return Count;
    }
    void Remove_Nth_From_Back(int N)
    {
        Node *temp = head;
        int Length = GetLength();
        if (N > Length)
            return;

        int DeletePosition = Length - N;

        if (DeletePosition == 0)
        {
            Node *Delete = head;
            head = head->next;
            delete Delete;
            return;
        }

        for (int i = 1; i < DeletePosition; i++)
        {
            temp = temp->next;
        }
        Node *Delete = temp->next;
        temp->next = temp->next->next;
        delete Delete;
    }

    void Remove_Nth_Slow_Fast(int N)
    {
        int Length = GetLength();
        if (Length == N)
        {
            cout << "Delete From Edge Case -->> \n";
            Node *Delete = head;
            head = head->next;
            delete Delete;
            return;
        }
        Node *slow = head;
        Node *fast = head;

        for (int i = 0; i <= N; i++)
        {
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        Node *Delete = slow->next;
        slow->next = slow->next->next;
        delete Delete;
    }
  
  
    void Display()
    {
        Node *temp = head;
        while (temp != nullptr)
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

    cout << "Original List: ";
    lst.Display();

    // lst.Remove_Nth_From_Back(4);
    lst.Remove_Nth_Slow_Fast(5);

    cout << "After Deletion: ";
    lst.Display();
    return 0;
}