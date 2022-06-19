// Singly Linear Linked List which take input from user

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int No)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        PNODE temp = *Head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void InsertAtPos(PPNODE Head, int No, int iPos)
{
    int iSize = 0;
    iSize = Count(*Head);

    if((iPos < 1) || (iPos > iSize+1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head, No);
    }
    else if(iPos == (iSize + 1))
    {
        InsertLast(Head, No);
    }
    else
    {
        PNODE temp = *Head;
        PNODE newn = NULL;
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = No;
        newn->next = NULL;

        int iCnt = 0;

        for (iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;

    if(temp == NULL)
    {
        return;
    }
    else if(temp->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = temp->next;
        free(temp);
    }

}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(temp == NULL)
    {
        return;
    }
    else if(temp->next == NULL)
    {
        free(temp);
        temp = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE Head, int iPos)
{
    int iSize = 0;
    iSize = Count(*Head);

    if((iPos < 1) || (iPos > iSize))
    {
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head);
    }
    else if(iPos == iSize)
    {
        DeleteLast(Head);
    }
    else
    {
        PNODE temp = *Head;
        PNODE Deltemp = NULL;
        int iCnt = 0;

        for (iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp->next;
        }
        Deltemp = temp->next;
        temp->next = Deltemp->next;
        free(Deltemp);
    }
}

void Display(PNODE Head)
{
    PNODE temp = Head;
    while(temp != NULL)
    {
        printf("|%d|-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    PNODE temp = Head;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

// Entry Point Function
int main()
{
    PNODE first = NULL;
    int no = 0, iValue = 1, position = 0, iRet = 0;

    while(iValue != 0)
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

        switch(iValue)
        {
            case 1:
                printf("Enter number : ");
                scanf("%d", &no);
                InsertFirst(&first, no);
                break;

            case 2:
                printf("Enter number : ");
                scanf("%d", &no);
                InsertLast(&first, no);
                break;

            case 3:
                printf("Enter number : ");
                scanf("%d", &no);
                printf("Enter the position : ");
                scanf("%d", &position);
                InsertAtPos(&first, no, position);
                break;

            case 4:
                DeleteFirst(&first);
                break;

            case 5:
                DeleteLast(&first);
                break;

            case 6:
                printf("Enter the position : ");
                scanf("%d", &position);
                DeleteAtPos(&first, position);
                break;

            case 7:
                Display(first);
                break;

            case 8:
                iRet = Count(first);
                printf("Number of nodes are : %d\n", iRet);
                break; 

            case 9:
                printf("Thanks for using the application");
                iValue = 0;
                break;

            default:
                printf("\nEnter Valid Input\n");
                break;
        }   // end of switch
    }   // end of while

    return 0;
}