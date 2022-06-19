// Doubly Circular Lineked List

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class DoublyCir
{
    private:
        PNODE head;
        PNODE tail;
        int iCount;

    public:
        DoublyCir();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int CountNode();
};

DoublyCir::DoublyCir()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

void DoublyCir::InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE();
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
        tail->next = head;
        head->prev = tail;
    }
    iCount++;
}

void DoublyCir::InsertLast(int no)
{
    PNODE newn = NULL;
    newn = new NODE();
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        tail->next = newn;
        newn->prev = tail;
        tail = newn;
        tail->next = head;
        head->prev = tail;
    }
    iCount++;
}

void DoublyCir::InsertAtPos(int no, int ipos)
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
        PNODE temp = head;
        PNODE newn = NULL;
        int iCnt = 0;

        newn = new NODE();
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

void DoublyCir::DeleteFirst()
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
        head = head->next; // tail->next = head->next;
        delete (tail->next); // delete(head);
        tail->next = head;   // head = tail->next;
        head->prev = tail;   // head->prev = tail;
    }
    iCount--;
}

void DoublyCir::DeleteLast()
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
        head->prev = tail->prev;
        delete (tail);
        tail = head->prev;
        tail->next = head;
    }
    iCount--;
}

void DoublyCir::DeleteAtPos(int ipos)
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
        PNODE temp = head;
        PNODE deltemp = NULL;
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

void DoublyCir::Display()
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

int DoublyCir::CountNode()
{
    return iCount;
}

int main()
{
    DoublyCir obj;

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