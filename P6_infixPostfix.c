#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 
// Stack type
struct Stack {
  int top;
  char items[MAX];
};

// Stack Operations
void push(struct Stack* s, char x) {
  s->items[++s->top] = x;
}

char pop(struct Stack* s) {
  return s->items[s->top--]; 
}

int precedence(char x) {
  if(x == '(')
    return 0;
  if(x == '+' || x == '-')
    return 1; 
  if(x == '*' || x == '/')
    return 2;
  return 0;
}

// Infix to Postfix conversion
void infixToPostfix(char* exp) {

  struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
  s->top = -1;

  char* postfix = (char*)malloc((strlen(exp) + 1) * sizeof(char));

  int i = 0; // Track infix traversal
  int j = 0; // Track postfix addition

  char temp; // Temporary character

  while(exp[i] != '\0') {
    // If operand, add to postfix
    if(exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z') {
      postfix[j++] = exp[i++]; 
    }
    // If opening brace, push to stack
    else if(exp[i] == '(') { 
      push(s, exp[i]);
      i++;
    }
    // If closing brace, pop from stack until matching opening brace
    else if(exp[i] == ')') {
      while((temp = pop(s)) != '(')
        postfix[j++] = temp;
      i++;
    }
    // If operator
    else {
      while(s->top != -1 && precedence(exp[i]) <= precedence(s->items[s->top]))
        postfix[j++] = pop(s);
      push(s, exp[i++]);
    } 
  }
  
  // Pop any remaining operators from stack
  while(s->top != -1) {
    postfix[j++] = pop(s);
  }

  postfix[j] = '\0'; // Null terminate postfix expression

  printf("Postfix: %s", postfix);

}

int main() {

  char* infix[100];
  printf("Enter the infix Expression: \n");
scanf("%s",&infix);
  infixToPostfix(infix);

  return 0;
}
