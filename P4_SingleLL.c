#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node* head = NULL;

// Insert node at beginning 
void insert() {
  int new_data;
  printf("Enter element to insert: ");
  scanf("%d", &new_data);

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = head;
  head = new_node;
}

// Delete node by key
void delete() {
  int key;  
  printf("Enter element to delete: ");
  scanf("%d", &key);

  struct Node *temp = head, *prev;
  if (temp != NULL && temp->data == key) {
    head = temp->next;
    free(temp);
    return;
  }
  
  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }
  
  if (temp == NULL) return;
  prev->next = temp->next;

  free(temp);
}

// Search element by key
void search() {
  int key, index=0;
  printf("Enter element to search: ");
  scanf("%d", &key);

  struct Node* current = head;
  while (current != NULL) {
    if (current->data == key) {
      printf("Element found at index %d", index);  
      return;
    }
    current = current->next;
    index++; 
  }

  printf("Element not found");
}  

// Display linked list
void display() {
  struct Node* ptr;
  ptr = head;
  printf("Linked list Elements : ");
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}

int main() {
  // Menu based operations  
  int choice;
  while(1) {
    printf("\n1. Insert\n");
    printf("2. Delete\n"); 
    printf("3. Search\n");
    printf("4. Display\n"); 
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 5) 
      break;

    switch(choice) {
      case 1:
        insert();
        break;
      case 2: 
        delete();
        break;
      case 3:
        search();
        break;
      case 4:
        display();
        break;    
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}
