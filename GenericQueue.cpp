// Generic Queue (First in First out)

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class Queue
{
    private:
        struct node<T> *head;
        int iCount;
    
    public:
        Queue();
        void Enqueue(T);     // insertLast
        void Dequeue();         // deleteFirst
        void Display();
        int CountNode();
};

template <class T>
Queue<T>::Queue()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void Queue<T>::Enqueue(T no)     // insertlast
{
    struct node<T> *newn = NULL;

    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        struct node<T> *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;
}

template <class T>
void Queue<T>::Dequeue()   // deletefirst
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
        struct node<T> *temp = head;
        head = head->next;
        delete (temp);
    }
    iCount--;
}

template <class T>
void Queue<T>::Display()
{
    struct node<T> *temp = head;
    while(temp != NULL)
    {
        cout << "|" << temp->data << "|-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

template <class T>
int Queue<T>::CountNode()
{
    return iCount;
}

int main()
{
    Queue <int>obj;

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

    cout << "-------------------------------------Character-----------------------------------------" << endl;
    Queue <char>obj1;

    obj1.Enqueue('S');
    obj1.Enqueue('H');
    obj1.Enqueue('U');
    obj1.Enqueue('B');
    obj1.Enqueue('H');
    obj1.Enqueue('A');
    obj1.Enqueue('M');
    obj1.Display();
    cout << "Number of nodes : " << obj1.CountNode() << endl;

    obj1.Dequeue();
    obj1.Dequeue();
    obj1.Display();
    cout << "Number of nodes : " << obj1.CountNode() << endl;

    return 0;
}