#include <stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE]; 
int top = -1;

void Push(int x) {
  if(top == MAX_SIZE-1) {
    printf("Error: Stack overflow\n"); 
    return;
  }
  A[++top] = x;   //initially top = -1 means there no element in the stack, so firstly increase the size then pushes the element to the stack
}

void Pop() {
  if(top == -1) {
    printf("Error: No elements to pop\n");
    return;
  }
  top--;  // if the size of the stack is greater than -1 then it decrease the size of top by 1 means it pops the element from the stack
}

void Display() {
  if(top == -1) {
    printf("Stack is empty\n");
    return;
  }
  for(int i=top; i>=0; i--) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main() {
  int choice, x;
  
  while(1) {
    printf("1. Push\n");
    printf("2. Pop\n"); 
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1: 
        printf("Enter element to push: ");
        scanf("%d", &x);
        Push(x);
        break;
      case 2: 
        Pop(); 
        break;
      case 3:
        Display();
        break;
      case 4: 
        return 0; 
      default: 
        printf("Invalid choice\n");
    }
  }
}
