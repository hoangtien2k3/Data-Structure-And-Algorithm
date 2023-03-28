#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 10 // set cứng số hàng là 10
#define COL 10 // set cúng số cột là 10

// Structure to represent a point in the maze
struct Point {
    int x, y;
};

// Structure to represent a node in the stack
struct Node {
    struct Point pt;
    int dist;
};

// struct Stack sẽ tạo ra một đối tượng stack với 2 thuộc tính 
struct Stack {
    int top;    // giá trị truyền vào
    struct Node* array; // một mảng kiểu Node
};

// hàm này sẽ tạo ra Stack 
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); // cấp phát động stack 
    stack->top = -1;    // gán giá trị cho nó là -1
    stack->array = (struct Node*)malloc(size * sizeof(struct Node)); // cấp phát động một mảng array với size
    return stack;   // trả về một stack quản lý top và array
}

// hàm này kiểm tra xem Stack có rỗng hay không, nếu rổng nó sẽ trả về 1 (true) ngược là là 0 (false)
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// hàm này có chức năng đó là thêm phần tử vào đầu của danh sach Stack (vì stack tuân theo quy luật: Last In First Out (vào sau ra trước))
void push(struct Stack* stack, struct Node node) {
    stack->array[++stack->top] = node;
}

// hàm này thì xóa phần tử ở đầu danh sách (nghĩa là phần tử vào cuối cùng sẽ bị loại bỏ khỏi Stack)
struct Node pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// hàm này kiểm tra xem điểm đó đã hợp lệ trong ma trận hay chưa (nếu thỏa mãn tất cả các điều kiện thì trả về true)
int isValid(int **maze, int visited[][COL], int row, int col, struct Point pt) {
    return pt.x >= 0 && pt.x < row && pt.y >= 0 && pt.y < col && maze[pt.x][pt.y] == 0 && !visited[pt.x][pt.y];
}


// hàm này lại thực hiện: chức năng tìm đường đi ngắn nhất từ điểm bắt đầu vào ma trận cho đến điểm kết thúc của ma trận.
void findShortestPath(int row, int col, int **maze, struct Point start, struct Point end) {
    const int MAX_SIZE = ROW * COL;
    int visited[ROW][COL] = {0}; // tạo mảng và gán từng giá trị của mảng là 0
    struct Stack* stack = createStack(MAX_SIZE); // tạo ra một Stack với kích thuocs MAX_SIZE
    struct Node node = {start, 0}; // Khởi tạo nút bắt đầu
    push(stack, node); // đẩy Stack và node bắt đầu vào danh sách.

    while (!isEmpty(stack)) { // nếu stack khác rỗng
        struct Node curr = pop(stack); // xóa nút đầu khỏi stack
        struct Point pt = curr.pt;

        if (pt.x == end.x && pt.y == end.y) { // Nếu chúng đã đạt đến điểm cuối
            printf("Shortest path length is %d\n", curr.dist); // thì in ra cái điểm cuối đó
            return; // kết thức hàm (vì đây là void nên return không trả về giá trị)
        }

        visited[pt.x][pt.y] = 1; // Đánh dấu điểm hiện tại là đã truy cập

        // Kiểm tra tất cả bốn điểm liền kề của điểm hiện tại
        struct Point adj[] = {{pt.x-1, pt.y}, {pt.x+1, pt.y}, {pt.x, pt.y-1}, {pt.x, pt.y+1}};
        for (int i = 0; i < 4; i++) {
            if (isValid(maze, visited, ROW, COL, adj[i])) { // Nếu điểm liền kề là hợp lệ
                struct Node newNode = {adj[i], curr.dist + 1}; // Tạo một nút mới cho điểm liền kề
                push(stack, newNode); // Đẩy nút mới vào ngăn xếp
            }
        }
    }

    printf("No path found\n"); // Nếu không tìm thấy đường dẫn, in thông báo lỗi
}


int main() {
    // cho một mảng đầy vào.
    int defaultMaze[5][5] = {{3, 0, 0, 0, 0},
                             {0, 1, 1, 1, 0},
                             {0, 1, 2, 1, 0},
                             {0, 1, 0, 0, 0},
                             {0, 0, 0, 0, 0}
                            };


    int row = 5, col = 5; // set cứng số hàng rơ = 5 và số cột col = 5
    int **maze = (int**)malloc(row * sizeof(int*)); // cấp phát động một mảng (hay số hàng)
    for (int i = 0; i < row; i++) {
        maze[i] = (int*)malloc(col * sizeof(int)); // cấp phát cho từng phần tử của mảng (hay số cột)
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            maze[i][j] = defaultMaze[i][j]; // gán từng giá trị của mảng động cho mảng tĩnh
        }
    }
    struct Point start = {0, 3}, end = {3, 3}; // tạo độ của điểm bắt đầu và điểm kết thức (có thể thay đổi tọa độ đầu vào)
    
    
    // dùng để in ma trận vừa được thêm vào
    printf("A = { ");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("\t%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("    };\n\n");
    

    // Find shortest path
    findShortestPath(row, col, maze, start, end); // gọi hàm xuống giải quyết bài toán

    // để giải phóng bộ nhớ heap (vì cấp phát động trong vùng nhớ heap thì sẽ tốn rất nhiều dung lương bộ nhớ, nếu chúng ta không giải phóng chúng, thì vùng nhớ sẽ đầy)
    for (int i = 0; i < row; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0; // hàm trả về của hàm main
}


