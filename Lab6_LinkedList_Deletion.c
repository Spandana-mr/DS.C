#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void createList(struct Node** head) {
    int data;
    char choice;
    do {
        printf("Enter data for the new node: ");
        scanf("%d", &data);

        struct Node* newNode = createNode(data);

        if (*head == NULL) {
            *head = newNode; 
        } else {
            struct Node* temp = *head;
            
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode; 
        }

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice); 
    } while (choice == 'y' || choice == 'Y');
}


void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty, cannot delete the first element.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next; 
    free(temp); 
    printf("First element deleted successfully.\n");
}


void deleteElement(struct Node** head, int data) {
    if (*head == NULL) {
        printf("The list is empty, cannot delete the element.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    
    if (temp != NULL && temp->data == data) {
        *head = temp->next; 
        free(temp);
        printf("Element %d deleted successfully.\n", data);
        return;
    }

    
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp == NULL) {
        printf("Element %d not found in the list.\n", data);
        return;
    }

    prev->next = temp->next; 
    free(temp); 
    printf("Element %d deleted successfully.\n", data);
}


void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty, cannot delete the last element.\n");
        return;
    }

    
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Last element deleted successfully.\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->next != NULL) {
        temp = temp->next;
    }

    
    free(temp->next);
    temp->next = NULL;
    printf("Last element deleted successfully.\n");
}

int main() {
    struct Node* head = NULL; 
    int choice, element;

    do {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("3. Delete First Element\n");
        printf("4. Delete Specified Element\n");
        printf("5. Delete Last Element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList(&head);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                deleteFirst(&head);
                break;
            case 4:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                deleteElement(&head, element);
                break;
            case 5:
                deleteLast(&head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
