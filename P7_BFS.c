#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->rear == MAX_NODES - 1);
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1 || queue->front > queue->rear);
}

void enqueue(struct Queue* queue, int value) {
    if (isFull(queue))
        return;
    if (queue->front == -1)
        queue->front = 0;
    queue->items[++queue->rear] = value;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return queue->items[queue->front++];
}

void BFS(int adjacencyMatrix[MAX_NODES][MAX_NODES], int source, int nodes) {
    struct Queue* queue = createQueue();
    int visited[MAX_NODES] = {0};
    int i, current;

    visited[source] = 1;
    enqueue(queue, source);

    printf("Breadth First Search Traversal: ");

    while (!isEmpty(queue)) {
        current = dequeue(queue);
        printf("%d ", current);

        for (i = 0; i < nodes; i++) {
            if (adjacencyMatrix[current][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
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

    printf("Enter the source node for BFS traversal: ");
    scanf("%d", &source);

    BFS(adjacencyMatrix, source, nodes);

    return 0;
}
