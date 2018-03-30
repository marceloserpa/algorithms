#include <stdio.h>
#include <stdlib.h>

typedef struct node_element {
    int data;
    struct node_element *next;
} Node;

Node* create(int data, Node *next) {
    Node *node = malloc(sizeof(Node)); 
    node->data = data;
    if(next != NULL) node->next = next;
    return node;
}

Node* createLast(int data) {
    return create(data, NULL);
}

void append(int data, Node **head){
    if(*head == NULL){
        Node *n = createLast(data);
        (*head) = n;
        return;
    }
    Node *cursor = (*head);
    while(cursor->next != NULL){
        cursor = cursor->next;
    }
    cursor->next = createLast(data);
}

void addAtStart(int data, Node **head){
    Node *newNode = create(data, NULL);
    newNode->next = (*head);
    (*head) = newNode;
}

void printList(Node *head){    
    Node *cursor = head;
    while(cursor != NULL){
        printf("data: %d\n", cursor->data);
        cursor = cursor->next;
    }
}

int size(Node *list){
    Node *cursor = list;
    int size = 0;
    while(cursor != NULL){
        size++;
        cursor = cursor->next;
    }  
    return size;
}

void deleteByValue(Node **list, int data){
    Node *cursor = *list;
    if(cursor->data == data){        
        Node *first = cursor;    
        *list = cursor->next;
        first->next = NULL;
        free(first);
        return;
    }
    while(cursor != NULL){
        if(cursor->next->data == data) break;        
        cursor = cursor->next;
    }
    Node *tmp = cursor->next;
    cursor->next = tmp->next;
    tmp->next=NULL;
    free(tmp);
}

int main(){
    Node *list = NULL;
    append(7, &list);
    append(1, &list);
    append(3, &list);
    append(8, &list);
    append(6, &list);
    addAtStart(5, &list);
    
    printList(list);
    printf("--------\n");

    deleteByValue(&list, 5); 
    deleteByValue(&list, 1); 
    deleteByValue(&list, 3); 

    printList(list);
    printf("size is : %d\n", size(list));
    return 0;
}