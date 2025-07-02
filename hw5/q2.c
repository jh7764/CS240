#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createnode(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        return 1;
    }
    
    new_node -> data = data;
    new_node -> next = NULL;
    new_node -> prev = NULL;
    
    return new_node;
}
struct node* createinitiallist(){
    int n;
    struct node *head = NULL;
    struct node *tail = NULL;
    struct node *new_node = NULL;
    
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
            tail = new_node;
        }
        else{
            tail -> next = new_node;
            new_node -> prev = tail;
             tail = new_node;
        }
       
    }
    return head;
        
}


void displayF(struct node* head){
    struct node *temp = head;
    
    printf("Forward List: ");
    while(temp!= NULL){
        printf("%d -> ", temp->data);

        temp = temp->next;
    }
    printf("NULL\n");
    
}

void displayR(struct node *tail){
    struct node *temp = tail;
    
    while (temp -> next != NULL){
        temp = temp -> next;
    }
    
    printf("Reverse List: ");
    while(temp!= NULL){
        printf("%d -> ", temp->data);

        temp = temp-> prev;
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
        if (head != NULL){
            head -> prev = new_node;
        }
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
    new_node -> prev = temp;
    if (temp -> next != NULL){
        temp -> next -> prev = new_node;
    }
    temp -> next = new_node;
    
    
    return head;
        
}

struct node* delete(struct node* head, int position){
    if (position < 1 || head == NULL){
        printf("Error!\n");
        return;
    }
    struct node *temp = head;
    
    if (position == 1){
        head = head -> next;
        if (head != NULL){
            head -> prev = NULL;
        }
        free(temp);
        return head;
    }
    
    for (int i = 1; i < position; i++){
        if (temp == NULL){
            break;
        }
        temp = temp -> next;
    }
    if (temp == NULL){
        printf("Error!\n");
        return;
    }
    
    if (temp -> next != NULL){
        temp -> next -> prev = temp -> prev;
    } 
    
    if (temp -> prev != NULL){
        temp -> prev -> next = temp -> next;
    }
    
    
    
    free(temp);
    
    struct node* tail = head;
    if (tail != NULL){
        while (tail -> next != NULL){
            tail = tail -> next;
        }
    }
    
    return head;
    
}


int main(){
    struct node* head = createinitiallist();
    int n;
    int position;
    int data;
    int choice;

    printf("\nInitial List (Forward): \n");
    displayF(head);
    printf("\n");
    
    printf("Initial List (Reverse): \n");
    displayR(head);
    printf("\n");

    
    
    while (head){
        printf("\nMenu: \n");
        printf("1.Insert at a position\n2.Delete at a position\n3.Display Forward\n4.Display Reverse\n5.Exit\n");
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
            printf("Forward List: ");
            displayF(head);
        }
        
        else if (choice == 4){
            printf("Reverse List: ");
            displayR(head);
        }
        else if (choice == 5){
            printf("Exiting program.\n");
            exit(1);
        }
    } 
    
    printf("\n");

    struct node *temp;
    while (head != NULL){
        temp = head;
        head = head -> next -> prev;
        free(temp);
    }

    return 0;
}
