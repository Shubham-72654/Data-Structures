// Generic Singly Linear Lineked List

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLL
{
    private:
        struct node<T> *head;
        int iCount;

    public:
        SinglyLL();
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
SinglyLL<T>::SinglyLL()
{
    head = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
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
        newn->next = head;
        head = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
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
void SinglyLL<T>::InsertAtPos(T no, int ipos)
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
        newn->next = NULL;

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
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
        
        head = head->next;
        delete (temp);
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
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
void SinglyLL<T>::DeleteAtPos(int ipos)
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
        deltemp = temp->next;
        temp->next = deltemp->next;
        delete (deltemp);

        iCount--;
    }
}

template <class T>
void SinglyLL<T>::Display()
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
int SinglyLL<T>::CountNode()
{
    return iCount;
}

int main()
{
    SinglyLL <int>obj;

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

    return 0;
}