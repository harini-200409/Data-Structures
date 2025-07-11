#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head=NULL;

void insertAtEnd(int data){
    struct Node *newNode =(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;

    if(head==NULL){
        head=newNode;
    }else{
        struct Node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

void display(){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void deleteAfter(struct Node *prev){
    struct Node *toDelete=prev->next;
    prev->next=toDelete->next;
    free(toDelete);
}

void deleteHead(){
    struct Node *temp=head;
    head=head->next;
    free(temp);
}

int countNodes(){
    int count=0;
    struct Node *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

int josephus(int k){
    if(head==NULL)
    return -1;
    struct Node *temp=head;
    struct Node *prev=NULL;
    while(countNodes()>1){
        for(int i=1;i<k;i++){
            prev=temp;
            temp=temp->next;
            if(temp==NULL){ 
                temp=head;
                prev=NULL;  
            }
        }
        if(temp==head){
            printf("Eliminated: %d\n",temp->data);
            deleteHead();
            temp=head; 
        } else {
            printf("Eliminated: %d\n",temp->data);
            deleteAfter(prev);
            temp=prev->next ?prev->next:head; 
        }
    }
    return head->data; 
}
int main(){
    int N,k;
    printf("Enter number of players (N): ");
    scanf("%d",&N);
    printf("Enter step count (k): ");
    scanf("%d",&k);
    for(int i=1;i<=N;i++){
        insertAtEnd(i);
    }
    printf("\nInitial players:\n");
    display();
    int lastPlayer=josephus(k);
    printf("\nLast remaining player is: %d\n",lastPlayer);
    return 0;
}
