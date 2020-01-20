#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

void insertNodeAtFirst(int data);
void insertNodeAtLast(int data);
int listSize(void);
void searchForItemInList(int data);
void updateItemInTheList(int old, int new);
void removeNodeFromTheList(int data);
void printList(void);

struct node * HEAD = NULL;
struct node * current = NULL;

int main()
{
    int size=0;
    insertNodeAtLast(10);
    insertNodeAtLast(20);
    insertNodeAtLast(30);
    printList();
    size=listSize();
    printf("\nsize=%d",size);
    searchForItemInList(20);
    updateItemInTheList(20,50);
    printList();
    removeNodeFromTheList(50);
    printList();
    return 0;
}

void removeNodeFromTheList(int data)
{
    struct node * ptr=HEAD;
    struct node * delete_node=NULL;
    struct node * prev=NULL;
    current=HEAD;
    if(ptr == NULL)
    {
        printf("Emtpy Linkedlist.. Item not found!\n");
        return;
    }
    if(HEAD->data==data)
    {
        delete_node=HEAD;
        HEAD=HEAD->next;
        free(delete_node);
    }
    ptr=HEAD->next;
    prev=HEAD;
    while(ptr != NULL)
    {
        if(ptr->data == data)
        {
            delete_node=ptr;
            prev->next=ptr->next;
            free(delete_node);
            return;
        }
        ptr=ptr->next;
        prev=prev->next;
    }
    printf("\nItem not found!\n");
}

void updateItemInTheList(int old_item, int new_item)
{
    struct node * ptr=HEAD;
    if(ptr == NULL)
    {
        printf("Emtpy Linkedlist.. Item not found!\n");
        return;
    }
    while(ptr != NULL)
    {
        if(ptr->data == old_item)
        {
            ptr->data=new_item;
            return;
        }
        ptr=ptr->next;
    }
    printf("\nItem not found in list!\n");
}

void searchForItemInList(int data)
{
    int index=0;
    struct node * ptr = HEAD;
    if(ptr == NULL)
    {
        printf("Emtpy Linkedlist.. Item not found!\n");
        return;
    }
    while(ptr != NULL)
    {
        if(ptr->data == data)
        {
            printf("\n%d is found in node number %d\n",data,index);
            return;
        }
        index++;
        ptr=ptr->next;
    }
    printf("Empty not found!\n");
}

int listSize(void)
{
    int count=0;
    struct node * ptr = HEAD;
    if(ptr == NULL)
    {
        printf("Empty Linkedlist");
        return;
    }
    while(ptr != NULL)
    {
        count++;
        ptr=ptr->next;
    }
    return count;
}

void insertNodeAtLast(int data)
{
    struct node * link = (struct node*)malloc(sizeof(struct node));
    link->data=data;
    link->next=NULL;
    if(HEAD == NULL)
    {
        HEAD=link;
        return;
    }
    current=HEAD;
    while(current->next != NULL)
    {
        current=current->next;
    }
    current->next=link;
}

void insertNodeAtFirst(int data)
{
    struct node * link = HEAD;
    link = (struct node*)malloc(sizeof(struct node));

    link->data=data;
    link->next=HEAD;
    HEAD=link;
}

void printList(void)
{
    struct node * ptr = HEAD;
    if(ptr == NULL)
    {
        printf("Emtpy Linkedlist!");
        return;
    }
    printf("[HEAD] -> ");
    while(ptr != NULL)
    {
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("[NULL]\n");
}
