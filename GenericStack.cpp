// Generic Stack (Last in First out)

#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class Stack
{
    private:
        struct node<T> *head;
        int iCount;
    
    public:
        Stack();
        void Push(T);     // insertfirst
        void Pop();         // deletefirst
        void Display();
        int CountNode();
};

template <class T>
Stack<T>::Stack()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::Push(T no)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    newn->next = head;
    head = newn;

    iCount++;
}

template <class T>
void Stack<T>::Pop()
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
void Stack<T>::Display()
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
int Stack<T>::CountNode()
{
    return iCount;
}

int main()
{
    Stack <int>sobj;

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

    cout << "-------------------------------------Character-----------------------------------------" << endl;
    Stack <char>sobj1;

    sobj1.Push('M');
    sobj1.Push('A');
    sobj1.Push('H');
    sobj1.Push('B');
    sobj1.Push('U');
    sobj1.Push('H');
    sobj1.Push('S');
    sobj1.Display();
    cout << "Number of nodes : " << sobj1.CountNode() << endl;

    sobj1.Pop();
    sobj1.Display();
    cout << "Number of nodes : " << sobj1.CountNode() << endl;

    return 0;
}