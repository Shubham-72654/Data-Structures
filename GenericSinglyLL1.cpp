// Generic Singly Linear Lineked List (get input from user)

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


class DataX
{
    public:
        int position = 0, iRet = 0;

        void intX()
        {
            SinglyLL<int> obj;
            int no = 0, iValue = 1;

            cout << "Insert only integers" << endl;
            while (iValue != 0)
            {
                printf("1.  InsertFirst\n");
                printf("2.  InsertLast\n");
                printf("3.  InsertAtPos\n");
                printf("4.  DeleteFirst\n");
                printf("5.  DeleteLast\n");
                printf("6.  DeleteAtPos\n");
                printf("7.  Display\n");
                printf("8.  Count\n");
                printf("9.  Terminate the application\n");
                scanf("%d", &iValue);

                switch (iValue)
                {
                    case 1:
                        printf("Enter number : ");
                        scanf("%d", &no);
                        obj.InsertFirst(no);
                        break;

                    case 2:
                        printf("Enter number : ");
                        scanf("%d", &no);
                        obj.InsertLast(no);
                        break;

                    case 3:
                        printf("Enter number : ");
                        scanf("%d", &no);
                        printf("Enter the position : ");
                        scanf("%d", &position);
                        obj.InsertAtPos(no, position);
                        break;

                    case 4:
                        obj.DeleteFirst();
                        break;

                    case 5:
                        obj.DeleteLast();
                        break;

                    case 6:
                        printf("Enter the position : ");
                        scanf("%d", &position);
                        obj.DeleteAtPos(position);
                        break;

                    case 7:
                        obj.Display();
                        break;

                    case 8:
                        iRet = obj.CountNode();
                        printf("Number of nodes are : %d\n", iRet);
                        break; 

                    case 9:
                        printf("\nWelcome back to main application...\n");
                        iValue = 0;
                        break;

                    default:
                        printf("\nEnter Valid Input\n");
                        break;
                }   // end of switch
            }   // end of while
        }   // end of intX


        ///////////////////////////////////////////// float /////////////////////////////////////////////

        void floatX()
        {
            SinglyLL <float>obj1;
            float fno = 0;
            int fValue = 1;

            cout << "\nInsert only floats" << endl;
            while(fValue != 0)
            {
                printf("1.  InsertFirst\n");
                printf("2.  InsertLast\n");
                printf("3.  InsertAtPos\n");
                printf("4.  DeleteFirst\n");
                printf("5.  DeleteLast\n");
                printf("6.  DeleteAtPos\n");
                printf("7.  Display\n");
                printf("8.  Count\n");
                printf("9.  Terminate the application\n");
                scanf("%d", &fValue);

                switch(fValue)
                {
                    case 1:
                        printf("Enter number : ");
                        scanf("%f", &fno);
                        obj1.InsertFirst(fno);
                        break;

                    case 2:
                        printf("Enter number : ");
                        scanf("%f", &fno);
                        obj1.InsertLast(fno);
                        break;

                    case 3:
                        printf("Enter number : ");
                        scanf("%f", &fno);
                        printf("Enter the position : ");
                        scanf("%d", &position);
                        obj1.InsertAtPos(fno, position);
                        break;

                    case 4:
                        obj1.DeleteFirst();
                        break;

                    case 5:
                        obj1.DeleteLast();
                        break;

                    case 6:
                        printf("Enter the position : ");
                        scanf("%d", &position);
                        obj1.DeleteAtPos(position);
                        break;

                    case 7:
                        obj1.Display();
                        break;

                    case 8:
                        iRet = obj1.CountNode();
                        printf("Number of nodes are : %d\n", iRet);
                        break; 

                    case 9:
                        printf("\nWelcome back to main application...\n");
                        fValue = 0;
                        break;

                    default:
                        printf("\nEnter Valid Input\n");
                        break;
                }   // end of switch
            }   // end of while
        } // end of floatX
};

int main()
{
    
    char ch[10];
    int value = 1;
    DataX dobj;

    while(value != 0)
    {
        cout << "select for insert which type of values...." << endl;
        cout << "1. For integer values" << endl;
        cout << "2. For float values" << endl;
        cout << "3. Terminate the application" << endl;
        cin >> value;

        switch (value)
        {
            case 1:
                dobj.intX();
                break;
            
            case 2:
                dobj.floatX();
                break;
            
            case 3:
                cout << "Thanks to visit my application" << endl;
                value = 0;
                break;

            default:
                cout << "Invalid input" << endl;
                break;
        }
    }

    return 0;
}
