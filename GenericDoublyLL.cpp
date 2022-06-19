// Generic Doubly Linear Lineked List

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *prev;
    struct node *next;
};

template <class T>
class DoublyLL
{
    private:
        struct node<T> *head;
        int iCount;

    public:
        DoublyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int CountNode();
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->prev = NULL;
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
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int ipos)
{
    int iSize = 0;
    iSize = CountNode();

    if((ipos < 1) || (ipos > (iSize + 1)))
    {
        cout << "Invalid Position" << endl;
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == (iSize + 1))
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> *temp = head;
        struct node<T> *newn = NULL;
        int iCnt = 0;

        newn = new node<T>;
        newn->data = no;
        newn->prev = NULL;
        newn->next = NULL;

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        newn->next->prev = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete (head);
        head = NULL;
    }
    else
    {
        head = head->next;
        delete(head->prev);
        head->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(head == NULL)
    {
        return;
    }
    else if(head->next == NULL)
    {
        delete (head);
        head = NULL;
    }
    else
    {
        struct node<T> *temp = head;
        
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
    int iSize = 0;
    iSize = CountNode();

    if((ipos < 1) || (ipos > iSize))
    {
        cout << "Invalid Position" << endl;
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == iSize)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> *temp = head;
        struct node<T> *deltemp = NULL;
        int iCnt = 0;

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;

        iCount--;
    }
}

template <class T>
void DoublyLL<T>::Display()
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
int DoublyLL<T>::CountNode()
{
    return iCount;
}

int main()
{
    DoublyLL <int>obj;

    cout << "Insert First" << endl;
    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    cout << "Number of nodes are : " << obj.CountNode() << endl;

    cout << "\nInsert Last" << endl;
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.Display();
    cout << "Number of nodes are : " << obj.CountNode() << endl;

    cout << "\nInsert At Position" << endl;
    obj.InsertAtPos(30, 3);
    obj.InsertAtPos(150, 8);
    obj.Display();
    cout << "Number of nodes are : " << obj.CountNode() << endl;

    cout << "\nDelete First" << endl;
    obj.DeleteFirst();
    obj.Display();
    cout << "Number of nodes are : " << obj.CountNode() << endl;

    cout << "\nDelete Last" << endl;
    obj.DeleteLast();
    obj.Display();
    cout << "Number of nodes are : " << obj.CountNode() << endl;

    cout << "\nDalate At Position" << endl;
    obj.DeleteAtPos(6);
    obj.DeleteAtPos(2);
    obj.Display();
    cout << "Number of nodes are : " << obj.CountNode() << endl; 
    

    ////////////////////   float  /////////////////////////
    cout << "\n-----------------------------------------Float----------------------------------------" << endl;
    DoublyLL <float>obj1;

    cout << "Insert First" << endl;
    obj1.InsertFirst(10.5);
    obj1.InsertFirst(8.5);
    obj1.InsertFirst(5.6);
    obj1.InsertFirst(2.8);
    obj1.Display();
    cout << "Number of nodes are : " << obj1.CountNode() << endl;

    cout << "\nInsert Last" << endl;
    obj1.InsertLast(14.8);
    obj1.InsertLast(21.4);
    obj1.Display();
    cout << "Number of nodes are : " << obj1.CountNode() << endl;

    cout << "\nInsert At Position" << endl;
    obj1.InsertAtPos(7.9, 3);
    obj1.InsertAtPos(23.6, 8);
    obj1.Display();
    cout << "Number of nodes are : " << obj1.CountNode() << endl;

    cout << "\nDelete First" << endl;
    obj1.DeleteFirst();
    obj1.Display();
    cout << "Number of nodes are : " << obj1.CountNode() << endl;

    cout << "\nDelete Last" << endl;
    obj1.DeleteLast();
    obj1.Display();
    cout << "Number of nodes are : " << obj1.CountNode() << endl;

    cout << "\nDalate At Position" << endl;
    obj1.DeleteAtPos(6);
    obj1.DeleteAtPos(2);
    obj1.Display();
    cout << "Number of nodes are : " << obj1.CountNode() << endl; 

    return 0;
}