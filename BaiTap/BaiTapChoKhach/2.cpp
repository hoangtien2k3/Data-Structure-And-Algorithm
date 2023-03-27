#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 50
#define MAX_COLS 50

typedef struct {
    int x;
    int y;
} Point;

typedef struct Node {
    Point data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

int maze[MAX_ROWS][MAX_COLS];
int rows, cols;

void init_queue(Queue *q) {
    q->front = q->rear = NULL;
}

bool is_queue_empty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, Point data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (is_queue_empty(q)) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

Point dequeue(Queue *q) {
    Point data = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL) {
        q->rear = NULL;
    }
    return data;
}

bool is_valid(Point p) {
    return p.x >= 0 && p.x < rows && p.y >= 0 && p.y < cols && maze[p.x][p.y] != 1;
}

int bfs(Point start, Point end, Queue* queue) {
    init_queue(queue);
    enqueue(queue, start);
    maze[start.x][start.y] = 1;
    int distance = 0;
    while (!is_queue_empty(queue)) {
    int size = 0;
    Node* current = queue->front;
    while (current != NULL) {
	    size++;
	    current = current->next;
	    }
	    for (int i = 0; i < size; i++) {
	        Point p = dequeue(queue);
	        if (p.x == end.x && p.y == end.y) {
	            maze[start.x][start.y] = 2;
	            return distance;
	        }
	        Point neighbors[] = {{p.x-1, p.y}, {p.x+1, p.y}, {p.x, p.y-1}, {p.x, p.y+1}};
	        for (int j = 0; j < 4; j++) {
	            Point n = neighbors[j];
	            if (is_valid(n)) {
	                enqueue(queue, n);
	                maze[n.x][n.y] = 1;
	            }
	        }
	    }
	    distance++;
	}
    maze[start.x][start.y] = 2;
    return -1;  // No path found
}

void print_maze() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of rows (maximum %d): ", MAX_ROWS);
    scanf("%d", &rows);
    printf("Enter number of columns (maximum %d): ", MAX_COLS);
    scanf("%d", &cols);
    printf("Enter maze data:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

	Queue q;
    Queue* queue = &q;

    // Find entrance and exit
    Point entrance = {-1, -1};
    Point exit = {-1, -1};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == 2) {
                entrance.x = i;
                entrance.y = j;
            } else if (maze[i][j] == 3) {
                exit.x = i;
                exit.y = j;
            }
        }
    }

    if (entrance.x == -1 || entrance.y == -1) {
        printf("Entrance not found\n");
        return 1;
    }
    if (exit.x == -1 || exit.y == -1) {
        printf("Exit not found\n");
        return 1;
    }

    printf("Maze:\n");
    print_maze();

    int shortest_path = bfs(entrance, exit, queue);
    if (shortest_path == -1) {
        printf("No path found\n");
    } else {
        printf("Shortest path: %d\n", shortest_path);
    }

    // Free the memory used by the queue
    Node *current_node = queue->front;
    while (current_node != NULL) {
        Node *next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    return 0;
}
