#include<iostream>
#include<cstdlib>
using namespace std;

struct Node
{
    int data;
    struct Node *next; // Self referencing structure
};

struct Node *display(struct Node *head){
    cout<<"the Circular linked list is"<<endl;
    struct Node *ptr = head;
    int i = 1;
    do{
        cout<<"the "<<i<<" element is: "<<ptr->data;
        cout<<endl;
        i++;
        ptr = ptr->next;
    }while(ptr != head);
    return head;
};
struct Node *InsertAtBegning(struct Node *head,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node)) ;
    ptr->data = data;
    struct Node *p = head->next;
    while(ptr->next != head){
        p = p->next;
    };
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head; 
};

int main(){
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *sec = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = sec;

    sec->data = 20;
    sec->next = third;

    third->data = 30;
    third->next =fourth;

    fourth->data = 40;
    fourth->next = head;  //it will not point to null instead it will point to head node

    display(head);
    head =  InsertAtBegning(head , 50);
    display(head);


    return 0;
}