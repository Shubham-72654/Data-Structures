// Singly Circular Lineked List

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class SinglyCir
{
    private:
        PNODE head;
        PNODE tail;
        int iCount;

    public:
        SinglyCir();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int CountNode();
};

SinglyCir::SinglyCir()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}

void SinglyCir::InsertFirst(int no)
{
    PNODE newn = NULL;
    newn = new NODE();
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

void SinglyCir::InsertLast(int no)
{
    PNODE newn = NULL;
    newn = new NODE();
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

void SinglyCir::InsertAtPos(int no, int ipos)
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

void SinglyCir::DeleteFirst()
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

void SinglyCir::DeleteLast()
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
        PNODE temp = head;
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

void SinglyCir::DeleteAtPos(int ipos)
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
        deltemp = temp->next;
        temp->next = deltemp->next;
        delete (deltemp);

        iCount--;
    }
}

void SinglyCir::Display()
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

int SinglyCir::CountNode()
{
    return iCount;
}

int main()
{
    SinglyCir obj;

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