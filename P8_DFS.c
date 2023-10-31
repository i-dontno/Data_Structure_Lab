#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 100
struct Stack {
    int items[MAX_NODES];
    int top;
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}
int isFull(struct Stack* stack) {
    return stack->top == MAX_NODES - 1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int value) {
    if (isFull(stack))
        return;
    stack->items[++stack->top] = value;
}
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->items[stack->top--];
}
void DFS(int adjacencyMatrix[MAX_NODES][MAX_NODES], int source, int nodes) {
    struct Stack* stack = createStack();
    int visited[MAX_NODES] = {0};
    int i, current;
    printf("Depth First Search Traversal: ");
    visited[source] = 1;
    push(stack, source);
    printf("%d ", source);
    while (!isEmpty(stack)) {
        current = stack->items[stack->top];
        int flag = 0;
        for (i = 0; i < nodes; i++) {
            if (adjacencyMatrix[current][i] && !visited[i]) {
                visited[i] = 1;
                push(stack, i);
                printf("%d ", i);
                flag = 1;
                break;
            }
        }
        if (!flag)
            pop(stack);
    }
}
int main() {
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    int nodes, edges, source;
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }
    printf("Enter the source node for DFS traversal: ");
    scanf("%d", &source);
    DFS(adjacencyMatrix, source, nodes);
    return 0;
}
