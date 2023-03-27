#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

// Structure to represent a point in the maze
struct Point {
    int x, y;
};

// Structure to represent a node in the stack
struct Node {
    struct Point pt;
    int dist;
};

// Stack ADT
struct Stack {
    int top;
    struct Node* array;
};

// Function to create a new stack
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->array = (struct Node*)malloc(size * sizeof(struct Node));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push a node onto the stack
void push(struct Stack* stack, struct Node node) {
    stack->array[++stack->top] = node;
}

// Function to pop a node from the stack
struct Node pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// Function to check if a given point is a valid point in the maze
int isValid(int **maze, int visited[][COL], int row, int col, struct Point pt) {
    return pt.x >= 0 && pt.x < row && pt.y >= 0 && pt.y < col && maze[pt.x][pt.y] == 0 && !visited[pt.x][pt.y];
}


// Function to find the shortest path from the entrance to the exit of the maze
void findShortestPath(int row, int col, int **maze, struct Point start, struct Point end) {
    const int MAX_SIZE = ROW * COL;
    int visited[ROW][COL] = {0}; // Initialize visited array to 0
    struct Stack* stack = createStack(MAX_SIZE); // Create a new stack
    struct Node node = {start, 0}; // Initialize the starting node
    push(stack, node); // Push the starting node onto the stack

    while (!isEmpty(stack)) { // While the stack is not empty
        struct Node curr = pop(stack); // Pop the top node from the stack
        struct Point pt = curr.pt;

        if (pt.x == end.x && pt.y == end.y) { // If we have reached the end point
            printf("Shortest path length is %d\n", curr.dist); // Print the shortest path length
            return;
        }

        visited[pt.x][pt.y] = 1; // Mark the current point as visited

        // Check all four adjacent points of the current point
        struct Point adj[] = {{pt.x-1, pt.y}, {pt.x+1, pt.y}, {pt.x, pt.y-1}, {pt.x, pt.y+1}};
        for (int i = 0; i < 4; i++) {
            if (isValid(maze, visited, ROW, COL, adj[i])) { // If the adjacent point is valid
                struct Node newNode = {adj[i], curr.dist + 1}; // Create a new node for the adjacent point
                push(stack, newNode); // Push the new node onto the stack
            }
        }
    }

    printf("No path found\n"); // If no path is found, print an error message
}


int main() {
    int **maze;
    int row, col;

    // Read input values
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &row, &col);

    // Dynamically allocate memory for the maze
    maze = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        maze[i] = (int*)malloc(col * sizeof(int));
    }

    // Read maze input
    printf("Enter the maze:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    // Read starting and ending points
    struct Point start, end;
    printf("Enter the starting point (row column): ");
    scanf("%d %d", &start.x, &start.y);
    printf("Enter the ending point (row column): ");
    scanf("%d %d", &end.x, &end.y);

    // Find shortest path
    findShortestPath(row, col, maze, start, end);

    // Free dynamically allocated memory
    for (int i = 0; i < row; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}
