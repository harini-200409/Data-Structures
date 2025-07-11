#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node 
{
    char hint[100];
    struct Node *next;
};
struct Node *head=NULL;
void insertAtEnd(char *hint)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->hint, hint);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)  
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void displayHint()
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%s\n",temp->hint);
        temp=temp->next;
    }
}
int main()
{
    int choice;
    char hint[100];
    while(1)
    {
        printf("1 . Add Hint\n2 . Display Hint\n3 . Exit\n4 . Enter the choice : ");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:
            {
                fgets(hint,sizeof(hint),stdin);
                hint[strcspn(hint,"\n")]=0;
                insertAtEnd(hint);
                break;
            }
            case 2: 
            {
                displayHint();
                break;
            }
            case 3:
            {
                exit(0);
            }
            default:
            printf("Invalid input choice");
        }
    }
    return 0;
}
