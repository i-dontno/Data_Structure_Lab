#include <stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int rear = -1;
int front = -1;

void Insert(int x) {
  if(rear == MAX_SIZE-1) {
    printf("Queue Overflow\n");
    return;
  }
  if(front == -1) 
    front = 0;
  A[++rear] = x;
} 

void Delete() {
  if(front == -1 || front > rear) {
    printf("Queue Underflow\n");
    return ;
  }
  front++;
}

void Display() {
  if(front == -1) {
    printf("Queue is empty\n");
    return;
  }
  for(int i = front; i <= rear; i++) {
    printf("%d ", A[i]); 
  }
  printf("\n");
}

int main() {
  int choice, x;

  while(1) {
    
    printf("1. Insert element to queue \n");
    printf("2. Delete element from queue \n");
    printf("3. Display all elements of queue \n");
    printf("4. Quit \n");

    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter element to insert: ");
        scanf("%d", &x);
        Insert(x);
        break;
      case 2:
        Delete();
        break;
      case 3: 
        Display();
        break;
      case 4:
        return 0;
      default: 
        printf("Wrong choice \n");
    }
  }
}
