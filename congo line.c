#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char congo[100];
    struct Node *next;
    struct Node *prev;
};
struct Node *head=NULL;
struct Node *tail=NULL;
//insertAtEnd
void congoLine(char *congo)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->congo,congo);
    newNode->next=NULL;
    newNode->prev=tail;
    if(tail!=NULL)
    {
        tail->next=newNode;
    }
    else
    {
        head=newNode;
    }
    tail=newNode;
}
void display()
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%s\n",temp->congo);
        temp=temp->next;
    }
    
}
int main()
{
    int i,n;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        char congo[100];
        fgets(congo, sizeof(congo), stdin);
        for (int j = 0; congo[j] != '\0'; j++)
        {
            if (congo[j] == '\n')
            {
                congo[j] = '\0';
                break;
            }
        }
        congoLine(congo);
    }
    printf("\n");
    display();
    printf("\n");
}
