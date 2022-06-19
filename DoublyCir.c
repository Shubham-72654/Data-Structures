// Doubly Circular Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE head,int no, PPNODE tail)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if((*head == NULL) && (*tail == NULL))
    {
        *head = newn;
        *tail = newn;
    }
    else
    {
        newn->next = *head;
        (*head)->prev = newn;
        *head = newn;
        (*head)->prev = *tail;
        (*tail)->next = *head;
    }
}

void InsertLast(PPNODE head,int no, PPNODE tail)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if((*head == NULL) && (*tail == NULL))
    {
        *head = newn;
        *tail = newn;
    }
    else
    {
        (*tail)->next = newn;
        newn->prev = *tail;
        *tail = newn;
        (*tail)->next = *head;
        (*head)->prev = *tail;
    }  
}

void InsertAtPos(PPNODE head, int no, int ipos, PPNODE tail)
{
    int iSize = 0;
    iSize = Count(*head, *tail);

    if((ipos < 1) || (ipos > (iSize + 1)))
    {
        printf("Enter valid position\n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(head, no, tail);
    }
    else if(ipos == (iSize + 1))
    {
        InsertLast(head, no, tail);
    }
    else
    {
        PNODE temp = *head;
        PNODE newn = NULL;
        int iCnt = 0;

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(iCnt = 1; iCnt < (ipos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        newn->next->prev = newn;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE head, PPNODE tail)
{
    if((*head == NULL) && (*tail == NULL))
    {
        return;
    }
    else if(*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        (*tail)->next = (*head)->next;
        free(*head);
        *head = (*tail)->next;
        (*head)->prev = (*tail);
    }
}

void DeleteLast(PPNODE head, PPNODE tail)
{
     if((*head == NULL) && (*tail == NULL))
    {
        return;
    }
    else if(*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        (*head)->prev = (*tail)->prev;
        free(*tail);
        (*tail) = (*head)->prev;
        (*tail)->next = *head;
    }
}

void DeleteAtPos(PPNODE head,int ipos, PPNODE tail)
{
    int iSize = 0;
    iSize = Count(*head, *tail);

    if((ipos < 1) || (ipos > iSize))
    {
        printf("Enter valid position\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(head, tail);
    }
    else if(ipos == iSize)
    {
        DeleteLast(head, tail);
    }
    else
    {
        PNODE temp = *head;
        int iCnt = 0;

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

void Display(PNODE head, PNODE tail)
{
    if((head == NULL) && (tail == NULL))
    {
        printf("NULL\n");
    }
    do
    {
        printf("|%d|-> ",head->data);
        head = head->next;
    } while (head != tail->next);
    printf("NULL\n");
}

int Count(PNODE head, PNODE tail)
{
    int iCnt = 0;
    if((head == NULL) && (tail == NULL))
    {
        printf("NULL\n");
    }
    do
    {
        iCnt++;
        head = head->next;
    } while (head != tail->next);

    return iCnt;
}

int main()
{
    PNODE first = NULL;
    PNODE last = NULL;

    printf("Insert First :\n");
    InsertFirst(&first, 101, &last);
    InsertFirst(&first, 51, &last);
    InsertFirst(&first, 21, &last);
    InsertFirst(&first, 11, &last);
    Display(first, last);
    printf("Number of nodes : %d\n", Count(first, last));

    printf("\nInsert Last :\n");
    InsertLast(&first, 111, &last);
    InsertLast(&first, 121, &last);
    Display(first, last);
    printf("Number of nodes : %d\n", Count(first, last));

    printf("\nInsert At Position :\n");
    InsertAtPos(&first, 105, 5, &last);
    InsertAtPos(&first, 115, 7, &last);
    Display(first, last);
    printf("Number of nodes : %d\n", Count(first, last));

    printf("\nDelete First :\n");
    DeleteFirst(&first, &last);
    Display(first, last);
    printf("Number of nodes : %d\n", Count(first, last));

    printf("\nDelete Last :\n");
    DeleteLast(&first, &last);
    Display(first, last);
    printf("Number of nodes : %d\n", Count(first, last));

    printf("\nDelete At Position :\n");
    DeleteAtPos(&first, 4, &last);
    DeleteAtPos(&first, 5, &last);
    Display(first, last);
    printf("Number of nodes : %d\n", Count(first, last));

    return 0;
}