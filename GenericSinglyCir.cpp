// Generic Singly Circular Lineked List

#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyCir
{
    private:
        struct node<T> *head;
        struct node<T> *tail;
        int iCount;

    public:
        SinglyCir();
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
SinglyCir<T>::SinglyCir()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

template <class T>
void SinglyCir<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
        tail->next = newn; // tail->next = head;
    }
    iCount++;
}

template <class T>
void SinglyCir<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        tail->next = newn;
        tail = newn;
        tail->next = head;
    }
    iCount++;
}

template <class T>
void SinglyCir<T>::InsertAtPos(T no, int ipos)
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
void SinglyCir<T>::DeleteFirst()
{
    if((head == NULL) && (tail == NULL))
    {
        return;
    }
    else if(head == tail)
    {
        delete (head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail->next = tail->next->next; // head = head->next;
        delete (head);                 // delete(tail->next);
        head = tail->next;             // tail->next = head;
    }
    iCount--;
}

template <class T>
void SinglyCir<T>::DeleteLast()
{
    if((head == NULL) && (tail == NULL))
    {
        return;
    }
    else if(head == tail)
    {
        delete (head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        struct node<T> *temp = head;
        while(temp->next != tail)
        {
            temp = temp->next;
        }
        delete (tail);
        tail = temp;
        tail->next = head;
    }
    iCount--;
}

template <class T>
void SinglyCir<T>::DeleteAtPos(int ipos)
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
void SinglyCir<T>::Display()
{
    if((head == NULL) && (tail == NULL))
    {
        return;
    }
    do
    {
        cout << "|" << head->data << "|-> ";
        head = head->next;
    } while (head != tail->next);
    cout << "NULL" << endl;
}

template <class T>
int SinglyCir<T>::CountNode()
{
    return iCount;
}

int main()
{
    SinglyCir <int>obj;

    cout << "Integer Values : " << endl;
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

    cout << "--------------------------------------float-----------------------------------------" << endl;
    SinglyCir <float>obj1;

    cout << "Float Values : " << endl;
    cout << "Insert First" << endl;
    obj1.InsertFirst(101.23);
    obj1.InsertFirst(51.14);
    obj1.InsertFirst(21.84);
    obj1.InsertFirst(11.87);
    obj1.Display();
    cout << "Number of nodes are : " << obj1.CountNode() << endl;

    cout << "\nInsert Last" << endl;
    obj1.InsertLast(121.34);
    obj1.InsertLast(151.65);
    obj1.Display();
    cout << "Number of nodes are : " << obj1.CountNode() << endl;

    cout << "\nInsert At Position" << endl;
    obj1.InsertAtPos(30.43, 3);
    obj1.InsertAtPos(150.15, 8);
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