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

void insert(int data, Node **head){
    if(*head == NULL){
        Node *n = createLast(data);
        (*head) = n;
        return;
    }
    Node *cursor = (*head);
    if(cursor->data > data){
        Node *newNode = createLast(data);
        newNode->next = cursor;
        (*head) = newNode;
        return;       
    }

    while(cursor->next != NULL){
        if(cursor->next->data > data){
            Node *newNode = createLast(data);
            newNode->next = cursor->next;
            cursor->next = newNode;
            return;
        }
        cursor = cursor->next;
    }
    cursor->next = createLast(data);
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

int main(){
    Node *list = NULL;
    insert(10, &list);
    insert(20, &list);
    insert(30, &list);
    insert(50, &list);
    insert(40, &list); 
    insert(80, &list);  
    insert(8, &list);  
    
    printList(list);

    printf("size is : %d\n", size(list));
    return 0;
}