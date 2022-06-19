// Stack (Last in First out)

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class Stack
{
    private:
        PNODE head;
        int iCount;
    
    public:
        Stack();
        void Push(int);     // insertfirst
        void Pop();         // deletefirst
        void Display();
        int CountNode();
};

Stack::Stack()
{
    head = NULL;
    iCount = 0;
}

void Stack::Push(int no)
{
    PNODE newn = NULL;

    newn = new NODE();
    newn->data = no;
    newn->next = NULL;

    newn->next = head;
    head = newn;

    iCount++;
}

void Stack::Pop()
{
    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete(head);
        head = NULL;
    }
    else
    {
        PNODE temp = head;
        head = head->next;
        delete (temp);
    }
    iCount--;
}

void Stack::Display()
{
    PNODE temp = head;
    while(temp != NULL)
    {
        cout << "|" << temp->data << "|-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int Stack::CountNode()
{
    return iCount;
}

int main()
{
    Stack sobj;

    sobj.Push(5);
    sobj.Push(4);
    sobj.Push(3);
    sobj.Push(2);
    sobj.Push(1);
    sobj.Display();
    cout << "Number of nodes : " << sobj.CountNode() << endl;

    sobj.Pop();
    sobj.Display();
    cout << "Number of nodes : " << sobj.CountNode() << endl;

    return 0;
}