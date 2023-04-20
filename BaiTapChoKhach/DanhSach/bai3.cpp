/**
 * @file bai2.cpp
 * @author hoangtien2k3 (hoangtien2k3qx1@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*  ! Đề bài:
    Queue & Stack: Path finding in the maze.

    Given a maze defined by a 2-dimensional matrix of size (m x n) of integers. In which the values of the elements
    have the following meanings:

    ‘The number 0 represents the Way/can be walked
    ‘The number 1 stands for Obstacle
    ‘The number 2 represents the Entrance.
    ‘The number 3 represents the Exit.

    For example:
    int A[][] = {
            {3, 0, 0, 0, 0},
            {0, 1, 1, 1, 0),
            {0, 1, 2, 1, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0}
        };

    1. Write a program to find the shortest path from a given point to the Exit using Stack ADT (2points)

    2. Write a program to find the shortest path from a given point to the Exit using Queue ADT (2points)
    Linked List & BST & AVL Tree: Finding a sub-string in a given string.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_MAZE_SIZE 100

int maze[][5] = {
	    {3, 0, 0, 0, 0},
	    {0, 1, 1, 1, 0},
	    {0, 1, 2, 1, 0},
	    {0, 1, 0, 0, 0},
	    {0, 0, 0, 0, 0}
	};
int m = 5, n = 5; // m là số hàng, n là số cố cột.

int visited[MAX_MAZE_SIZE][MAX_MAZE_SIZE]; // tạo ra một mảng visited với số hàng và số cột là MAX_MAZE_SIZE

struct Point {
    int x, y;
};

struct Queue {
    struct Point* items[MAX_MAZE_SIZE * MAX_MAZE_SIZE];
    int front, rear;
};

struct Stack {
    struct Point* items[MAX_MAZE_SIZE * MAX_MAZE_SIZE];
    int top;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

struct Stack* createStack() {
    struct Stack* s = (struct Stack*) malloc(sizeof(struct Stack));
    s->top = -1;
    return s;
}

void enqueue(struct Queue* q, struct Point* item) {
    if (q->rear == MAX_MAZE_SIZE * MAX_MAZE_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = item;
}

struct Point* dequeue(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return NULL;
    }
    struct Point* item = q->items[q->front];
    q->front++;
    return item;
}

void push(struct Stack* s, struct Point* item) {
    if (s->top == MAX_MAZE_SIZE * MAX_MAZE_SIZE - 1) {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->items[s->top] = item;
}

struct Point* pop(struct Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return NULL;
    }
    struct Point* item = s->items[s->top];
    s->top--;
    return item;
}

int isVisited(struct Point* p) {
    return visited[p->x][p->y] == 1;
}

void markVisited(struct Point* p) {
    visited[p->x][p->y] = 1;
}

int isWay(struct Point* p) {
    return maze[p->x][p->y] == 0 || maze[p->x][p->y] == 2 || maze[p->x][p->y] == 3;
}

int isExit(struct Point* p) {
    return maze[p->x][p->y] == 3;
}

struct Point* createPoint(int x, int y) {
    struct Point* p = (struct Point*) malloc(sizeof(struct Point));
    p->x = x;
    p->y = y;
    return p;
}

void printPath(struct Stack* s) {
    printf("Path found:\n");
    while (s->top >= 0) {
        struct Point* p = pop(s);
        printf("(%d, %d)\n", p->x, p->y);
        free(p);
    }
}

void findPath(int startX, int startY) {
    struct Queue* q = createQueue();
    struct Stack* s = createStack();

    struct Point* start = createPoint(startX, startY);
    markVisited(start);
    enqueue(q, start);
    while (q->front <= q->rear) {
	    struct Point* current = dequeue(q);
	    push(s, current);
	
	    if (isExit(current)) {
	        printPath(s);
	        free(q);
	        free(s);
	        return;
	    }
	
	    struct Point* up = createPoint(current->x - 1, current->y);
	    if (up->x >= 0 && !isVisited(up) && isWay(up)) {
	        markVisited(up);
	        enqueue(q, up);
	    }
	
	    struct Point* down = createPoint(current->x + 1, current->y);
	    if (down->x < m && !isVisited(down) && isWay(down)) {
	        markVisited(down);
	        enqueue(q, down);
	    }
	
	    struct Point* left = createPoint(current->x, current->y - 1);
	    if (left->y >= 0 && !isVisited(left) && isWay(left)) {
	        markVisited(left);
	        enqueue(q, left);
	    }
	
	    struct Point* right = createPoint(current->x, current->y + 1);
	    if (right->y < n && !isVisited(right) && isWay(right)) {
	        markVisited(right);
	        enqueue(q, right);
	    }
	}
	
	printf("No path found\n");
	free(q);
	free(s);
}

int main() {
	// Read maze from input


	// Find entrance and start searching for path
	int startX = -1, startY = -1;
	for (int i = 0; i < m; i++) {
	    for (int j = 0; j < n; j++) {
	        if (maze[i][j] == 2) {
	            startX = i;
	            startY = j;
	            break;
	        }
	    }
	    if (startX != -1) {
	        break;
	    }
	}

	if (startX == -1) {
	    printf("Entrance not found\n");
	    return 0;
	}
	
	findPath(startX, startY);
	
	return 0;
}
