#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        return 1;
    }
    
    new_node -> data = data;
    new_node -> next = NULL;
    
    return new_node;
}
struct node* createlist(){
    int n;
    struct node *head = NULL;
    struct node *new_node = NULL;
    struct node *temp = NULL;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    if (n <= 0){
        printf("Error!");
        return NULL;
    }

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
        printf("%d -> ", temp->data);

        temp = temp->next;
    }
    printf("NULL\n");
    
}

struct node* insert(struct node* head, int position, int newdata){
    if (position < 1){
        printf("Error!\n");
        return;
    }
    struct node* new_node = createnode(newdata);
    
    if (position == 1){
        new_node -> next = head;
        head = new_node;
        return head;
    } 
    struct node *temp = head;
    for (int i = 1; i < position - 1; i++){
        if (temp == NULL){
            break;
        }
        temp = temp -> next;
    }
    
    if (temp == NULL){
        printf("Error!\n");
        free(new_node);
        return head;
    }
        
    new_node -> next = temp -> next;
    temp -> next = new_node;
        
    return head;
        
}

struct node* delete(struct node* head, int position){
    if (position < 1 || head == NULL){
        printf("Error!\n");
        return;
    }
    struct node *nodetodelete;
    struct node *temp = head;
    
    if (position == 1){
        head = temp -> next;
        free(temp);
        return head;
    }
    
    for (int i = 1; i < position - 1; i++){
        if (temp == NULL){
            break;
        }
        temp = temp -> next;
    }
    if (temp == NULL || temp -> next == NULL){
        printf("Error!\n");
        free(temp);
        return head;
    }
    
    nodetodelete = temp -> next;
    temp -> next = nodetodelete -> next;
    
    free(nodetodelete);
    
    return head;
    
}

int main(){
    struct node* head = createlist();
    int n;
    int position;
    int data;
    int choice;

    printf("Initial List: \n");
    printf("Linked List: ");
    displaylist(head);
    printf("\n");

    
    
    while (head){
        printf("\nMenu: \n");
        printf("1.Insert at a position\n2.Delete at a position\n3.Display List\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1){
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            head = insert(head, position, data);
            printf("Node inserted.\n");
        }
        
        else if (choice == 2){
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            head = delete(head, position);
            printf("Node deleted.\n");
        }
        
        else if (choice == 3){
            printf("Linked List: ");
            displaylist(head);
        }
        
        else if (choice == 4){
            printf("Exiting program.\n");
            exit(1);
        }
    } 
    
    printf("\n");

    struct node *temp;
    while (head != NULL){
        temp = head;
        head = head -> next;
        free(temp);
    }

    return 0;
}
