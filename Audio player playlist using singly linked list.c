#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node 
{
    char song[100];
    struct Node *next;
};
struct Node *head=NULL;
void insertSong(char *song)
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->song, song);
    newNode->next=head;
    head=newNode;
}
void displaySong()
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%s\n",temp->song);
        temp=temp->next;
    }
}
int main()
{
    int choice;
    char songName[100];
    while(1)
    {
    printf("1 . Add song\n2 . Display Song\n3 . Exit\nEnter your choice : ");
    scanf("%d",&choice);
    getchar();
    switch(choice)
    {
        case 1:
        {
            fgets(songName,sizeof(songName),stdin);
            songName[strcspn(songName,"\n")]=0; //rempve newline
            insertSong(songName);
            break;
        }
        
        case 2:
        displaySong();
        break;
        
        case 3:
        exit(0);
        
        default:
        printf("Enter a valid input\n");
    }
    }
}
/*int main()
{
    char str[5][10]={"aaa","bbb","ccc","ddd","eee"};
    for(int i=0;i<5;i++)
    {
        insertSong(str[i]);
    }
    displaySong();
    
    return 0;
}*/
