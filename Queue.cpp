// Queue (First in First out)

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class Queue
{
    private:
        PNODE head;
        int iCount;
    
    public:
        Queue();
        void Enqueue(int);     // insertLast
        void Dequeue();         // deleteFirst
        void Display();
        int CountNode();
};

Queue::Queue()
{
    head = NULL;
    iCount = 0;
}

void Queue::Enqueue(int no)     // insertlast
{
    PNODE newn = NULL;

    newn = new NODE();
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        PNODE temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;
}

void Queue::Dequeue()   // deletefirst
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

void Queue::Display()
{
    PNODE temp = head;
    while(temp != NULL)
    {
        cout << "|" << temp->data << "|-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int Queue::CountNode()
{
    return iCount;
}

int main()
{
    Queue obj;

    obj.Enqueue(1);
    obj.Enqueue(2);
    obj.Enqueue(3);
    obj.Enqueue(4);
    obj.Enqueue(5);
    obj.Display();
    cout << "Number of nodes : " << obj.CountNode() << endl;

    obj.Dequeue();
    obj.Display();
    cout << "Number of nodes : " << obj.CountNode() << endl;

    return 0;
}