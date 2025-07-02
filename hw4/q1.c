#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node* next;
};


struct node* createlist(){
    int n;
    struct node *head = NULL;
    struct node *new_node = NULL;
    struct node *temp = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        new_node = (struct node *)malloc(sizeof(struct node));
        if (new_node == NULL){
            return 1;
        }
        printf("Enter value for node %d: ", i+1);
        scanf("%d", &new_node->data);

        new_node-> next= NULL;

        if (head == NULL){
            head = new_node;
        }
        else{
            temp -> next = new_node;
        }
        temp = new_node;
    }
    return head;
        
}


void displaylist(struct node* head){
    struct node *temp = head;
    
    while(temp!= NULL){
        printf("%d ", temp->data);

        temp = temp->next;
    }
    printf("\n");
    
}

struct node* insert(struct node* head, int newdata){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        return 1;
    }

    new_node->data = newdata;
    new_node -> next = head;
    
    return new_node;
}

int main(){
    struct node* head = createlist();
    int n;

    printf("\n");
    printf("Linked List before insertion: \n");
    printf("Linked List: ");
    displaylist(head);
    
    printf("\n");

    printf("Enter a value to insert at the beginning: ");
    scanf("%d", &n);
    head = insert(head, n);
    
    printf("\n");

    printf("Linked List after insertion: \n");
    printf("Linked List: ");
    displaylist(head);
    
    printf("\n");

    free(head);

    return 0;
}
