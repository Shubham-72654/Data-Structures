// Stack  --->    Last in First out.

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

void Push(PPNODE head, int no)  // insertfirst
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
        
    newn->next = *head;
    *head = newn;
}

void Pop(PPNODE head)   // deletefirst
{
    PNODE temp = *head;

    if(temp == NULL)
    {
        return;
    }
    else if(temp->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        *head = temp->next;
        free(temp);
    }
}

void Display(PNODE head)
{
    PNODE temp = head;
    while(temp != NULL)
    {
        printf("|%d|-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int Count(PNODE head)
{
    PNODE temp = head;
    int iCnt = 0;
    while(temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

int main()
{
    PNODE first = NULL;

    Push(&first, 101);
    Push(&first, 51);
    Push(&first, 21);
    Push(&first, 11);
    Display(first);
    printf("Number of nodes are : %d\n", Count(first));

    printf("\nPop\n");
    Pop(&first);
    Display(first);
    printf("Number of nodes are : %d\n", Count(first));

    return 0;
}