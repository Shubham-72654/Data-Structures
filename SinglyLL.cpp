// Singly Linear Lineked List

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class SinglyLL
{
    private:
        PNODE head;
        int iCount;

    public:
        SinglyLL();
        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int CountNode();
};

SinglyLL::SinglyLL()
{
    head = NULL;
    iCount = 0;
}

void SinglyLL::InsertFirst(int no)
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
        newn->next = head;
        head = newn;
    }
    iCount++;
}

void SinglyLL::InsertLast(int no)
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

void SinglyLL::InsertAtPos(int no, int ipos)
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

void SinglyLL::DeleteFirst()
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
        PNODE temp = head;
        
        head = head->next;
        delete (temp);
    }
    iCount--;
}

void SinglyLL::DeleteLast()
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
        PNODE temp = head;
        
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
    }
    iCount--;
}

void SinglyLL::DeleteAtPos(int ipos)
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

void SinglyLL::Display()
{
    PNODE temp = head;
    while(temp != NULL)
    {
        cout << "|" << temp->data << "|-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int SinglyLL::CountNode()
{
    return iCount;
}

int main()
{
    SinglyLL obj;

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