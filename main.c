#include <stdio.h>
#include "mymalloc.h"

typedef struct node{
    int data;
    struct node *next;
}node_t;

node_t *newNode(int val){
    node_t *temp = (node_t *)MyMalloc(sizeof(node_t));
    temp->data = val;
    return temp;
}

node_t *insertBegin(node_t *head, int val){
    node_t *temp = newNode(val);
    temp->next = head;
    head = temp;
}

node_t *insertEnd(node_t *head, int val){
    node_t *temp = newNode(val);
    node_t *ptr = head;
        
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    temp->next = NULL;
    ptr->next = temp;

   return head;
}

node_t *insertBefore(node_t *head, int insert, int val){
    node_t *temp = newNode(val);
    node_t *ptr = head;

    while(ptr->next->data != insert){
        if(ptr->next->next == NULL){
            printf("Eror!\n");
            return head;
        }
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

node_t *insertAfter(node_t *head, int insert, int val){
    node_t *temp = newNode(val);
    node_t *ptr = head;

    while(ptr->data != insert){
        if(ptr->next == NULL){
            printf("Eror!\n");
            return head;
        }
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;
    return head;
}

node_t *deleteBegin(node_t *head){
    node_t *ptr = head;

    if(ptr == NULL){
        printf("Under flow\n");
        return head;

    }else{
        head = head->next;
        MyFree(ptr);
        return head;
    }
}

node_t *deleteEnd(node_t *head){
    node_t *ptr = head;

    if(ptr == NULL){
        printf("Under flow\n");
        return head;

    }else{
       while(ptr->next->next != NULL){
           ptr = ptr->next;
       }

        MyFree(ptr->next);
        ptr->next = NULL;
        return head;
    }
}

node_t *deleteAfter(node_t *head, int delete){
    node_t *ptr = head;
    node_t *ptr2 = ptr;

    if(ptr == NULL){
        printf("Under flow\n");
        return head;

    }else{
       while(ptr2->data != delete){
           printf("Moving\n");
           if(ptr2->next == NULL){
            printf("Eror!\n");
            return head;
        }
           ptr2 = ptr;
           ptr = ptr->next;
       }
        
        node_t *temp = ptr;
        ptr2->next = ptr->next;
        MyFree(temp);
        return head;
    }
}

void count(node_t *head){
    node_t *ptr = head;

    if(ptr == NULL){
        printf("Empty list\n");

    }else{
        int num = 1;
        while(ptr->next != NULL){
            ptr = ptr->next;
            num++;
        }

        printf("Size of list is %d\n", num);
    }
}


void display(node_t *head){
    node_t *ptr = head;

    if(ptr == NULL){
        printf("Empty list\n");

    }else{
        printf("%d-", ptr->data);
        while(ptr->next != NULL){
            ptr = ptr->next;
            printf("%d-", ptr->data);
            
        }

        printf("\n");
    }
}

node_t *deleteEntireList(node_t *head){
    node_t *ptr = head;
    node_t *ptr2 = head;
    head = NULL;

    if(ptr == NULL){
        printf("Under flow\n");
        return head;

    }else{
        ptr = ptr->next;
        ptr2 = ptr;
       while(ptr->next != NULL){
           ptr = ptr->next;
           MyFree(ptr2);
           ptr2 = ptr;
       }
    return head;
       
    }
}

int main(){
    node_t *head = NULL;
    count(head);
    head = insertBegin(head, 10);
    head = insertBegin(head, 20);
    head = insertBegin(head, 30);
    
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);

    head = insertAfter(head, 30, 35);
    head = insertBefore(head, 50, 45);

    head = insertBefore(head, 60, 55);

    count(head);
    display(head);

    head = deleteBegin(head);
    head = deleteBegin(head);

    display(head);  

    head = deleteEnd(head);
    head = deleteEnd(head);

    display(head);
    count(head);
    head = insertEnd(head, 50);
    head = insertEnd(head, 75);
    display(head);
   // head = deleteAfter(head, 20);
    head = deleteEntireList(head);
    
    display(head);
    head = insertBegin(head, 55);
    // head = insertBefore(head, 100, 55);
    // head = insertBefore(head, 200, 55);
    // head = insertBefore(head, 300, 55);
    // head = insertBefore(head, 400, 55);
    // head = insertBefore(head, 500, 55);
    display(head);
   
    return 0;
}