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

    bool isPalindrome(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        Node *slow = head;
        Node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node *ReverseNode = Reverse(slow); //! Edge Case If Odd Length
        Node *FirstHalf = head;
        Node *secondHalf = ReverseNode;

        while (secondHalf != nullptr)
        {
            if (FirstHalf->val != secondHalf->val)
            {
                return false;
            }
            FirstHalf = FirstHalf->next;
            secondHalf = secondHalf->next;
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
    lst.Insert(3);
    lst.Insert(2);
    lst.Insert(1);
    cout << lst.isPalindrome(lst.head);
    return 0;
}